#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    ui->setupUi(this);
    dropDown = centralWidget()->findChild<WordList *>("listWidget");
    textField = centralWidget()->findChild<MyLineEdit *>("lineEdit");
    statusBar()->clearMessage();
    QPushButton * pushButton =
                centralWidget()->findChild<QPushButton *>("pushButton");

    connect(pushButton, SIGNAL(clicked(bool)),
            textField, SLOT(clearTextBox()));
    connect(textField, SIGNAL(textEdited(const QString &)),
            dropDown, SLOT(setItems(const QString &)));
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

void MainWindow::textFieldSetText(const QString& str) {
    textField->setText(str);
}

void MainWindow::textFieldSaveCurrTextAsOriginal() {
    textField->storeOriginal();
}

QString MainWindow::getTextFieldOriginalString() {
    return textField->originalString;
}

void MainWindow::clearStatusBarText() {
    statusBar()->clearMessage();
}

void MainWindow::setStatusBarText(const QString& str, int timeout) {
    statusBar()->showMessage(str, timeout);
}

MainWindow::~MainWindow() {
    delete ui;
}
