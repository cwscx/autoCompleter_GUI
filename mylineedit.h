/*
 * Author: Galen Krulce, Shengyang Shi, Huajie Wu, Huayin Zhou
 * Description: This file is a custom LineEdit widget. This customization
 * allows us to respond to various user events as well as programmatically
 * control the string it displays.
 * Date: 01/28/2016
 */
#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>
#include <QListWidget>
#include <QKeyEvent>
#include "wordlist.h"
class WordList;
class MyLineEdit : public QLineEdit
{
    Q_OBJECT

public:
    QString originalString;
    MyLineEdit(QWidget *parent = 0);
    void setWordList(WordList *);
    ~MyLineEdit();
    void storeOriginal();

private slots:
    void storeOriginal(const QString &);
    void clearTextBox();

protected:
    void keyPressEvent(QKeyEvent *event);


private:
    WordList *wordList;
};

#endif // MYLINEEDIT_H
