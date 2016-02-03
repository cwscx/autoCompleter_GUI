/*
 * Author: Huayin Zhou
 * Date: 01/28/2015
 */
#include "wordlist.h"
#include <unistd.h>

WordList::WordList(QWidget *parent) : QListWidget(parent) {
    lineEdit = parent->parentWidget()->findChild<MyLineEdit *>("lineEdit");
    lineEdit->setWordList(this);
    connect(lineEdit, SIGNAL(textEdited(const QString &)),
            this, SLOT(setItems(const QString &)));
    connect(this, SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(mouseClickClearItems(QListWidgetItem *)));
    trie = new DictionaryTrie();
}

WordList::~WordList() {
   delete trie;
}

void WordList::selectNext() {
    int currRow = currentRow();
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

void WordList::selectPrev() {
    int currRow = currentRow();
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


void WordList::setItems(const QString &newString) {
    clear();
    if (!newString.isEmpty()) {
      std::string searchString = newString.toUtf8().constData();
      std::string prefixString = std::string();
      for (int i = 0; i < MAX_POSTFIX_TO_SEARCH; i++) { 
        std::vector<std::string> v = trie->predictCompletions(searchString, 
                                                              MAX_DISPLAY);
        for(std::vector<std::string>::iterator it = v.begin(); 
            it != v.end(); ++it) {
            addItem(QString::fromUtf8(it->c_str()).prepend(
                      QString::fromUtf8(prefixString.c_str())));
        }

        if (count() >= MAX_DISPLAY) break;
        int spacePos = searchString.find_first_of(' ');
        if (spacePos == string::npos 
           || spacePos + 1 >= searchString.length()) break;

        prefixString += searchString.substr(0, spacePos + 1);
        searchString = searchString.substr(spacePos + 1);
      }
    }
    if (count() > 0) {
        setVisible(true);
        resize(width(), 
               rectForIndex(indexFromItem(item(0))).height()*count() + 5);
    } else {
        resize(width(), 0);
    }
}

void WordList::clearItems() {
    lineEdit->storeOriginal();
    clear();
    resize(width(), 0);
}

void WordList::mouseClickClearItems(QListWidgetItem * item) {
    lineEdit->setText(item->text());
    lineEdit->storeOriginal();
    clear();
    resize(width(), 0);
}
