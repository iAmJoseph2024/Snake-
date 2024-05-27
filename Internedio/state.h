#pragma once
#include <SFML/System/Time.hpp> // Incluimos la libreria para sf::Time

namespace Engine {
    // Definimos una clase llamada State en el namespace Engine
    class State {
    public:
        // Constructor por defecto y destructor virtual para la clase State
        State() {};
        virtual ~State() {};

        //Virtuals que deben ser implementados por las clases derivadas
        virtual void Init() = 0; // Inicializa el estado
        virtual void ProcessInput() = 0; // Procesa la entrada del usuario
        virtual void Update(sf::Time deltaTime) = 0; // Actualiza el estado basado en el tiempo delta
        virtual void Draw() = 0; // “Dibuja” el estado en pantalla

        virtual void Pause() {}; // Pausa el estado
        virtual void Start() {}; // Inicia el estado
    };
} 
