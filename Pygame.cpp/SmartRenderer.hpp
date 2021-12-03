#pragma once

#include "SmartWindow.hpp"

#include <SDL.h>

class SmartTexture;
class Sprite;

class SmartRenderer
{
    SDL_Renderer* m_renderer;

    void cleanup() const;

  public:
    SmartRenderer(const SmartWindow& window, int index, Uint32 flags);
    ~SmartRenderer();
    SmartRenderer(const SmartRenderer&) = delete;
    SmartRenderer& operator=(const SmartRenderer&) = delete;
    SmartRenderer(SmartRenderer&& other) noexcept;
    SmartRenderer& operator=(SmartRenderer&& other) noexcept;

    SDL_Renderer* get() const;
    void setDrawBlendMode(SDL_BlendMode bm) const;
    void setDrawColor(SDL_Color color) const;
    void clear() const;
    void present() const;
    void copy(const SmartTexture& texture, const SDL_Rect* src, const SDL_Rect* dst) const;
    void copy(const Sprite& spr) const;
};
