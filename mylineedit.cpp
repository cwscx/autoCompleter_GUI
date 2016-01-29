#include "mylineedit.h"
#include <QDebug>

MyLineEdit::MyLineEdit(QWidget *parent) : QLineEdit(parent)
{
    wordList = parent->findChild<WordList *>("listWidget");
    qDebug() << wordList << endl;
    // maybe connect enter pressed to button pressed/ or autocomplete in wordlist?
    //connect(lineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(setItems(const QString &)));
}

MyLineEdit::~MyLineEdit() {}

void MyLineEdit::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Down)
    {
            // move down highlighter of wordList
            qDebug() << this << "key down pressed!";
    }
    else if (event->key() == Qt::Key_Up)
    {
            // move up highlighter of wordList;
            qDebug() << this << "key up pressed!";
    }
    else{
            // default handler for event
            QLineEdit::keyPressEvent(event);
    }
}
