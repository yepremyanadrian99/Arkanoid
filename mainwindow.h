#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>
#include <QPoint>
#include <QKeyEvent>
#include <QMouseEvent>

#include "ball.h"
#include "block.h"
#include "board.h"

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
    Ball* ball;
    Block* block;
    Board* board;

protected:
    void keyPressEvent(QKeyEvent* e);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
