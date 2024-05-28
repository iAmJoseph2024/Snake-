#pragma once
#include <memory>
#include <SFML/Graphics/Text.hpp>
#include "State.h"
#include "JuegoSnake.h"

class MainMenu : public Engine::State
{
private:
    std::shared_ptr<Context> mContexto;
    sf::Text mTituloJuego;
    sf::Text mBotonJugar;
    sf::Text mBotonSalir;

    bool mBotonPlaySeleccionado;
    bool mBotonPlayPresionado;

    bool mBotonSalirSeleccionado;
    bool mBotonSalirPresionado;

public:
    MainMenu(std::shared_ptr<Context>& context);
    ~MainMenu();

    void Init() override;
    void ProcesarInput();
    void Actualizar(const sf::Time& deltaTime);
    void Dibujar(); 
};
