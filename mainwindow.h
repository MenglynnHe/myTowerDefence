#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include"scene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *);

    Scene * scene=nullptr;



private:
    Ui::MainWindow *ui;

public slots:
   void play();//开始游戏
};

#endif // MAINWINDOW_H
