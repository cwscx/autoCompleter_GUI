/*
 * Author: Galen Krulce, Shengyang Shi, Huajie Wu, Huayin Zhou
 * Description: Get's the ball running. Creates and delegates to a top level
 * QT window.
 * Date: 01/28/2016
 */
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
