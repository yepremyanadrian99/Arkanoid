#ifndef BALL_H
#define BALL_H
#include <iostream>
#include <QRect>
#include <QPoint>
#include <QSize>

class Ball
{
public:
  Ball(int x, int y)
    :x(x),y(y)
  {}

  Ball(int x, int y, int size);

public:
    int get_x();
    int get_y();
    QRect get_rect();

private:
    int x, y;
    QRect b_rect;
    int dx, dy;
};

#endif // BALL_H
