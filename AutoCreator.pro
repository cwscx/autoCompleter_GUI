#-------------------------------------------------
#
# Project created by QtCreator 2016-01-26T17:02:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AutoCreator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    wordlist.cpp \
    mylineedit.cpp \
    autocomplete_util.cpp \
    MNode.cpp \
    MWFTrie.cpp \
    autocomplete_util.cpp \
    MNode.cpp


HEADERS  += mainwindow.h \
    wordlist.h \
    mylineedit.h \
    autocomplete_util.hpp \
    MNode.hpp \
    MWFTrie.hpp \
    constants.hpp

FORMS    += mainwindow.ui
CONFIG += c++11
