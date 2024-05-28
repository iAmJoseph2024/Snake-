#include "GameOver.h"
#include "JugarSnake.h"
#include <SFML/Window/Event.hpp>

GameOver::GameOver(std::shared_ptr<Context>& context) : mContexto(context), mBotonReiniciarSeleccionado(true), mBotonReiniciarPresionado(false), mBotonSalirSeleccionado(false), mBotonSalirPresionado(false) {}
GameOver::~GameOver() {}

void GameOver::Init()
{
    // Title
    mTituloSnakeJuego.setFont(mContexto->mAssets->GetFondo(MAIN_FONT));
    mTituloSnakeJuego.setString("Perdiste, vete a Administracion");
    mTituloSnakeJuego.setOrigin(mTituloSnakeJuego.getLocalBounds().width / 2, mTituloSnakeJuego.getLocalBounds().height / 2);
    mTituloSnakeJuego.setPosition(mContexto->mVentana->getSize().x / 2, mContexto->mVentana->getSize().y / 2 - 150.f);

    // Play Button
    mBotonReiniciar.setFont(mContexto->mAssets->GetFondo(MAIN_FONT));  
    mBotonReiniciar.setString("Reiniciar");
    mBotonReiniciar.setOrigin(mBotonReiniciar.getLocalBounds().width / 2, mBotonReiniciar.getLocalBounds().height / 2);
    mBotonReiniciar.setPosition(mContexto->mVentana->getSize().x / 2, mContexto->mVentana->getSize().y / 2 - 25.f);
    mBotonReiniciar.setCharacterSize(20);

    // Exit Button
    mBotonSalir.setFont(mContexto->mAssets->GetFondo(MAIN_FONT));
    mBotonSalir.setString("Salir"); 
    mBotonSalir.setOrigin(mBotonSalir.getLocalBounds().width / 2, mBotonSalir.getLocalBounds().height / 2);
    mBotonSalir.setPosition(mContexto->mVentana->getSize().x / 2, mContexto->mVentana->getSize().y / 2 + 25.f); 
    mBotonSalir.setCharacterSize(20); 
}

void GameOver::ProcesarInput()
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
            switch (event.key.code)
            {
            case sf::Keyboard::Up:
            {
                if (!mBotonReiniciarSeleccionado)
                {
                    mBotonReiniciarSeleccionado = true;
                    mBotonSalirSeleccionado = false;
                }
                break;
            }
            case sf::Keyboard::Down:
            {
                if (!mBotonSalirSeleccionado)
                {
                    mBotonReiniciarSeleccionado = false;
                    mBotonSalirSeleccionado = true;
                }
                break;
            }
            case sf::Keyboard::Return:
            {
                mBotonReiniciarPresionado = false;
                mBotonSalirPresionado = false;

                if (mBotonReiniciarSeleccionado)
                {
                    mBotonReiniciarPresionado = true;
                }
                else
                {
                    mBotonSalirPresionado = true;
                }

                break;
            }
            default:
            {
                break;
            }
            }
        }
    }
}

void GameOver::Actualizar(const sf::Time& deltaTime)
{
    if (mBotonReiniciarSeleccionado)
    {
        mBotonReiniciar.setFillColor(sf::Color::Black);
        mBotonSalir.setFillColor(sf::Color::White);
    }
    else
    {
        mBotonSalir.setFillColor(sf::Color::Black);
        mBotonReiniciar.setFillColor(sf::Color::White);
    }

    if (mBotonReiniciarPresionado)
    {
        mContexto->mStates->Add(std::make_unique<GamePlay>(mContexto), true);
    }
    else if (mBotonSalirPresionado)
    {
        mContexto->mStates->PopAll();
    }
}

void GameOver::Dibujar()
{
    mContexto->mVentana->clear(sf::Color::Green);
    mContexto->mVentana->draw(mTituloSnakeJuego);   
    mContexto->mVentana->draw(mBotonReiniciar);  
    mContexto->mVentana->draw(mBotonSalir);  
    mContexto->mVentana->display();
}