#include "ball.h"

Ball::Ball(QRect rect, QColor color)
{
    dx_ = 1;
    dy_ = -1;
    rect_ = rect;
    color_ = color;
}

QRect Ball::get_rect() const
{
    return rect_;
}

QRect& Ball::get_rect()
{
    return rect_;
}

QColor Ball::get_color() const
{
    return color_;
}

int Ball::get_dx() const
{
    return dx_;
}

int Ball::get_dy() const
{
    return dy_;
}

int& Ball::get_dx()
{
    return dx_;
}

int& Ball::get_dy()
{
    return dy_;
}

void Ball::start()
{
    started = true;
}

bool Ball::is_started()
{
    return started;
}
