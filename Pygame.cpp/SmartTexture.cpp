#include "SmartTexture.hpp"

#include "MySDL.hpp"

void SmartTexture::cleanup() const
{
    if (m_texture != nullptr)
    {
        SDL_DestroyTexture(m_texture);
    }
}

SmartTexture::SmartTexture(const SmartRenderer& renderer, const SmartSurface surf)
    : m_texture(mysdl::CheckPointer(SDL_CreateTextureFromSurface(renderer.get(), surf.get()))), m_width(surf.get()->w),
      m_height(surf.get()->h)
{
}

SmartTexture::SmartTexture(SmartTexture&& other) noexcept
    : m_texture(other.m_texture), m_width(other.m_width), m_height(other.m_height)
{
    other.m_texture = nullptr;
}

SmartTexture& SmartTexture::operator=(SmartTexture&& other) noexcept
{
    if (&other != this)
    {
        cleanup();
        m_texture = other.m_texture;
        m_width = other.m_width;
        m_height = other.m_height;
        other.m_texture = nullptr;
    }
    return *this;
}

SmartTexture::~SmartTexture()
{
    cleanup();
}

SDL_Texture* SmartTexture::get() const
{
    return m_texture;
}

int SmartTexture::width() const
{
    return m_width;
}

int SmartTexture::height() const
{
    return m_height;
}
