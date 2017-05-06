#include "ball.h"

Ball::Ball(int x, int y, int size)
{
    this->x = x;
    this->y = y;
    this->b_rect = QRect(QPoint(x,y), QSize(size, size));
}

int Ball::get_x()
{
    return x;
}

int Ball::get_y()
{
    return y;
}

QRect Ball::get_rect()
{
    return b_rect;
}
