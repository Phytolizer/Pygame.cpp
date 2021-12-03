#include "GraphicsContext.hpp"

#include "MySDL.hpp"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

GraphicsContext::GraphicsContext()
{
    mysdl::CheckCode(SDL_Init(SDL_INIT_VIDEO));
    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
    {
        std::ostringstream ss;
        ss << "IMG_Init failed: " << IMG_GetError();
        throw std::runtime_error(ss.str());
    }
    mysdl::CheckCode(TTF_Init());
}

GraphicsContext::~GraphicsContext()
{
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
