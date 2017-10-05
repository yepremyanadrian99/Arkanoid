#ifndef BALL_H
#define BALL_H
#include <QRect>
#include <QPoint>
#include <QSize>
#include <QColor>

class Ball
{

public:
  Ball(QRect, QColor);

public:
    QRect get_rect() const;
    QRect& get_rect();
    QColor get_color() const;
    int get_dx() const;
    int get_dy() const;
    int& get_dx();
    int& get_dy();

public:
    void start();
    bool is_started();

private:
    QRect rect_;
    QColor color_;

    int dx_, dy_;
    bool started = false;
};


#endif // BALL_H
