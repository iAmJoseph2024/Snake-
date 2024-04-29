#pragma once
#include <stack> // Incluimos la libreria para std::stack
#include <memory> // Incluimos la libreria para std::unique_ptr

#include "state.h" // Incluimos la libreria echa por nosotros para la clase State

namespace Engine {
    // Definimos una clase llamada StateMan en el namespace Engine
    class StateMan {
    private:
        std::stack<std::unique_ptr<State>> m_stateStack; // Pila de punteros únicos a objetos de tipo State
        std::unique_ptr<State> m_newState; // Puntero único al nuevo estado a ser agregado

        bool m_add; // Variable para indicar si se va a agregar un nuevo estado
        bool m_replace; // Variable para indicar si se va a reemplazar el estado actual
        bool m_remove; // Variable para indicar si se va a eliminar el estado actual

    public:
        // Constructor por defecto y destructor de la clase StateMan
        StateMan();
        ~StateMan();

        // Métodos públicos de la clase StateMan

        // Agrega un nuevo estado a la pila de estados
        void Add(std::unique_ptr<State> toAdd, bool replace = false);

        // Elimina el estado actual de la pila de estados
        void PopCurrent();

        // Procesa los cambios de estado pendientes
        void ProcessStateChange();

        // Obtiene una referencia al estado actual
        std::unique_ptr<State>& GetCurrent();
    };
}
