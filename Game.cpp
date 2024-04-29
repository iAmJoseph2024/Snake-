#include "Game.h"
#include <SFML/Window/Event.hpp> // Incluimos la libreria para sf::Event
#include <SFML/Graphics/CircleShape.hpp> // Incluimos la libreria para sf::CircleShape
#include "MainMenu.h" // Incluimos la librería creada por nosotros para la clase MainMenu

// Constructor de la clase Game
Game::Game() : m_context(std::make_shared<Context>()) {
    // Creamos una ventana utilizando sf::RenderWindow
    m_context->m_window->create(sf::VideoMode(1080, 720), "SNAKE GAME", sf::Style::Close);
    // Agregamos el estado MainMenu al StateMan
    m_context->m_states->Add(std::make_unique<MainMenu>(m_context));
}

// Destructor de la clase Game
Game::~Game() {}

// Método para iniciar la ejecución del juego
void Game::Run() {

    // Creamos un temporizador utilizando sf::Clock
    sf::Clock clock;
    sf::Time timeSinceLastFrame = sf::Time::Zero;

    // Bucle principal del juego
    while (m_context->m_window->isOpen()) {
        // Actualizamos el tiempo transcurrido desde el último fotograma
        timeSinceLastFrame += clock.restart();

        // Procesamos los eventos y actualizamos el juego en función del tiempo transcurrido
        while (timeSinceLastFrame > TIME_PER_FRAME) {
            timeSinceLastFrame -= TIME_PER_FRAME;

            // Procesamos los cambios de estado pendientes
            m_context->m_states->ProcessStateChange();
            // Procesamos la entrada del usuario en el estado actual
            m_context->m_states->GetCurrent()->ProcessInput();
            // Actualizamos el estado actual del juego
            m_context->m_states->GetCurrent()->Update(TIME_PER_FRAME);
            // Dibujamos el estado actual del juego en pantalla
            m_context->m_states->GetCurrent()->Draw();
        }
    }
}
