#pragma once
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include "AssetAdmin.h"
#include "StateAdmin.h"

enum AssetID 
{
    MAIN_FONT = 0,
    GRASS,
    FOOD,
    WALL,
    SNAKE
};

struct Context
{
    std::unique_ptr<Engine::AssetMan> mAssets;
    std::unique_ptr<Engine::StateMan> mStates;
    std::unique_ptr<sf::RenderWindow> mVentana;

    Context()
    {
        mAssets = std::make_unique<Engine::AssetMan>();
        mStates = std::make_unique<Engine::StateMan>();
        mVentana = std::make_unique<sf::RenderWindow>();
    }
};

class Game
{
private:
    std::shared_ptr<Context> mContexto;
    const sf::Time TiempoPorFrame = sf::seconds(1.f / 60.f);

public:
    Game();
    ~Game();

    void Correr();
};