#pragma once
#include <SFML/System/Time.hpp>

namespace Engine
{
    class State
    {
    public:
        State() {};
        virtual ~State() {};

        virtual void Init() = 0;
        virtual void ProcesarInput() = 0;
        virtual void Actualizar(const sf::Time& deltaTime) = 0;
        virtual void Dibujar() = 0;

        virtual void Pausa() {};
        virtual void Empezar() {};
    };
}