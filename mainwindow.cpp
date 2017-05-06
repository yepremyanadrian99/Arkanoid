#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ball =new Ball(20,20,30);
    block = new Block(0,0,6,8);
    board = new Board(QRect(QPoint(100,80), QSize(80,20)));
    update();
}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    p.setPen(Qt::blue);
    p.drawRect(board->get_rect());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::RightArrow)
    {
        board->moveRight();
    }
    update();
}
