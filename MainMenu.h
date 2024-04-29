#pragma once
#include <memory> // Incluimos la libreria para std::shared_ptr
#include <SFML/Graphics/Text.hpp> // Incluimos la libreria para sf::Text
#include "Game.h" // Incluimos la libreria creada por nosotros para la clase Game
#include "State.h" // Incluimos la librer�a creada por nosotros para la clase State

// Definimos una clase llamada MainMenu que hereda de la clase State del namespace Engine
class MainMenu : public Engine::State {
private:
    std::shared_ptr<Context> m_context; // Puntero compartido a un objeto de tipo Context
    sf::Text m_gameTitle; // Texto para el t�tulo del juego
    sf::Text m_playButton; // Texto para el bot�n de jugar
    sf::Text m_exitButton; // Texto para el bot�n de salir

    bool m_isPlayButtonSelected; // Variable que indica si el bot�n de jugar est� seleccionado
    bool m_isPlayButtonPressed; // Variable que indica si el bot�n de jugar est� presionado

    bool m_isExitButtonSelected; // Variable que indica si el bot�n de salir est� seleccionado
    bool m_isExitButtonPressed; // Variable que indica si el bot�n de salir est� presionado

public:
    // Constructor de la clase MainMenu que recibe un puntero compartido a un objeto de tipo Context
    MainMenu(std::shared_ptr<Context>& context);

    // Destructor de la clase MainMenu
    ~MainMenu();

    // Virtuals heredados de la clase State que deben ser implementados
    void Init() override; // Inicializa el estado
    void ProcessInput() override; // Procesa la entrada del usuario
    void Update(sf::Time deltaTime) override; // Actualiza el estado basado en el tiempo delta
    void Draw() override; // Dibuja el estado en pantalla
};
