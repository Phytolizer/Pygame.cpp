#include "MySDL.hpp"

#include <SDL_error.h>
#include <sstream>

void mysdl::CheckCode(const int code)
{
    if (code != 0)
    {
        std::ostringstream message;
        message << "SDL Error: " << SDL_GetError();
        throw std::runtime_error{message.str()};
    }
}
