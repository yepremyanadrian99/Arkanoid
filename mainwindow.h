#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>
#include <QPoint>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QThread>

#include <ball.h>
#include <block.h>
#include <board.h>
#include <map.h>

#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void paintEvent(QPaintEvent*);

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

public:
    QThread* th_move;
    Board* board;
    Ball* ball;
    std::vector<Block>* blocks;
    Map* map;

public:
    void set_blocks();
    void connects();
    void win();

public slots:
    void new_game();

protected:
    void keyPressEvent(QKeyEvent* e);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
