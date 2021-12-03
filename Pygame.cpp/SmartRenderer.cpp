#include "SmartRenderer.hpp"

#include "MySDL.hpp"
#include "SmartTexture.hpp"
#include "Sprite.hpp"

void SmartRenderer::cleanup() const
{
    if (m_renderer != nullptr)
    {
        SDL_DestroyRenderer(m_renderer);
    }
}

SmartRenderer::SmartRenderer(const SmartWindow& window, const int index, const Uint32 flags)
    : m_renderer(mysdl::CheckPointer(SDL_CreateRenderer(window.get(), index, flags)))
{
}

SmartRenderer::~SmartRenderer()
{
    cleanup();
}

SmartRenderer::SmartRenderer(SmartRenderer&& other) noexcept : m_renderer(other.m_renderer)
{
    other.m_renderer = nullptr;
}

SmartRenderer& SmartRenderer::operator=(SmartRenderer&& other) noexcept
{
    if (&other != this)
    {
        cleanup();
        m_renderer = other.m_renderer;
        other.m_renderer = nullptr;
    }
    return *this;
}

SDL_Renderer* SmartRenderer::get() const
{
    return m_renderer;
}

void SmartRenderer::setDrawBlendMode(const SDL_BlendMode bm) const
{
    mysdl::CheckCode(SDL_SetRenderDrawBlendMode(m_renderer, bm));
}

void SmartRenderer::setDrawColor(const SDL_Color color) const
{
    mysdl::CheckCode(SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a));
}

void SmartRenderer::clear() const
{
    mysdl::CheckCode(SDL_RenderClear(m_renderer));
}

void SmartRenderer::present() const
{
    SDL_RenderPresent(m_renderer);
}

void SmartRenderer::copy(const SmartTexture& texture, const SDL_Rect* src, const SDL_Rect* dst) const
{
    mysdl::CheckCode(SDL_RenderCopy(m_renderer, texture.get(), src, dst));
}

void SmartRenderer::copy(const Sprite& spr) const
{
    copy(spr.getTexture(), nullptr, &spr.getRect());
}
