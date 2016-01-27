#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);
    QWidget *central = centralWidget();
    QVBoxLayout *layout = central->findChild<QVBoxLayout *>("verticalLayout");
    //QTextEdit *text = central->findChild<QTextEdit *>("textEdit");
    //QPushButton *button = central->findChild<QPushButton *>("pushButton");
    cout << "window " << width() << " " << height() << endl;
    cout << "central " << central->width() << " " << central->height() << endl;
    cout << "layout " << layout->geometry().width() << " " << layout->geometry().height() << endl;
    //layout->geometry().setX((central->width() - layout->geometry().width()) / 2);
    //layout->geometry().setY((central->height() - layout->geometry().height()) / 2);
    layout->geometry().moveCenter(QPoint(central->width() / 2), central->height() / 2);
    //central->move(QPoint((central->width() - layout->geometry().width()) / 2,
      //                   (central->height() - layout->geometry().height()) / 2));
}

MainWindow::~MainWindow()
{
    delete ui;
}
