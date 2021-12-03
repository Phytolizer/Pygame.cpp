#pragma once
#include "SmartTexture.hpp"

class Sprite
{
    SmartTexture m_texture;
    SDL_Rect m_rect;

public:
    explicit Sprite(SmartTexture tex);
    const SmartTexture& getTexture() const;
    const SDL_Rect& getRect() const;
    void setTopLeft(int x, int y);
    void setMidBottom(int x, int y);
};
