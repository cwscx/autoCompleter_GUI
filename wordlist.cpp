/*
 * Author: Galen Krulce, Shengyang Shi, Huajie Wu, Huayin Zhou
 * Description: WordList is a customized QListWidget to keep track of the text
 * changes in QLineEdit and print strings to the changes accordingly by
 * calling pa3 function:
 * vector<std::string> autocomplete(unsigned int num_words, std::string prefix).
 * Date: 01/28/2016
 */
#include "wordlist.h"
#include <unistd.h>
#include <QDebug>
#include <fstream>

WordList::WordList(QWidget *parent) : QListWidget(parent) {
   lineEdit = parent->parentWidget()->findChild<MyLineEdit *>("lineEdit");
   lineEdit->setWordList(this);
   connect(lineEdit, SIGNAL(textEdited(const QString &)),
           this, SLOT(setItems(const QString &)));
   connect(this, SIGNAL(itemClicked(QListWidgetItem*)),
           this, SLOT(mouseClickClearItems(QListWidgetItem *)));

   trie = new DictionaryTrie();
   // Read the dictionary into DictTrie 
   std::ifstream in;
   in.open("../freq_dict.txt");
   Timer T;
   T.load_dict(*trie, in);
   in.close();
}

WordList::~WordList() {
   delete trie;
}

// Select the next item in drop down menu. The selected text will be sent to
// input bar, but the original input can be retrieved later.
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

// Select the prev item in drop down menu. The selected text will be sent to
// input bar, but the original input can be retrieved later.
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

// Populate the drop down menu by searching prediction of word in input bar
void WordList::setItems(const QString &newString) {
    clear();
    if (!newString.isEmpty()) {
      vector<string> prefixString;
      vector<string> searchString;
      std::string originString = newString.toUtf8().constData();
      std::string trailingSpaces = std::string();
      // Get the trailing spaces
      while (originString.find_last_of(' ') == originString.length() - 1) {
         originString.pop_back();
         trailingSpaces += " ";
      }

      int spacePos = originString.length();
      // Construct postfixes
      for (int i = 0; i < MAX_POSTFIX_TO_SEARCH; i++) {
         spacePos = originString.find_last_of(' ', spacePos - 1);

         prefixString.push_back(originString.substr(0, spacePos + 1));
         searchString.push_back( 
            originString.substr(spacePos + 1) + trailingSpaces);
         
         if (spacePos == string::npos) break;
      }

/*    
      for (int i = searchString.size() - 1; i >= 0; i--) {
         qDebug() << "Prefix " << i << ": " << QString::fromUtf8(prefixString[i].c_str());
         qDebug() << "Search " << i << ": " << QString::fromUtf8(searchString[i].c_str());
         qDebug() << "Trail :" << trailingSpaces.length() << endl;
      }
*/
      // Search each postfix
      for (int i = searchString.size() - 1; i >= 0; i--) { 
         std::vector<std::string> v = 
            trie->predictCompletions(searchString[i], MAX_DISPLAY);
         for(std::vector<std::string>::iterator it = v.begin(); 
            it != v.end(); ++it) {
            addItem(QString::fromUtf8(it->c_str()).prepend(
                      QString::fromUtf8(prefixString[i].c_str())));
            if (count() >= MAX_DISPLAY) break;  
         }

         if (count() >= MAX_DISPLAY) break;    
      }
    }

    // Resize drop down menu
    if (count() > 0) {
        setVisible(true);
        resize(width(), 
               rectForIndex(indexFromItem(item(0))).height()*count() + 5);
    } else {
        resize(width(), 0);
    }
}


// Clear the drop down menu BUT RETAIN the content in input bar
void WordList::clearItems() {
    lineEdit->storeOriginal();
    clear();
    resize(width(), 0);
}

// Clear the drop down menu, replace the content in input bar with
// the clicked item
void WordList::mouseClickClearItems(QListWidgetItem * item) {
    lineEdit->setText(item->text());
    lineEdit->storeOriginal();
    clear();
    resize(width(), 0);
}
