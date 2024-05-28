#pragma once
#include <list>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

class Snake : public sf::Drawable
{
public:
    Snake();
    ~Snake();

    void Init(const sf::Texture& texture);
    void Mover(const sf::Vector2f& direction);
    bool IsOn(const sf::Sprite& other) const;
    void Crecer(const sf::Vector2f& direction);
    bool Chocar() const;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    std::list<sf::Sprite> mCuerpo;
    std::list<sf::Sprite>::iterator mCabeza;
    std::list<sf::Sprite>::iterator mCola;
};