#include "PausaSnake.h"
#include <SFML/Window/Event.hpp>

PauseGame::PauseGame(std::shared_ptr<Context>& context) : mContexto(context) {}
PauseGame::~PauseGame() {}

void PauseGame::Init()
{
    // Title
    mTituloPausa.setFont(mContexto->mAssets->GetFondo(MAIN_FONT));
    mTituloPausa.setString("Pausa");
    mTituloPausa.setOrigin(mTituloPausa.getLocalBounds().width / 2, mTituloPausa.getLocalBounds().height / 2);
    mTituloPausa.setPosition(mContexto->mVentana->getSize().x / 2, mContexto->mVentana->getSize().y / 2);
}

void PauseGame::ProcesarInput()
{
    sf::Event event;
    while (mContexto->mVentana->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            mContexto->mStates->PopAll(); 
        } else if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
                case sf::Keyboard::Escape:
                {
                    mContexto->mStates->PopCurrent(); 
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

void PauseGame::Actualizar(const sf::Time& deltaTime) {}

void PauseGame::Dibujar()
{
    mContexto->mVentana->draw(mTituloPausa); 
    mContexto->mVentana->display(); 
}