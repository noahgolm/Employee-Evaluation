#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class QVBoxLayout;

class MainWindow : public QWidget
{
public:
    MainWindow();
private:
    QVBoxLayout *layout;
};

#endif // MAINWINDOW_H
