/*
 * Author: Galen Krulce, Shengyang Shi, Huajie Wu, Huayin Zhou
 * Description: Represents the top level QT window for the application.
 * Date: 01/28/2016
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void resizeEvent(QResizeEvent *event);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
