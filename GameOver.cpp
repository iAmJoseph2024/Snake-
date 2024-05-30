#include "GameOver.h"
#include "JugarSnake.h"  
#include <SFML/Window/Event.hpp>

// Constructor de GameOver que inicializa el contexto y los estados de los botones
GameOver::GameOver(std::shared_ptr<Context>& context)
    : mContexto(context),
    mBotonReiniciarSeleccionado(true),
    mBotonReiniciarPresionado(false),
    mBotonSalirSeleccionado(false),
    mBotonSalirPresionado(false) {}

// Destructor de GameOver
GameOver::~GameOver() {}

// Inicialización de elementos gráficos y de texto en la pantalla de Game Over
void GameOver::Init()
{
    // Título
    mTituloSnakeJuego.setFont(mContexto->mAssets->GetFondo(MAIN_FONT));
    mTituloSnakeJuego.setString("Perdiste, vete a Administracion");
    mTituloSnakeJuego.setOrigin(mTituloSnakeJuego.getLocalBounds().width / 2, mTituloSnakeJuego.getLocalBounds().height / 2);
    mTituloSnakeJuego.setPosition(mContexto->mVentana->getSize().x / 2, mContexto->mVentana->getSize().y / 2 - 150.f);

    // Botón de Reiniciar
    mBotonReiniciar.setFont(mContexto->mAssets->GetFondo(MAIN_FONT));
    mBotonReiniciar.setString("Reiniciar");
    mBotonReiniciar.setOrigin(mBotonReiniciar.getLocalBounds().width / 2, mBotonReiniciar.getLocalBounds().height / 2);
    mBotonReiniciar.setPosition(mContexto->mVentana->getSize().x / 2, mContexto->mVentana->getSize().y / 2 - 25.f);
    mBotonReiniciar.setCharacterSize(20);

    // Botón de Salir
    mBotonSalir.setFont(mContexto->mAssets->GetFondo(MAIN_FONT));
    mBotonSalir.setString("Salir");
    mBotonSalir.setOrigin(mBotonSalir.getLocalBounds().width / 2, mBotonSalir.getLocalBounds().height / 2);
    mBotonSalir.setPosition(mContexto->mVentana->getSize().x / 2, mContexto->mVentana->getSize().y / 2 + 25.f);
    mBotonSalir.setCharacterSize(20);
}

// Procesamiento de la entrada del usuario
void GameOver::ProcesarInput()
{
    sf::Event event;
    while (mContexto->mVentana->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            mContexto->mStates->PopAll();  // Salir del juego si se cierra la ventana
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::Up:
                if (!mBotonReiniciarSeleccionado)
                {
                    mBotonReiniciarSeleccionado = true;
                    mBotonSalirSeleccionado = false;
                }
                break;
            case sf::Keyboard::Down:
                if (!mBotonSalirSeleccionado)
                {
                    mBotonReiniciarSeleccionado = false;
                    mBotonSalirSeleccionado = true;
                }
                break;
            case sf::Keyboard::Return:
                mBotonReiniciarPresionado = false;
                mBotonSalirPresionado = false;

                if (mBotonReiniciarSeleccionado)
                {
                    mBotonReiniciarPresionado = true;
                }
                else
                {
                    mBotonSalirPresionado = true;
                }
                break;
            default:
                break;
            }
        }
    }
}

// Actualización lógica basada en el tiempo transcurrido
void GameOver::Actualizar(const sf::Time& deltaTime)
{
    // Cambiar el color del texto de los botones según estén seleccionados o presionados
    if (mBotonReiniciarSeleccionado)
    {
        mBotonReiniciar.setFillColor(sf::Color::Black);
        mBotonSalir.setFillColor(sf::Color::White);
    }
    else
    {
        mBotonSalir.setFillColor(sf::Color::Black);
        mBotonReiniciar.setFillColor(sf::Color::White);
    }

    // Realizar acciones según el botón presionado
    if (mBotonReiniciarPresionado)
    {
        mContexto->mStates->Add(std::make_unique<GamePlay>(mContexto), true);  // Iniciar el estado de juego si se presiona Reiniciar
    }
    else if (mBotonSalirPresionado)
    {
        mContexto->mStates->PopAll();  // Salir del juego si se presiona Salir
    }
}

// Dibujar elementos en la pantalla
void GameOver::Dibujar()
{
    mContexto->mVentana->clear(sf::Color::Green);  // Limpiar la pantalla con un color verde
    mContexto->mVentana->draw(mTituloSnakeJuego);  // Dibujar el título en la pantalla
    mContexto->mVentana->draw(mBotonReiniciar);  // Dibujar el botón de Reiniciar en la pantalla
    mContexto->mVentana->draw(mBotonSalir);  // Dibujar el botón de Salir en la pantalla
    mContexto->mVentana->display();  // Mostrar los elementos dibujados en la pantalla
}
