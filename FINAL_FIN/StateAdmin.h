#pragma once

#include <stack>
#include <memory>
#include "State1.h"

namespace Engine
{
    // Clase que gestiona el manejo de estados del juego mediante una pila
    class StateMan
    {
    public:
        // Constructor y destructor
        StateMan();
        ~StateMan();

        // Añadir un nuevo estado al stack
        void Add(std::unique_ptr<State> toAdd, bool replace = false);

        // Eliminar el estado actual del stack
        void PopCurrent();

        // Eliminar todos los estados del stack
        void PopAll();

        // Procesar cambios en el estado (añadir, reemplazar o eliminar estados)
        void ProcessStateChange();

        // Obtener el estado actual en la cima del stack
        std::unique_ptr<State>& GetCurrent();

        // Verificar si el stack de estados está vacía
        bool Vacio() const;

    private:
        // Stack que almacena los estados del juego como punteros únicos
        std::stack<std::unique_ptr<State>> m_stateStack;

        // Nuevo estado que puede ser añadido, reemplazado o eliminado
        std::unique_ptr<State> m_newState;

        // Variables booleanas para controlar acciones sobre los estados
        bool m_add;  // Indica si se debe añadir un nuevo estado
        bool m_replace;  // Indica si se debe reemplazar el estado actual
        bool m_remove;  // Indica si se debe eliminar el estado actual
        bool m_removeAll;  // Indica si se deben eliminar todos los estados
    };

}
