#ifndef Block_H
#define Block_H
#include <iostream>
#include <QRect>
#include <QColor>

class Block
{
public:
    Block(int x = 0, int y = 0, int w = 0, int h = 0)
        :x(x), y(y), width(w), height(h)
    {
    }

    std::pair<int, int> get_coords() const;

    bool is_destroyed() const;

public:
    QRect block_rect;


private:
    int x, y, width, height;
    bool crashed = false;
    QColor block_color;
};

#endif // Block_H
