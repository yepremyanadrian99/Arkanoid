#ifndef BOARD_H
#define BOARD_H
#include <QRect>
class Board{
public:
    Board(QRect rect)
        :rect(rect)
    {
        size = rect.size();
    }
    QRect get_rect()
    {
        return rect;
    }

    void set_x(int x)
    {
        this->x = x;
        rect = QRect(QPoint(x, y), size);
    }

    void moveRight()
    {
        ++x;
        rect = QRect(QPoint(x, y), size);
    }


private:
    int x,y;
    QRect rect;
    QSize size;
};

#endif // BOARD_H
