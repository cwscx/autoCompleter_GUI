/*
 * Author: Galen Krulce, Shengyang Shi, Huajie Wu, Huayin Zhou
 * Description: This file is a custom LineEdit widget. This customization
 * allows us to respond to various user events as well as programmatically
 * control the string it displays.
 * Date: 01/28/2016
 */
#include "mylineedit.h"

MyLineEdit::MyLineEdit(QWidget *parent) : QLineEdit(parent) {
    wordList = parent->parentWidget()->findChild<WordList *>("listWidget");
    connect(this, SIGNAL(textEdited(const QString &)),
            this, SLOT(storeOriginal(const QString &)));
}

void MyLineEdit::setWordList(WordList * listPtr) {
    wordList = listPtr;
}

MyLineEdit::~MyLineEdit() {}

void MyLineEdit::storeOriginal() {
    originalString = text();
}

void MyLineEdit::storeOriginal(const QString & str) {
    originalString = str;
}

void MyLineEdit::clearTextBox() {
   setText("");
   wordList->clearItems();
}

void MyLineEdit::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()) {
        case Qt::Key_Down: // move down highlighter of wordList
            wordList->selectNext();
            break;
        case Qt::Key_Up:   // move up highlighter of wordList
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
