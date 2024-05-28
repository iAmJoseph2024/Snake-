#pragma once
#include <memory>
#include <SFML/Graphics/Text.hpp>
#include "State.h"
#include "JuegoSnake.h"

class GameOver : public Engine::State
{
private:
    std::shared_ptr<Context> mContexto;
    sf::Text mTituloSnakeJuego;
    sf::Text mBotonReiniciar;
    sf::Text mBotonSalir;

    bool mBotonReiniciarSeleccionado;
    bool mBotonReiniciarPresionado;
    bool mBotonSalirSeleccionado;
    bool mBotonSalirPresionado;

public:
    GameOver(std::shared_ptr<Context>& context);
    ~GameOver();

    void Init() override;
    void ProcesarInput();
    void Actualizar(const sf::Time& deltaTime);
    void Dibujar();
};