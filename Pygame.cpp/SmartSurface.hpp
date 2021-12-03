#pragma once

#include <SDL.h>

class SmartSurface
{
    SDL_Surface* m_surface;
    void cleanup() const;

  public:
    explicit SmartSurface(SDL_Surface* surf);
    SmartSurface(const SmartSurface&) = delete;
    SmartSurface& operator=(const SmartSurface&) = delete;
    SmartSurface(SmartSurface&& other) noexcept;
    SmartSurface& operator=(SmartSurface&& other) noexcept;
    ~SmartSurface();

    SDL_Surface* get() const;
};
