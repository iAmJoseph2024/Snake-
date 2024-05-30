#pragma once

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include "AssetAdmin.h"
#include "StateAdmin.h"

// Enumeración para identificar los diferentes tipos de activos del juego
enum AssetID
{
    MAIN_FONT = 0,
    GRASS,
    FOOD,
    WALL,
    SNAKE
};

// Estructura que contiene el contexto del juego, incluyendo administradores de activos y estados, y la ventana de renderizado
struct Context
{
    std::unique_ptr<Engine::AssetMan> mAssets;
    std::unique_ptr<Engine::StateMan> mStates;
    std::unique_ptr<sf::RenderWindow> mVentana;

    // Constructor que inicializa los punteros únicos
    Context()
    {
        mAssets = std::make_unique<Engine::AssetMan>();
        mStates = std::make_unique<Engine::StateMan>();
        mVentana = std::make_unique<sf::RenderWindow>();
    }
};

// Clase principal del juego
class Game
{
private:
    // Contexto compartido del juego
    std::shared_ptr<Context> mContexto;

    // Tiempo por frame para mantener una tasa de actualización constante
    const sf::Time TiempoPorFrame = sf::seconds(1.f / 60.f);

public:
    // Constructor y destructor
    Game();
    ~Game();

    // Funcion para iniciar el juego
    void Correr();
};
