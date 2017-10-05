#ifndef BOARD_H
#define BOARD_H
#include <QRect>
#include <QColor>

class Board{

public:
    Board(QRect rect, QColor color)
        :rect_(rect), color_(color)
    {}

    Board()
    {}

    QRect get_rect() const;
    QColor get_color() const;

    void set_pos(int);

    void update();

    void move_right();
    void move_left();

private:
    QRect rect_;
    QColor color_;
    int dx = 10;
};

#endif // BOARD_H
