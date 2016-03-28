#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dropDown = centralWidget()->findChild<WordList *>("listWidget");
    textField = centralWidget()->
                           findChild<MyLineEdit *>("lineEdit");
    QPushButton * pushButton = centralWidget()->
                              findChild<QPushButton *>("pushButton");
    connect(pushButton, SIGNAL(clicked(bool)),
            textField, SLOT(clearTextBox()));
    dropDown->setVisible(false);
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);
    QWidget *central = centralWidget();
    QWidget *layoutContainer = central->findChild<QWidget *>("layoutContainer");
    layoutContainer->move(QPoint((central->width() - layoutContainer->width()) / 2,
                                 (central->height() - layoutContainer->height()) / 2));
}

void MainWindow::dropDownSelNext() {
    dropDown->selectNext();
}

void MainWindow::dropDownSelPrev() {
    dropDown->selectPrev();
}

void MainWindow::dropDownClear() {
    dropDown->clearItems();
}

//void MainWindow::setWordList(WordList * listPtr) {
//    wordList = listPtr;
//}

//void MainWindow::setLineEdit(MyLineEdit * linePtr) {
//    lineEdit = linePtr;
//}

MainWindow::~MainWindow()
{
    delete ui;
}
