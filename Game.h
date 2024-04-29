#pragma once

#include <memory> // Incluimos la libreria para std::unique_ptr
#include <SFML/Graphics/RenderWindow.hpp> // Incluimos la libreria para sf::RenderWindow
#include "AssetMan.h" // Incluimos la libreria echa por nosotros para la clase AssetMan
#include "StateMan.h" // Incluimos la libreria echa por nosotros para la clase StateMan

// Definimos un enum para identificar los diferentes assets
enum AssetID {
    MAIN_FONT = 0
};

// Definimos una estructura llamada Context para almacenar los objetos necesarios para el juego
struct Context {
    std::unique_ptr<Engine::AssetMan> m_assets; // Puntero único a un objeto de tipo AssetMan
    std::unique_ptr<Engine::StateMan> m_states; // Puntero único a un objeto de tipo StateMan
    std::unique_ptr<sf::RenderWindow> m_window; // Puntero único a un objeto de tipo sf::RenderWindow

    // Constructor de la estructura Context
    Context() {
        m_assets = std::make_unique<Engine::AssetMan>(); // Inicializamos m_assets con un nuevo objeto de tipo AssetMan
        m_states = std::make_unique<Engine::StateMan>(); // Inicializamos m_states con un nuevo objeto de tipo StateMan
        m_window = std::make_unique<sf::RenderWindow>(); // Inicializamos m_window con un nuevo objeto de tipo sf::RenderWindow
    }
};

// Definimos una clase llamada Game
class Game {
private:
    std::shared_ptr<Context> m_context; // Puntero compartido a un objeto de tipo Context
    const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f); // Constante que define el tiempo por fotograma

public:
    // Constructor y destructor de la clase Game
    Game();
    ~Game();

    // Método que inicia la ejecución del juego
    void Run();
};
