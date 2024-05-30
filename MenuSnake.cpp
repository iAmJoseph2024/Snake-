#include "MenuSnake.h"
#include "JugarSnake.h"
#include <SFML/Window/Event.hpp>

// Constructor de la clase MainMenu
MainMenu::MainMenu(std::shared_ptr<Context>& context)
    : mContexto(context),
    mBotonPlaySeleccionado(true),
    mBotonPlayPresionado(false),
    mBotonSalirSeleccionado(false),
    mBotonSalirPresionado(false) {}

MainMenu::~MainMenu() {}

// Funcion para inicializar el menú principal
void MainMenu::Init()
{
    // Cargar la fuente principal
    mContexto->mAssets->AnadirFondo(MAIN_FONT, "Assets/Fonts/PressStart2P-Regular.ttf");

    // Configurar el título del juego
    mTituloJuego.setFont(mContexto->mAssets->GetFondo(MAIN_FONT));
    mTituloJuego.setString("Snake OOP");
    mTituloJuego.setOrigin(mTituloJuego.getLocalBounds().width / 2, mTituloJuego.getLocalBounds().height / 2);
    mTituloJuego.setPosition(mContexto->mVentana->getSize().x / 2, mContexto->mVentana->getSize().y / 2 - 150.f);

    // Configurar el botón de jugar
    mBotonJugar.setFont(mContexto->mAssets->GetFondo(MAIN_FONT));
    mBotonJugar.setString("Jugar");
    mBotonJugar.setOrigin(mBotonJugar.getLocalBounds().width / 2, mBotonJugar.getLocalBounds().height / 2);
    mBotonJugar.setPosition(mContexto->mVentana->getSize().x / 2, mContexto->mVentana->getSize().y / 2 - 25.f);
    mBotonJugar.setCharacterSize(20);

    // Configurar el botón de salir
    mBotonSalir.setFont(mContexto->mAssets->GetFondo(MAIN_FONT));
    mBotonSalir.setString("Salir");
    mBotonSalir.setOrigin(mBotonSalir.getLocalBounds().width / 2, mBotonSalir.getLocalBounds().height / 2);
    mBotonSalir.setPosition(mContexto->mVentana->getSize().x / 2, mContexto->mVentana->getSize().y / 2 + 25.f);
    mBotonSalir.setCharacterSize(20);
}

// Funcion para procesar la entrada del usuario
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

// Funcion para actualizar el estado del menú
void MainMenu::Actualizar(const sf::Time& deltaTime)
{
    // Cambiar el color del texto según el botón seleccionado
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

    // Realizar la acción correspondiente si un botón ha sido presionado
    if (mBotonPlayPresionado)
    {
        mContexto->mStates->Add(std::make_unique<GamePlay>(mContexto), true);
    }
    else if (mBotonSalirPresionado)
    {
        mContexto->mStates->PopAll();
    }
}

// Funcion para dibujar el menú
void MainMenu::Dibujar()
{
    mContexto->mVentana->clear(sf::Color::Green);
    mContexto->mVentana->draw(mTituloJuego);
    mContexto->mVentana->draw(mBotonJugar);
    mContexto->mVentana->draw(mBotonSalir);
    mContexto->mVentana->display();
}
