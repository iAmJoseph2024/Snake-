#pragma once

#include <memory>
#include <SFML/Graphics/Text.hpp>
#include "State1.h"
#include "JuegoSnake.h"

// Clase que representa el estado de "Game Over" en el juego
class GameOver : public Engine::State
{
private:
    // Contexto compartido del juego
    std::shared_ptr<Context> mContexto;

    // Elementos de texto para el título y los botones
    sf::Text mTituloSnakeJuego;
    sf::Text mBotonReiniciar;
    sf::Text mBotonSalir;

    // Variables para gestionar la selección y pulsación de los botones
    bool mBotonReiniciarSeleccionado;
    bool mBotonReiniciarPresionado;
    bool mBotonSalirSeleccionado;
    bool mBotonSalirPresionado;

public:
    // Constructor y destructor
    GameOver(std::shared_ptr<Context>& context);
    ~GameOver();

    // Inicializar el estado
    void Init() override;

    // Procesar la entrada del usuario
    void ProcesarInput();

    // Actualizar el estado con el tiempo transcurrido
    void Actualizar(const sf::Time& deltaTime);

    // Dibujar los elementos en la pantalla
    void Dibujar();
};
