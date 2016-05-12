#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::string path = (argc == 2) ? std::string(argv[1]) : std::string("");
    MainWindow w(path, 0);
    w.show();

    return a.exec();
}
