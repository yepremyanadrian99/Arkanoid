#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    paintEvent(QPaintEvent*);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
