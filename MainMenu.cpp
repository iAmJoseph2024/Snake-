#include "MainMenu.h"
#include <SFML/Window/Event.hpp> // Incluimos la libreria para sf::Event

// Constructor de la clase MainMenu que inicializa el contexto y las variables de botones
MainMenu::MainMenu(std::shared_ptr<Context>& context) : m_context(context),
m_isPlayButtonSelected(true), m_isPlayButtonPressed(false), m_isExitButtonSelected(false), m_isExitButtonPressed(false)
{

}

// Destructor de la clase MainMenu
MainMenu::~MainMenu() {

}

// M�todo para inicializar los elementos de la interfaz de usuario
void MainMenu::Init() {

	// T�tulo
	m_context->m_assets->AddFont(MAIN_FONT, "assets/Jersey15-Regular.ttf");
	m_gameTitle.setFont(m_context->m_assets->GetFont(MAIN_FONT));
	m_gameTitle.setString("Snake Game");
	m_gameTitle.setOrigin(m_gameTitle.getLocalBounds().width / 2,
		m_gameTitle.getLocalBounds().height / 2);
	m_gameTitle.setPosition(m_context->m_window->getSize().x / 2.7,
		m_context->m_window->getSize().y / 2.8 - 250.f);
	m_gameTitle.setCharacterSize(100);

	// Bot�n de play
	m_playButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
	m_playButton.setString("Play");
	m_playButton.setOrigin(m_playButton.getLocalBounds().width / 2,
		m_playButton.getLocalBounds().height / 2);
	m_playButton.setPosition(m_context->m_window->getSize().x / 2,
		m_context->m_window->getSize().y / 2 - 90.f);
	m_playButton.setCharacterSize(50);

	// Bot�n de exit
	m_exitButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
	m_exitButton.setString("Exit");
	m_exitButton.setOrigin(m_exitButton.getLocalBounds().width / 2,
		m_exitButton.getLocalBounds().height / 2);
	m_exitButton.setPosition(m_context->m_window->getSize().x / 2,
		m_context->m_window->getSize().y / 2 + 70.f);
	m_exitButton.setCharacterSize(50);
}

// M�todo para procesar la entrada del usuario
void MainMenu::ProcessInput() {
	sf::Event event;
	while (m_context->m_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed) {
			m_context->m_window->close();
		}
		else if (event.type == sf::Event::KeyPressed) {
			switch (event.key.code) {
			case sf::Keyboard::Up: {
				if (!m_isPlayButtonSelected) {
					m_isPlayButtonSelected = true;
					m_isExitButtonSelected = false;
				}
				break;
			}
			case sf::Keyboard::Down: {
				if (!m_isExitButtonSelected) {
					m_isPlayButtonSelected = false;
					m_isExitButtonSelected = true;
				}
				break;
			}
			case sf::Keyboard::Return: {
				m_isPlayButtonPressed = false;
				m_isExitButtonPressed = false;

				if (m_isPlayButtonSelected) {
					m_isPlayButtonPressed = true;
				}
				else {
					m_isExitButtonPressed = true;
				}
				break;
			}
			default: {
				break;
			}
			}
		}
	}
}

// M�todo para actualizar el estado del men� principal
void MainMenu::Update(sf::Time deltaTime) {
	if (m_isPlayButtonSelected) {
		m_playButton.setFillColor(sf::Color::Yellow);
		m_exitButton.setFillColor(sf::Color::White);
	}
	else {
		m_exitButton.setFillColor(sf::Color::Yellow);
		m_playButton.setFillColor(sf::Color::White);
	}

	if (m_isPlayButtonPressed) {
		// Aqu� se podr�a iniciar el juego
	}
	else if (m_isExitButtonPressed) {
		m_context->m_window->close(); // Cerramos la ventana
	}
}

// M�todo para dibujar los elementos del men� principal en la pantalla
void MainMenu::Draw() {
	m_context->m_window->clear(sf::Color::Green); // Le asignamos un color al fondo de la pantalla
	m_context->m_window->draw(m_gameTitle); // Dibujamos el t�tulo del juego
	m_context->m_window->draw(m_playButton); // Dibujamos el bot�n de play
	m_context->m_window->draw(m_exitButton); // Dibujamos el bot�n de exit
	m_context->m_window->display(); // Mostramos la pantalla
}
