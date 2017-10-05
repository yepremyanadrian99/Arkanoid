#ifndef MAP_H
#define MAP_H
#include <QObject>
#include <QThread>
#include <vector>
#include <board.h>
#include <ball.h>
#include <block.h>


class Map : public QObject
{
    Q_OBJECT

public:
    Map(Board&, Ball&, std::vector<Block>&, QThread* th_move);
    ~Map();

public slots:
    void ball_move();

signals:
    void finished();
    void update_signal();

public:
    void start();
    void hit_wall();
    void hit_board();
    void hit_blocks();
    bool lose();
    bool win();
    char border_intersection(Block, Ball);

private:
    Board* board_;
    Ball* ball_;
    std::vector<Block>* blocks_;
    QThread* thread_ball_;

};

#endif // MAP_H
