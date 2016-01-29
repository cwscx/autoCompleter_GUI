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


std::vector<std::string> WordList::autocomplete(unsigned int num_words, std::string prefix) {


   std::vector<std::string> temp;
   for(int i = 0 ; i < 235886 ; i++) {
       if(std::string(dictionary[i]).find(prefix) == 0) {
           temp.push_back(std::string(dictionary[i]));
           if(temp.size() >= num_words) {
               break;
           }
       }
    }
    return temp;
}

void WordList::setItems(const QString &newString)
{
    qDebug() << "This is my custom setItems() method! " << newString << endl;
    clear();
    if (!newString.isEmpty())
    {
        std::vector<std::string> v = autocomplete(5, newString.toUtf8().constData());

        for(std::vector<std::string>::iterator it = v.begin(); it != v.end(); ++it) {
            addItem(QString::fromUtf8(it->c_str()));
        }
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


const char * WordList::dictionary[] = DICTIONARY;
