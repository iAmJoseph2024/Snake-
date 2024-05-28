#include <SFML/Graphics/CircleShape.hpp>
#include "JuegoSnake.h"
#include "MenuSnake.h"

Game::Game() : mContexto(std::make_shared<Context>())
{
    mContexto->mVentana->create(sf::VideoMode(1080, 720), "Snake Game", sf::Style::Close);
    mContexto->mStates->Add(std::make_unique<MainMenu>(mContexto));
}

Game::~Game() {}

void Game::Correr()
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Clock reloj;
    sf::Time timeSinceLastFrame = sf::Time::Zero;

    while (mContexto->mVentana->isOpen())
    {
        timeSinceLastFrame += reloj.restart();

        while (timeSinceLastFrame > TiempoPorFrame)
        {
            timeSinceLastFrame -= TiempoPorFrame;

            mContexto->mStates->ProcessStateChange();

            if (!mContexto->mStates->Vacio())
            {
                mContexto->mStates->GetCurrent()->ProcesarInput(); 
                mContexto->mStates->GetCurrent()->Actualizar(TiempoPorFrame);
                mContexto->mStates->GetCurrent()->Dibujar();
            }
            else
            {
                mContexto->mVentana->close(); 
            }
        }
    }
}