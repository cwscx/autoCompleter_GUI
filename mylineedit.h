#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>
#include <QListWidget>
#include <QKeyEvent>
#include "wordlist.h"

class MyLineEdit : public QLineEdit
{
    Q_OBJECT

public:
    MyLineEdit(QWidget *parent = 0);
    ~MyLineEdit();

protected:
    void keyPressEvent(QKeyEvent *event);


private:
    WordList *wordList;
};

#endif // MYLINEEDIT_H
