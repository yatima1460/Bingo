

#include <SDL_rect.h>
#include "GUI/Widget.hpp"


void Widget::SetPosition(SDL_Point location)
{
    this->location = location;
}


SDL_Point Widget::GetPosition() const
{
    return this->location;
}
