#include "JugarSnake.h"
#include "GameOver.h"
#include "PausaSnake.h"
#include <SFML/Window/Event.hpp>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

GamePlay::GamePlay(std::shared_ptr<Context>& context) : mContexto(context), mPuntuacion(0), mDireccionSnake({ 16.f, 0.f }), mTiempoPasado(sf::Time::Zero), mPausado(false)
{
    srand(time(nullptr));
}

GamePlay::~GamePlay() {}

void GamePlay::Init()
{
    mContexto->mAssets->AnadirTextura(GRASS, "Assets/Textures/grass.png", true);
    mContexto->mAssets->AnadirTextura(FOOD, "Assets/Textures/food.png");
    mContexto->mAssets->AnadirTextura(WALL, "Assets/Textures/wall.png", true); 
    mContexto->mAssets->AnadirTextura(SNAKE, "Assets/Textures/snake.png"); 

    mCesped.setTexture(mContexto->mAssets->GetTextura(GRASS));
    mCesped.setTextureRect(mContexto->mVentana->getViewport(mContexto->mVentana->getDefaultView())); 

    for (auto& wall : mParedes)
    {
        wall.setTexture(mContexto->mAssets->GetTextura(WALL));
    }

    mParedes[0].setTextureRect({ 0, 0, (int)mContexto->mVentana->getSize().x, 16 });
    mParedes[1].setTextureRect({ 0, 0, (int)mContexto->mVentana->getSize().x, 16 });
    mParedes[1].setPosition(0, mContexto->mVentana->getSize().y - 16); 

    mParedes[2].setTextureRect({ 0, 0, 16, (int)mContexto->mVentana->getSize().y });
    mParedes[3].setTextureRect({ 0, 0, 16, (int)mContexto->mVentana->getSize().y });
    mParedes[3].setPosition(mContexto->mVentana->getSize().x - 16, 0);

    mComida.setTexture(mContexto->mAssets->GetTextura(FOOD));
    mComida.setPosition(mContexto->mVentana->getSize().x / 2, mContexto->mVentana->getSize().y / 2); 

    mSerpiente.Init(mContexto->mAssets->GetTextura(SNAKE)); 

    mPuntuacionTexto.setFont(mContexto->mAssets->GetFondo(MAIN_FONT)); 
    mPuntuacionTexto.setString("Puntuacion : " + std::to_string(mPuntuacion)); 
    mPuntuacionTexto.setCharacterSize(15); 
}

void GamePlay::ProcesarInput()
{
    sf::Event event;
    while (mContexto->mVentana->pollEvent(event)) 
    {
        if (event.type == sf::Event::Closed)
        {
            mContexto->mStates->PopAll(); 
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            sf::Vector2f newDirection = mDireccionSnake;
            switch (event.key.code)
            {
            case sf::Keyboard::Up:
                newDirection = { 0.f, -16.f };
                break;
            case sf::Keyboard::Down:
                newDirection = { 0.f, 16.f };
                break;
            case sf::Keyboard::Left:
                newDirection = { -16.f, 0.f };
                break;
            case sf::Keyboard::Right:
                newDirection = { 16.f, 0.f };
                break;
            case sf::Keyboard::Escape:
                mContexto->mStates->Add(std::make_unique<PauseGame>(mContexto));
                break;

            default:
                break;
            }

            if (std::abs(mDireccionSnake.x) != std::abs(newDirection.x) ||  std::abs(mDireccionSnake.y) != std::abs(newDirection.y))
            {
                mDireccionSnake = newDirection;
            }
        }
    }
}

void GamePlay::Actualizar(const sf::Time& deltaTime)
{
    if (!mPausado)
    {
        mTiempoPasado += deltaTime;

        if (mTiempoPasado.asSeconds() > 0.1)
        {
            for (auto& wall : mParedes)
            {
                if (mSerpiente.IsOn(wall)) 
                {
                    mContexto->mStates->Add(std::make_unique<GameOver>(mContexto), true); 
                    break;
                }
            }

            if (mSerpiente.IsOn(mComida))
            {
                mSerpiente.Crecer(mDireccionSnake);

                int x = 0, y = 0;
                x = (rand() % mContexto->mVentana->getSize().x, 16, mContexto->mVentana->getSize().x - 2 * 16);
                y = (rand() % mContexto->mVentana->getSize().y, 16, mContexto->mVentana->getSize().y - 2 * 16); 

                mComida.setPosition(x, y);
                mPuntuacion += 1;
                mPuntuacionTexto.setString("Puntuacion : " + std::to_string(mPuntuacion));
            }
            else
            {
                mSerpiente.Mover(mDireccionSnake);
            }

            if (mSerpiente.Chocar())
            {
                mContexto->mStates->Add(std::make_unique<GameOver>(mContexto), true);
            }

            mTiempoPasado = sf::Time::Zero;
        }
    }
}

void GamePlay::Dibujar() 
{
    mContexto->mVentana->clear();
    mContexto->mVentana->draw(mCesped);

    for (auto& wall : mParedes)
    {
        mContexto->mVentana->draw(wall);
    }
    mContexto->mVentana->draw(mComida);
    mContexto->mVentana->draw(mSerpiente);  
    mContexto->mVentana->draw(mPuntuacionTexto); 

    mContexto->mVentana->display(); 
}

void GamePlay::Pausa()
{
    mPausado = true;
}

void GamePlay::Empezar()
{
    mPausado = false;
}