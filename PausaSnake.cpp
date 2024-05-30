#include "PausaSnake.h"
#include <SFML/Window/Event.hpp>

// Constructor de la clase PauseGame
PauseGame::PauseGame(std::shared_ptr<Context>& context) : mContexto(context) {}
PauseGame::~PauseGame() {}

// Funcion para inicializar el estado de pausa
void PauseGame::Init()
{
    // Configurar el título de pausa
    mTituloPausa.setFont(mContexto->mAssets->GetFondo(MAIN_FONT));
    mTituloPausa.setString("Pausa");
    mTituloPausa.setOrigin(mTituloPausa.getLocalBounds().width / 2, mTituloPausa.getLocalBounds().height / 2);
    mTituloPausa.setPosition(mContexto->mVentana->getSize().x / 2, mContexto->mVentana->getSize().y / 2);
}

// Funcion para procesar la entrada del usuario
void PauseGame::ProcesarInput()
{
    sf::Event event;
    while (mContexto->mVentana->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            mContexto->mStates->PopAll();
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::Escape:
            {
                mContexto->mStates->PopCurrent(); // Sale del estado de pausa al presionar Escape
                break;
            }
            default:
            {
                break;
            }
            }
        }
    }
}

// Funcion para actualizar el estado de pausa (no hace nada en este caso)
void PauseGame::Actualizar(const sf::Time& deltaTime) {}

// Funcion para dibujar la pantalla de pausa
void PauseGame::Dibujar()
{
    mContexto->mVentana->draw(mTituloPausa); // Dibuja el texto de pausa
    mContexto->mVentana->display(); // Muestra el contenido en la ventana
}
