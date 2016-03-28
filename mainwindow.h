#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "wordlist.h"
#include "mylineedit.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void resizeEvent(QResizeEvent *event);

    void dropDownSelNext();
    void dropDownSelPrev();
    void dropDownClear();

    void textFieldSetText(const QString& str);
    void textFieldSaveCurrTextAsOriginal();

    QString getTextFieldOriginalString();
private:
    Ui::MainWindow *ui;
    MyLineEdit * textField;
    WordList * dropDown;

};

#endif // MAINWINDOW_H
