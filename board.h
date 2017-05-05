#ifndef BOARD_H
#define BOARD_H

#include <iostream>

class Board
{
public:
    Board(int x = 0, int y = 0, int width = 0, int height = 0)
        : x(x), y(y), width(width), height(height)
    {}

    std::pair<int, int> get_coords() const;



private:
    int x, y;
    int width, height;
};

#endif // BOARD_H
