#include "SmartSurface.hpp"

#include "MySDL.hpp"

void SmartSurface::cleanup() const
{
    if (m_surface != nullptr)
    {
        SDL_FreeSurface(m_surface);
    }
}

SmartSurface::SmartSurface(SDL_Surface* surf) : m_surface(mysdl::CheckPointer(surf))
{
}

SmartSurface::SmartSurface(SmartSurface&& other) noexcept : m_surface(other.m_surface)
{
    other.m_surface = nullptr;
}

SmartSurface& SmartSurface::operator=(SmartSurface&& other) noexcept
{
    if (&other != this)
    {
        cleanup();
        m_surface = other.m_surface;
        other.m_surface = nullptr;
    }

    return *this;
}

SmartSurface::~SmartSurface()
{
    cleanup();
}

SDL_Surface* SmartSurface::get() const
{
    return m_surface;
}
