#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(std::string path, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    /* Get pointers to the following components:
     *     Dropdown list
     *     Text box
     *     Clear button
     * */
    dictionaryPath = (path.compare("") == 0) ? std::string("../freq_dict.txt") : path;
    ui->setupUi(this);
    dropDown = centralWidget()->findChild<WordList *>("listWidget");
    textField = centralWidget()->findChild<MyLineEdit *>("lineEdit");
    QPushButton * pushButton =
                centralWidget()->findChild<QPushButton *>("pushButton");
    statusBar()->clearMessage();

    // connection of events /w ui components
    if (textFieldEnabled) {
        connect(pushButton, SIGNAL(clicked(bool)),
                textField, SLOT(clearTextBox()));
        connect(textField, SIGNAL(textEdited(const QString &)),
                dropDown, SLOT(setItems(const QString &)));
    } else {
        textField->setDisabled(true);
        textField->setStyleSheet(tr("background-color: rgb(211, 211, 211);"));
        setStatusBarText(tr(
          "Failed to open dictionary. Is the dictionary file in the parent directory?"));
    }
    dropDown->setVisible(false);
}

/*
 * resizeEvent is to resize mainWindow and put search box to center
 * */
void MainWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);
    QWidget *central = centralWidget();
    QWidget *layoutContainer = central->findChild<QWidget *>("layoutContainer");
    layoutContainer->move(QPoint((central->width() - layoutContainer->width()) / 2,
                                 (central->height() - layoutContainer->height()) / 2));
}

/*
 * Interface to select next item in the dropdown menu
 * */
void MainWindow::dropDownSelNext() {
    dropDown->selectNext();
}

/*
 * Interface to select previous item in the dropdown menu
 * */
void MainWindow::dropDownSelPrev() {
    dropDown->selectPrev();
}

/*
 * Interface to clear the dropdown menu
 * */
void MainWindow::dropDownClear() {
    dropDown->clearItems();
}

/*
 * Interface to set text in the text field
 * */
void MainWindow::textFieldSetText(const QString& str) {
    textField->setText(str);
}

/*
 * Interface to save the original text in text field.
 * Ref. mylineedit.h originalString definition for what original text means.
 * */
void MainWindow::textFieldSaveCurrTextAsOriginal() {
    textField->storeOriginal();
}

/*
 * Interface to retrieve the original text.
 * */
QString MainWindow::getTextFieldOriginalString() {
    return textField->originalString;
}

/*
 * Interface to clear the status bar.
 * */
void MainWindow::clearStatusBarText() {
    statusBar()->clearMessage();
}

/*
 * Interface to set text of the status bar with timeout.
 *
 * Timeout is default to 0, which means no timeout.
 *
 * Text of the status bar without a timeout shall be cleared by
 * call to clearStatusBarText().
 * */
void MainWindow::setStatusBarText(const QString& str, int timeout) {
    statusBar()->showMessage(str, timeout);
}

std::string MainWindow::getDictionaryPath() {
    return dictionaryPath;
}

void MainWindow::dictNotLoaded() {
    textFieldEnabled = false;
}

MainWindow::~MainWindow() {
    delete ui;
}
