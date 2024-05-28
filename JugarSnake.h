#pragma once
#include <memory>
#include <array>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include "JuegoSnake.h"
#include "State.h"
#include "Snake.h"

class GamePlay : public Engine::State
{
private:
    std::shared_ptr<Context> mContexto;
    sf::Sprite mCesped;
    sf::Sprite mComida;
    std::array<sf::Sprite, 4> mParedes;
    Snake mSerpiente;

    sf::Text mPuntuacionTexto;
    int mPuntuacion;

    sf::Vector2f mDireccionSnake;
    sf::Time mTiempoPasado;

    bool mPausado;

public:
    GamePlay(std::shared_ptr<Context>& context);
    ~GamePlay();

    void Init() override;
    void ProcesarInput();
    void Actualizar(const sf::Time& deltaTime);
    void Dibujar();
    void Pausa() ;
    void Empezar() ;
};