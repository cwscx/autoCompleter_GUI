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

void MyLineEdit::storeOriginal() {
    originalString = text();
    qDebug() << "Original Stored: " << originalString;
}

void MyLineEdit::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()) {
        case Qt::Key_Down: // move down highlighter of wordList
            qDebug() << this << "key down pressed!";
            wordList->selectNext();
            break;
        case Qt::Key_Up:   // move up highlighter of wordList
            qDebug() << this << "key up pressed!";
            wordList->selectPrev();
            break;
        case Qt::Key_Return:
            wordList->clearItems();
            break;
        default:
            // default handler for event
            QLineEdit::keyPressEvent(event);
    }
}
