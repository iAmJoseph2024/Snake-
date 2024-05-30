#pragma once

#include <memory>
#include <SFML/Graphics/Text.hpp>
#include "State1.h"
#include "JuegoSnake.h"

// Clase que representa el estado del men� principal
class MainMenu : public Engine::State
{
private:
    // Contexto compartido del juego
    std::shared_ptr<Context> mContexto;

    // Elementos de texto para el t�tulo y los botones del men�
    sf::Text mTituloJuego;
    sf::Text mBotonJugar;
    sf::Text mBotonSalir;

    // Variables para gestionar la selecci�n y pulsaci�n de los botones
    bool mBotonPlaySeleccionado;
    bool mBotonPlayPresionado;

    bool mBotonSalirSeleccionado;
    bool mBotonSalirPresionado;

public:
    // Constructor y destructor
    MainMenu(std::shared_ptr<Context>& context);
    ~MainMenu();

    // Inicializar el estado
    void Init() override;

    // Procesar la entrada del usuario
    void ProcesarInput();

    // Actualizar el estado con el tiempo transcurrido
    void Actualizar(const sf::Time& deltaTime);

    // Dibujar los elementos en la pantalla
    void Dibujar();
};
