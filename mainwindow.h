#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "wordlist.h"
#include "mylineedit.h"

class MyLineEdit;
class WordList;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0) { MainWindow(std::string(""), parent); }
    explicit MainWindow(std::string path, QWidget *parent = 0);
    ~MainWindow();
    void resizeEvent(QResizeEvent *event);

    void dropDownSelNext();
    void dropDownSelPrev();
    void dropDownClear();

    void textFieldSetText(const QString& str);
    void textFieldSaveCurrTextAsOriginal();

    void clearStatusBarText();
    void setStatusBarText(const QString& str, int timeout = 0);

    QString getTextFieldOriginalString();
    std::string getDictionaryPath();

    void dictNotLoaded();
private:
    Ui::MainWindow *ui;
    MyLineEdit * textField;
    WordList * dropDown;
    std::string dictionaryPath;

    bool textFieldEnabled = true;
};

#endif // MAINWINDOW_H
