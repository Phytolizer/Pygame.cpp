#pragma once

#include "SmartRenderer.hpp"
#include "SmartSurface.hpp"
#include <SDL.h>

class SmartTexture
{
    SDL_Texture* m_texture;
    int m_width;
    int m_height;

    void cleanup() const;

  public:
    SmartTexture(const SmartRenderer& renderer, SmartSurface surf);
    SmartTexture(const SmartTexture&) = delete;
    SmartTexture& operator=(const SmartTexture&) = delete;
    SmartTexture(SmartTexture&& other) noexcept;
    SmartTexture& operator=(SmartTexture&& other) noexcept;
    ~SmartTexture();

    SDL_Texture* get() const;
    int width() const;
    int height() const;
};
