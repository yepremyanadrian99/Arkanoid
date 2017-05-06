#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget::setMouseTracking(true);
    ball = new Ball(20, 20, 30);
    block = new Block(0, 0, 6, 8);
    board = new Board(QRect(QPoint(160, 280), QSize(80, 20)));
    update();
}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    p.setPen(Qt::blue);
    p.fillRect(board->get_rect(), Qt::SolidPattern);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* e)
{
    if(e->key() == Qt::Key_Left)
        board->move_left();
    else if(e->key() == Qt::Key_Right)
        board->move_right();
    update();
}
