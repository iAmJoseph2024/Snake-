#include "MenuSnake.h"
#include "JugarSnake.h"
#include <SFML/Window/Event.hpp>

MainMenu::MainMenu(std::shared_ptr<Context>& context) : mContexto(context), mBotonPlaySeleccionado(true), mBotonPlayPresionado(false), mBotonSalirSeleccionado(false), mBotonSalirPresionado(false) {}
MainMenu::~MainMenu() {}

void MainMenu::Init()
{
    mContexto->mAssets->AnadirFondo(MAIN_FONT, "Assets/Fonts/PressStart2P-Regular.ttf");

    // Title
    mTituloJuego.setFont(mContexto->mAssets->GetFondo(MAIN_FONT));
    mTituloJuego.setString("Snake OOP");
    mTituloJuego.setOrigin(mTituloJuego.getLocalBounds().width / 2, mTituloJuego.getLocalBounds().height / 2);
    mTituloJuego.setPosition(mContexto->mVentana->getSize().x / 2, mContexto->mVentana->getSize().y / 2 - 150.f);

    // Play Button
    mBotonJugar.setFont(mContexto->mAssets->GetFondo(MAIN_FONT));
    mBotonJugar.setString("Jugar");
    mBotonJugar.setOrigin(mBotonJugar.getLocalBounds().width / 2, mBotonJugar.getLocalBounds().height / 2);
    mBotonJugar.setPosition(mContexto->mVentana->getSize().x / 2, mContexto->mVentana->getSize().y / 2 - 25.f); 
    mBotonJugar.setCharacterSize(20);

    // Exit Button
    mBotonSalir.setFont(mContexto->mAssets->GetFondo(MAIN_FONT));
    mBotonSalir.setString("Salir"); 
    mBotonSalir.setOrigin(mBotonSalir.getLocalBounds().width / 2, mBotonSalir.getLocalBounds().height / 2);
    mBotonSalir.setPosition(mContexto->mVentana->getSize().x / 2, mContexto->mVentana->getSize().y / 2 + 25.f); 
    mBotonSalir.setCharacterSize(20); 
}

void MainMenu::ProcesarInput()
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
            case sf::Keyboard::Up:
            {
                if (!mBotonPlaySeleccionado)
                {
                    mBotonPlaySeleccionado = true;
                    mBotonSalirSeleccionado = false;
                }
                break;
            }
            case sf::Keyboard::Down:
            {
                if (!mBotonSalirSeleccionado)
                {
                    mBotonPlaySeleccionado = false;
                    mBotonSalirSeleccionado = true;
                }
                break;
            }
            case sf::Keyboard::Return:
            {
                mBotonPlayPresionado = false;
                mBotonSalirPresionado = false;

                if (mBotonPlaySeleccionado)
                {
                    mBotonPlayPresionado = true;
                }
                else
                {
                    mBotonSalirPresionado = true;
                }

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

void MainMenu::Actualizar(const sf::Time& deltaTime)
{
    if (mBotonPlaySeleccionado)
    {
        mBotonJugar.setFillColor(sf::Color::Black);
        mBotonSalir.setFillColor(sf::Color::White);
    }
    else
    {
        mBotonSalir.setFillColor(sf::Color::Black);
        mBotonJugar.setFillColor(sf::Color::White);
    }

    if (mBotonPlayPresionado)
    {
        mContexto->mStates->Add(std::make_unique<GamePlay>(mContexto), true);
    }
    else if (mBotonSalirPresionado)
    {
        mContexto->mStates->PopAll(); 
    }
}

void MainMenu::Dibujar()
{
    mContexto->mVentana->clear(sf::Color::Green);
    mContexto->mVentana->draw(mTituloJuego);
    mContexto->mVentana->draw(mBotonJugar);
    mContexto->mVentana->draw(mBotonSalir);
    mContexto->mVentana->display();
}