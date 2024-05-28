#pragma once
#include <memory>
#include <SFML/Graphics/Text.hpp>
#include "State.h"
#include "JuegoSnake.h"

class PauseGame : public Engine::State
{
public:
    PauseGame(std::shared_ptr<Context>& context);
    ~PauseGame();

    void Init() override;
    void ProcesarInput();
    void Actualizar(const sf::Time& deltaTime);
    void Dibujar();

private:
    std::shared_ptr<Context> mContexto;
    sf::Text mTituloPausa;
};