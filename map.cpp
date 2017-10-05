#include "map.h"

Map::Map(Board& board, Ball& ball, std::vector<Block>& blocks, QThread* thread_ball)
{
    board_ = &board;
    ball_  = &ball;
    blocks_ = &blocks;
    thread_ball_ = thread_ball;
}

Map::~Map()
{}

void Map::ball_move()
{
    while(true)
    {
        if(!ball_->is_started())
            continue;
        QThread::msleep(5);
        ball_->get_rect().setX(ball_->get_rect().x() + ball_->get_dx());
        ball_->get_rect().setY(ball_->get_rect().y() + ball_->get_dy());
        ball_->get_rect().setWidth(ball_->get_rect().height() + ball_->get_dy());
        ball_->get_rect().setHeight(ball_->get_rect().height() + ball_->get_dy());
        hit_wall();
        hit_board();
        hit_blocks();
        if(lose())
        {
            qDebug("Lost!");
            emit finished();
            break;
        }
        if(win())
        {
            qDebug("Win!");
            emit finished();
            break;
        }
        emit update_signal();
    }
}

void Map::hit_board()
{
    if(ball_->get_rect().x() + ball_->get_rect().width() >= board_->get_rect().x() &&
            ball_->get_rect().x() <= board_->get_rect().x() + board_->get_rect().width() &&
            ball_->get_rect().y() + ball_->get_rect().height() >= board_->get_rect().y())
    {
        ball_->get_dy() = -ball_->get_dy();
        if((ball_->get_rect().x() + ball_->get_rect().width() / 2 < board_->get_rect().x() + board_->get_rect().width() / 2 &&
                ball_->get_dx() > 0) ||
                (ball_->get_rect().x() + ball_->get_rect().width() / 2 >= board_->get_rect().x() + board_->get_rect().width() / 2 &&
                ball_->get_dx() < 0))
            ball_->get_dx() = -ball_->get_dx();
        qDebug("hit board!");
    }
}

void Map::hit_wall()
{
    if(ball_->get_rect().x() >= 350 + ball_->get_rect().width() || ball_->get_rect().x() <= 0)
        ball_->get_dx() = -ball_->get_dx();
    if(ball_->get_rect().y() <= 0)
        ball_->get_dy() = -ball_->get_dy();
}

void Map::hit_blocks()
{
    for(auto& b : *blocks_)
    {
        /*if(ball_->get_rect().x() >= b.get_rect().x() && ball_->get_rect().x() <= b.get_rect().x() + b.get_rect().width() &&
                ball_->get_rect().y() - ball_->get_rect().height() <= b.get_rect().y()
                && ball_->get_rect().y() + ball_->get_rect().height() >= b.get_rect().y() + b.get_rect().height())
        {
            if(!b.is_destroyed())
            {
                b.destroy();
                ball_->get_dy() = -ball_->get_dy();
                qDebug("hit block!");
            }
        }*/
        if(b.is_destroyed())
            continue;
        char dir = border_intersection(b, *ball_);
        switch(dir)
        {
        case 'u':
            qDebug("up");
            ball_->get_dy() = -ball_->get_dy();
            b.destroy();
            break;
        case 'd':
            qDebug("down");
            ball_->get_dy() = -ball_->get_dy();
            b.destroy();
            break;
        case 'l':
            qDebug("left");
            ball_->get_dx() = -ball_->get_dx();
            b.destroy();
            break;
        case 'r':
            qDebug("right");
            ball_->get_dx() = -ball_->get_dx();
            b.destroy();
            break;
        }
    }
}

char Map::border_intersection(Block block, Ball ball)
{
    if(ball.get_rect().y() <= block.get_rect().y() + block.get_rect().height() &&
            ball.get_rect().y() + ball.get_rect().height() >= block.get_rect().y() &&
            ball.get_rect().x() <= block.get_rect().x() + block.get_rect().width() &&
            ball.get_rect().x() + ball.get_rect().width() >= block.get_rect().x())
    {
        if(ball.get_rect().x() >= block.get_rect().x() + block.get_rect().width())
            return 'r';
        if(ball.get_rect().x() + ball.get_rect().width() <= block.get_rect().x())
            return 'l';
        if(ball.get_rect().y() >= block.get_rect().y() + block.get_rect().height())
            return 'd';
        if(ball.get_rect().y() + ball.get_rect().height() <= block.get_rect().y())
            return 'u';
    }
    return ' ';
}

bool Map::lose()
{
    if(ball_->get_rect().y() >= 300)
        return true;
    return false;
}

void Map::start()
{
    thread_ball_->start();
}

bool Map::win()
{
    for(auto b : *blocks_)
        if(!b.is_destroyed())
            return false;
    return true;
}
