#pragma once

#include <SFML/System/Time.hpp>

namespace Engine
{
    // Clase base abstracta que define la interfaz para los estados del juego
    class State
    {
    public:
        // Constructor y destructor virtuales
        State() {};
        virtual ~State() {};

        // Funciones virtuales puros que deben ser implementados por las clases derivadas
        virtual void Init() = 0;  // Inicializar el estado
        virtual void ProcesarInput() = 0;  // Procesar la entrada del usuario
        virtual void Actualizar(const sf::Time& deltaTime) = 0;  // Actualizar el estado con el tiempo transcurrido
        virtual void Dibujar() = 0;  // Dibujar los elementos en la pantalla

        // Funciones virtuales opcionales que pueden ser implementados por las clases derivadas
        virtual void Pausa() {};  // Manejar la pausa del estado
        virtual void Empezar() {};  // Manejar el reinicio del estado
    };
}
