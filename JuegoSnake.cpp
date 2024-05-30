#include <SFML/Graphics/CircleShape.hpp>
#include "JuegoSnake.h"
#include "MenuSnake.h"

// Constructor de la clase Game
Game::Game() : mContexto(std::make_shared<Context>())
{
    // Crear una ventana con resolución 1080x720 y título "Snake Game"
    mContexto->mVentana->create(sf::VideoMode(1080, 720), "Snake Game", sf::Style::Close);
    // Agregar el menú principal como el estado inicial del juego
    mContexto->mStates->Add(std::make_unique<MainMenu>(mContexto));
}

// Destructor de la clase Game
Game::~Game() {}

// Método principal que ejecuta el ciclo del juego
void Game::Correr()
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    // Reloj para medir el tiempo transcurrido
    sf::Clock reloj;
    sf::Time timeSinceLastFrame = sf::Time::Zero;

    // Bucle principal del juego que corre mientras la ventana esté abierta
    while (mContexto->mVentana->isOpen())
    {
        // Actualizar el tiempo desde la última frame
        timeSinceLastFrame += reloj.restart();

        // Procesar el tiempo en incrementos del tiempo por frame definido
        while (timeSinceLastFrame > TiempoPorFrame)
        {
            timeSinceLastFrame -= TiempoPorFrame;

            // Procesar los cambios de estado
            mContexto->mStates->ProcessStateChange();

            // Si hay estados en el stack, procesar el estado actual
            if (!mContexto->mStates->Vacio())
            {
                mContexto->mStates->GetCurrent()->ProcesarInput();
                mContexto->mStates->GetCurrent()->Actualizar(TiempoPorFrame);
                mContexto->mStates->GetCurrent()->Dibujar();
            }
            else
            {
                // Si no hay estados en el stack, cerrar la ventana
                mContexto->mVentana->close();
            }
        }
    }
}
