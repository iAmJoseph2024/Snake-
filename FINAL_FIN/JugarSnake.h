#pragma once

#include <memory>
#include <array>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include "JuegoSnake.h"
#include "State1.h"
#include "Snake1.h"

// Clase que representa el estado de "Juego en progreso"
class GamePlay : public Engine::State
{
private:
    // Contexto compartido del juego
    std::shared_ptr<Context> mContexto;

    // Sprites para los elementos gráficos del juego
    sf::Sprite mCesped;
    sf::Sprite mComida;
    std::array<sf::Sprite, 4> mParedes;

    // Objeto para la serpiente del juego
    Snake mSerpiente;

    // Texto para mostrar la puntuación
    sf::Text mPuntuacionTexto;
    int mPuntuacion;

    // Dirección de movimiento de la serpiente y tiempo transcurrido
    sf::Vector2f mDireccionSnake;
    sf::Time mTiempoPasado;

    // Indicador de si el juego está pausado
    bool mPausado;

public:
    // Constructor y destructor
    GamePlay(std::shared_ptr<Context>& context);
    ~GamePlay();

    // Inicializar el estado
    void Init() override;

    // Procesar la entrada del usuario
    void ProcesarInput();

    // Actualizar el estado con el tiempo transcurrido
    void Actualizar(const sf::Time& deltaTime);

    // Dibujar los elementos en la pantalla
    void Dibujar();

    // Métodos para pausar y reanudar el juego
    void Pausa();
    void Empezar();
};
