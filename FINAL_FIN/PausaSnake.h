#pragma once

#include <memory>
#include <SFML/Graphics/Text.hpp>
#include "State1.h"
#include "JuegoSnake.h"

// Clase que representa el estado de pausa del juego
class PauseGame : public Engine::State
{
public:
    // Constructor y destructor
    PauseGame(std::shared_ptr<Context>& context);
    ~PauseGame();

    // Inicializar el estado
    void Init() override;

    // Procesar la entrada del usuario
    void ProcesarInput();

    // Actualizar el estado con el tiempo transcurrido
    void Actualizar(const sf::Time& deltaTime);

    // Dibujar los elementos en la pantalla
    void Dibujar();

private:
    // Contexto compartido del juego
    std::shared_ptr<Context> mContexto;

    // Texto para el título de pausa
    sf::Text mTituloPausa;
};
