#include "Sprite.hpp"

#include <utility>

Sprite::Sprite(SmartTexture tex) : m_texture{std::move(tex)}, m_rect{0, 0, m_texture.width(), m_texture.height()}
{
}

const SmartTexture& Sprite::getTexture() const
{
    return m_texture;
}

const SDL_Rect& Sprite::getRect() const
{
    return m_rect;
}

void Sprite::setTopLeft(const int x, const int y)
{
    m_rect.x = x;
    m_rect.y = y;
}

void Sprite::setMidBottom(const int x, const int y)
{
    m_rect.x = x - m_rect.w / 2;
    m_rect.y = y - m_rect.h;
}
