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

/*
 * Setter for wordlist field. 
 */
void MyLineEdit::setWordList(WordList * listPtr) {
    wordList = listPtr;
}

MyLineEdit::~MyLineEdit() {}

/*
 * Store the current text in the search bar
 * so that it can be retrieved later.
 */
void MyLineEdit::storeOriginal() {
    originalString = text();
}

/*
 * Store a specified string into a memory.
 */
void MyLineEdit::storeOriginal(const QString & str) {
    originalString = str;
}

/*
 * Clear box search bar and dropdown menu
 */
void MyLineEdit::clearTextBox() {
   setText("");
   wordList->clearItems();
}

/*
 * Key press event handler
 */
void MyLineEdit::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()) {
        case Qt::Key_Down:   // move down highlighter of wordList
            wordList->selectNext();
            break;
        case Qt::Key_Up:     // move up highlighter of wordList
            wordList->selectPrev();
            break;
        case Qt::Key_Return: // Ref. WordList::clearItems();
            wordList->clearItems();
            break;
        default:
            // default handler for event
            QLineEdit::keyPressEvent(event);
    }
}
