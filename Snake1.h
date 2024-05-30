#pragma once

#include <list>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

// Clase que representa la serpiente en el juego, derivada de sf::Drawable para ser renderizable
class Snake : public sf::Drawable
{
public:
    // Constructor y destructor
    Snake();
    ~Snake();

    // Inicializar la serpiente con una textura
    void Init(const sf::Texture& texture);

    // Mover la serpiente en una dirección específica
    void Mover(const sf::Vector2f& direction);

    // Comprobar si la serpiente está en una posición específica
    bool IsOn(const sf::Sprite& other) const;

    // Hacer crecer la serpiente en una dirección específica
    void Crecer(const sf::Vector2f& direction);

    // Comprobar si la serpiente ha chocado consigo misma
    bool Chocar() const;

    // Dibujar la serpiente en la parte renderizada
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    // Lista de sprites que conforman el cuerpo de la serpiente
    std::list<sf::Sprite> mCuerpo;

    // Iteradores para la cabeza y la cola de la serpiente
    std::list<sf::Sprite>::iterator mCabeza;
    std::list<sf::Sprite>::iterator mCola;
};
