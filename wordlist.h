/*
 * Author: Huayin Zhou
 * Description: WordList is a customized QListWidget to keep track of the text
 * changes in QLineEdit and print strings to the changes accordingly by
 * calling pa3 function:
 * vector<std::string> autocomplete(unsigned int num_words, std::string prefix).
 * Date: 01/28/2015
 */
#ifndef WORDLIST_H
#define WORDLIST_H

#include <QListWidget>
#include <QString>
#include <QLineEdit>
#include <string>
#include <iostream>
#include <fstream>
#include <array>
#include "mylineedit.h"
#include "MWFTrie.hpp"

class MyLineEdit;

class WordList : public QListWidget
{
    Q_OBJECT

public:
    WordList(QWidget *parent = 0);
    void selectNext();
    void selectPrev();
    ~WordList();
    const static char * dictionary[];

public slots:
    void setItems(const QString &newString);
    void clearItems();
    void mouseClickClearItems(QListWidgetItem * item);

private:
    MyLineEdit *lineEdit;
    MWFTrie * trie;
    std::vector<std::string> predictCompletions(std::string prefix,
                                                unsigned int num_words);
};

#endif // WORDLIST_H
