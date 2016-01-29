/*
 * Author: Huayin Zhou
 * Date: 01/28/2015
 */
#include "wordlist.h"
#include <QDebug>

WordList::WordList(QWidget *parent) : QListWidget(parent)
{
    lineEdit = parent->parentWidget()->findChild<QLineEdit *>("lineEdit");
    qDebug() << lineEdit << endl;
    connect(lineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(setItems(const QString &)));
}

WordList::~WordList()
{
}

void WordList::setItems(const QString &newString)
{
    qDebug() << "This is my custom setItems() method! " << newString << endl;
    clear();
    if (!newString.isEmpty())
    {
        //TODO: call the actual function and add items to this
        addItem(newString);
    }
    qDebug() << "size of each item" << rectForIndex(indexFromItem(item(0))).height();
    if (count() > 0)
    {
        setVisible(true);
        resize(width(), rectForIndex(indexFromItem(item(0))).height()*count());
    }
    else
        resize(width(), 0);
}
