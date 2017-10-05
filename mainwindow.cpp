#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mainToolBar->hide();
    new_game();
}

void MainWindow::new_game()
{
    th_move = new QThread;
    board = new Board(QRect(QPoint(160, 280), QSize(80, 20)), Qt::black);
    blocks = new std::vector<Block>();
    set_blocks();
    ball = new Ball(QRect(QPoint(board->get_rect().x() + 30, board->get_rect().y() - 25), QSize(25, 25)), Qt::white);
    map = new Map(*board, *ball, *blocks, th_move);
    connects();
    map->start();
    update();
    qDebug("new game!");
}

void MainWindow::connects()
{
    map->moveToThread(th_move);
    connect(th_move, SIGNAL(started()), map, SLOT(ball_move()));
    connect(map, SIGNAL(update_signal()), this, SLOT(update()));
    connect(map, SIGNAL(finished()), th_move, SLOT(quit()));
    connect(map, SIGNAL(finished()), this, SLOT(new_game()));
    connect(map, SIGNAL(finished()), map, SLOT(deleteLater()));
    connect(th_move, SIGNAL(finished()), th_move, SLOT(deleteLater()));
}

void MainWindow::set_blocks()
{

    blocks->push_back(Block(QRect(QPoint(0, 0), QSize(board->get_rect().width(), board->get_rect().height())), Qt::red));
    //blocks->push_back(Block(QRect(QPoint(80, 0), QSize(board->get_rect().width(), board->get_rect().height())), Qt::yellow));
    blocks->push_back(Block(QRect(QPoint(160, 0), QSize(board->get_rect().width(), board->get_rect().height())), Qt::green));
    //blocks->push_back(Block(QRect(QPoint(240, 0), QSize(board->get_rect().width(), board->get_rect().height())), Qt::gray));
    blocks->push_back(Block(QRect(QPoint(320, 0), QSize(board->get_rect().width(), board->get_rect().height())), Qt::yellow));

    /*blocks->push_back(Block(QRect(QPoint(0, 20), QSize(board->get_rect().width(), board->get_rect().height())), Qt::yellow));
    blocks->push_back(Block(QRect(QPoint(80, 20), QSize(board->get_rect().width(), board->get_rect().height())), Qt::green));
    blocks->push_back(Block(QRect(QPoint(160, 20), QSize(board->get_rect().width(), board->get_rect().height())), Qt::red));
    blocks->push_back(Block(QRect(QPoint(240, 20), QSize(board->get_rect().width(), board->get_rect().height())), Qt::cyan));
    blocks->push_back(Block(QRect(QPoint(320, 20), QSize(board->get_rect().width(), board->get_rect().height())), Qt::gray));*/

    //blocks->push_back(Block(QRect(QPoint(0, 40), QSize(board->get_rect().width(), board->get_rect().height())), Qt::cyan));
    blocks->push_back(Block(QRect(QPoint(80, 60), QSize(board->get_rect().width(), board->get_rect().height())), Qt::gray));
    //blocks->push_back(Block(QRect(QPoint(160, 40), QSize(board->get_rect().width(), board->get_rect().height())), Qt::green));
    blocks->push_back(Block(QRect(QPoint(240, 60), QSize(board->get_rect().width(), board->get_rect().height())), Qt::cyan));
    //blocks->push_back(Block(QRect(QPoint(320, 40), QSize(board->get_rect().width(), board->get_rect().height())), Qt::red));

    blocks->push_back(Block(QRect(QPoint(0, 120), QSize(board->get_rect().width(), board->get_rect().height())), Qt::blue));
    //blocks->push_back(Block(QRect(QPoint(80, 80), QSize(board->get_rect().width(), board->get_rect().height())), Qt::yellow));
    blocks->push_back(Block(QRect(QPoint(160, 120), QSize(board->get_rect().width(), board->get_rect().height())), Qt::red));
    //blocks->push_back(Block(QRect(QPoint(240, 80), QSize(board->get_rect().width(), board->get_rect().height())), Qt::gray));
    blocks->push_back(Block(QRect(QPoint(320, 120), QSize(board->get_rect().width(), board->get_rect().height())), Qt::gray));

    //blocks->push_back(Block(QRect(QPoint(0, 120), QSize(board->get_rect().width(), board->get_rect().height())), Qt::cyan));
    blocks->push_back(Block(QRect(QPoint(80, 180), QSize(board->get_rect().width(), board->get_rect().height())), Qt::gray));
    //blocks->push_back(Block(QRect(QPoint(160, 120), QSize(board->get_rect().width(), board->get_rect().height())), Qt::green));
    blocks->push_back(Block(QRect(QPoint(240, 180), QSize(board->get_rect().width(), board->get_rect().height())), Qt::cyan));
    //blocks->push_back(Block(QRect(QPoint(320, 120), QSize(board->get_rect().width(), board->get_rect().height())), Qt::red));
}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    p.setPen(Qt::black);
    for(auto const& b : *blocks)
    {
        if(!b.is_destroyed())
        {
            p.setBrush(QBrush(b.get_color()));
            p.drawRect(b.get_rect());
        }
    }
    p.setBrush(QBrush(board->get_color()));
    p.drawRoundRect(board->get_rect());
    p.setBrush(QBrush(ball->get_color()));
    p.drawEllipse(ball->get_rect());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* e)
{
    if(!ball->is_started())
    {
        if(e->key() == Qt::Key_Space)
            ball->start();
        ball->get_rect().setX(board->get_rect().x() + 30);
        ball->get_rect().setY(board->get_rect().y() - 25);
        ball->get_rect().setSize(QSize(25, 25));
    }
    if((e->key() == Qt::Key_Left || e->key() == Qt::Key_A) && board->get_rect().x() > 0)
        board->move_left();
    else if((e->key() == Qt::Key_Right || e->key() == Qt::Key_D) && board->get_rect().x() < 320)
        board->move_right();
    update();
}
