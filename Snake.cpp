#include "Snake.h"

Snake::Snake() : mCuerpo(std::list<sf::Sprite>(4))
{
    mCabeza = --mCuerpo.end();
    mCola = mCuerpo.begin();
}

Snake::~Snake() {}

void Snake::Init(const sf::Texture& texture)
{
    float x = 16.f;
    for (auto& piece : mCuerpo)
    {
        piece.setTexture(texture);
        piece.setPosition({ x, 16.f });
        x += 16.f;
    }
}

void Snake::Mover(const sf::Vector2f& direction)
{
    mCola->setPosition(mCabeza->getPosition() + direction);
    mCabeza = mCola;
    ++mCola;

    if (mCola == mCuerpo.end())
    {
        mCola = mCuerpo.begin();
    }
}

bool Snake::IsOn(const sf::Sprite& other) const
{
    return other.getGlobalBounds().intersects(mCabeza->getGlobalBounds());
}

void Snake::Crecer(const sf::Vector2f& direction)
{
    sf::Sprite newPiece;
    newPiece.setTexture(*(mCuerpo.begin()->getTexture()));
    newPiece.setPosition(mCabeza->getPosition() + direction);

    mCabeza = mCuerpo.insert(++mCabeza, newPiece);
}

bool Snake::Chocar() const
{
    bool flag = false;

    for (auto piece = mCuerpo.begin(); piece != mCuerpo.end(); ++piece)
    {
        if (mCabeza != piece)
        {
            flag = IsOn(*piece);

            if (flag)
            {
                break;
            }
        }
    }

    return flag;
}

void Snake::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto& piece : mCuerpo)
    {
        target.draw(piece);
    }
}