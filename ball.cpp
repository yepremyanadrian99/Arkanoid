#include "ball.h"

Ball::Ball(int x, int y, int size)
{
    this->x = x;
    this->y = y;
    this->b_rect = QRect(QPoint(x,y), QSize(size, size));
}
