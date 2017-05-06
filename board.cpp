#include "board.h"

Board::Board(QRect rect)
{
    this->rect = rect;
    this->size = rect.size();
}

QRect Board::get_rect()
{
    return rect;
}

void Board::move_right()
{
    set_pos(10);
}

void Board::move_left()
{
    set_pos(-10);
}

void Board::set_pos(int dx)
{
    rect.setX(get_rect().x() + dx);
    rect.setWidth(rect.width() + dx);
}
