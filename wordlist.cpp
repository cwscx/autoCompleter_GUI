/*
 * Author: Huayin Zhou
 * Date: 01/28/2015
 */
#include "wordlist.h"
#include <QDebug>
#include <unistd.h>

WordList::WordList(QWidget *parent) : QListWidget(parent)
{
    lineEdit = parent->parentWidget()->findChild<MyLineEdit *>("lineEdit");
    lineEdit->setWordList(this);
    qDebug() << lineEdit << endl;
    connect(lineEdit, SIGNAL(textEdited(const QString &)),
            this, SLOT(setItems(const QString &)));
    connect(this, SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(mouseClickClearItems(QListWidgetItem *)));
}

WordList::~WordList()
{
}

void WordList::selectNext() {
    int currRow = currentRow();
    qDebug() << "CurrentRow(): " << currentRow();
    qDebug() << "CurrentCount: " << count();
    if (currRow == count() - 1) {
        currRow = -1;
    } else {
        currRow++;
    }

    setCurrentRow(currRow);
    if (currentRow() != -1) {
        lineEdit->setText(currentItem()->text());
    } else {
        lineEdit->setText(lineEdit->originalString);
    }
}

void WordList::selectPrev(){
    int currRow = currentRow();
    qDebug() << "CurrentRow(): " << currentRow();
    qDebug() << "CurrentCount: " << count();
    if (currRow == -1) {
        currRow = count() - 1;
    } else {
        currRow--;
    }

    setCurrentRow(currRow);
    if (currentRow() != -1) {
        lineEdit->setText(currentItem()->text());
    } else {
        lineEdit->setText(lineEdit->originalString);
    }
}


void WordList::setItems(const QString &newString)
{
    qDebug() << "This is my custom setItems() method! " << newString << endl;
    clear();
    if (!newString.isEmpty())
    {   //TODO: Call the function from student code.
        std::vector<std::string> v = trie->predictCompletions(newString.toUtf8().constData(), 10);
        qDebug() << "Size of v: " << v.size() << endl;
        for(std::vector<std::string>::iterator it = v.begin(); it != v.end(); ++it) {
            addItem(QString::fromUtf8(it->c_str()));
        }
    }
    qDebug() << "size of each item" << rectForIndex(indexFromItem(item(0))).height();
    if (count() > 0)
    {
        setVisible(true);
        resize(width(), rectForIndex(indexFromItem(item(0))).height()*count() + 5);
    }
    else
        resize(width(), 0);
}

void WordList::clearItems() {
    qDebug() << "Clearing candidate box." << endl;
    lineEdit->storeOriginal();
    clear();
    resize(width(), 0);
}

void WordList::mouseClickClearItems(QListWidgetItem * item) {
    qDebug() << "Clearing candidate box." << endl;
    lineEdit->setText(item->text());
    lineEdit->storeOriginal();
    clear();
    resize(width(), 0);
}
