#include "block.h"

bool Block::is_destroyed() const
{
   return destroyed;
}

QRect Block::get_rect() const
{
    return rect_;
}

QColor Block::get_color() const
{
    return color_;
}

void Block::destroy()
{
    destroyed = true;
}
