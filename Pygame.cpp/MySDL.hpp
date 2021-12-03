#pragma once

#include <SDL_error.h>
#include <sstream>

namespace mysdl
{

void CheckCode(int code);
template <typename T> T* CheckPointer(T* pointer);

} // namespace mysdl

template <typename T> T* mysdl::CheckPointer(T* pointer)
{
    if (pointer == nullptr)
    {
        std::ostringstream message;
        message << "SDL Error: " << SDL_GetError();
        throw std::runtime_error{message.str()};
    }
    return pointer;
}
