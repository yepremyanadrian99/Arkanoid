#ifndef Block_H
#define Block_H

#include <iostream>
#include <QRect>
#include <QColor>

class Block
{
public:
    Block(QRect rect, QColor color)
        :rect_(rect), color_(color)
    {}

    QRect get_rect() const;
    QColor get_color() const;
    bool is_destroyed() const;
    void destroy();

private:
    QRect rect_;
    QColor color_;
    bool destroyed = false;
};

#endif // Block_H
