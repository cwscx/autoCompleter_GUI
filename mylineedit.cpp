#include "mylineedit.h"
#include <QDebug>

MyLineEdit::MyLineEdit(QWidget *parent) : QLineEdit(parent)
{
    wordList = parent->parentWidget()->findChild<WordList *>("listWidget");
    qDebug() << "wordList pointer: " << wordList << endl;
    connect(this, SIGNAL(textEdited(const QString &)),
            this, SLOT(storeOriginal(const QString &)));
}

void MyLineEdit::setWordList(WordList * listPtr) {
    wordList =listPtr;
    qDebug() << "wordList pointer: " << wordList << endl;
}

MyLineEdit::~MyLineEdit() {}

void MyLineEdit::storeOriginal(const QString &newString) {
    originalString = newString;
    qDebug() << originalString;
}

void MyLineEdit::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Down)
    {
            // move down highlighter of wordList
            qDebug() << this << "key down pressed!";
            wordList->selectNext();
    }
    else if (event->key() == Qt::Key_Up)
    {
            qDebug() << this << "key up pressed!";
            wordList->selectPrev();
    }
    else{
            // default handler for event
            QLineEdit::keyPressEvent(event);
    }
}
