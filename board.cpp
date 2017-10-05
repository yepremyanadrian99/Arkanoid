#include "board.h"

QRect Board::get_rect() const
{
    return rect_;
}

QColor Board::get_color() const
{
    return color_;
}

void Board::move_right()
{
    set_pos(dx);
}

void Board::move_left()
{
    set_pos(-dx);
}

void Board::set_pos(int dx)
{
    rect_.setX(get_rect().x() + dx);
    rect_.setWidth(rect_.width() + dx);
}

