#include "AssetAdmin.h"

Engine::AssetMan::AssetMan() {}
Engine::AssetMan::~AssetMan() {}

void Engine::AssetMan::AnadirTextura(int id, const std::string& filePath, bool wantRepeated)
{
    auto texture = std::make_unique<sf::Texture>();

    if (texture->loadFromFile(filePath))
    {
        texture->setRepeated(wantRepeated);
        mTexturas[id] = std::move(texture);
    }
}

void Engine::AssetMan::AnadirFondo(int id, const std::string& filePath)
{
    auto font = std::make_unique<sf::Font>();

    if (font->loadFromFile(filePath))
    {
        mFondos[id] = std::move(font);
    }
}

const sf::Texture& Engine::AssetMan::GetTextura(int id) const
{
    return *(mTexturas.at(id).get());
}

const sf::Font& Engine::AssetMan::GetFondo(int id) const
{
    return *(mFondos.at(id).get());
}