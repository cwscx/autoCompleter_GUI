#-------------------------------------------------
#
# Project created by QtCreator 2016-01-26T17:02:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Autocomplete
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    wordlist.cpp \
    mylineedit.cpp \
    ../DictionaryTrie.cpp \
    ../util.cpp

HEADERS  += mainwindow.h \
    wordlist.h \
    mylineedit.h \
    ../DictionaryTrie.cpp \
    ../util.cpp

FORMS    += mainwindow.ui
CONFIG += c++11
