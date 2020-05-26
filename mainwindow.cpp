#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QIcon"
#include "QPainter"
#include "mypushbutton.h"
#include "QTimer"
#include "enemy.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon(":/picture/logo.jpg"));//设置游戏图标
    this->setWindowTitle("Tower Defense 1.0");  //设置游戏标题
     this->setMouseTracking(true);                 //track mouse when mouse isn`t pressed
    this->setFixedSize(1200, 639);//固定窗口
    //退出
//    connect(ui->actionquit,&QAction::triggered,[=](){
//        this->close()});

    MyPushButton *startbtn=new MyPushButton(":/picture/startbutton.png");
    startbtn->setParent(this);//放在当前窗口下
    startbtn->move(375,354);
    connect(startbtn,&MyPushButton::clicked,[=](){
        //弹跳特效
    startbtn->upbounce();
    startbtn->downbounce();
    //延时500秒触发
    QTimer::singleShot(500,this,[=](){
    play();
    });

    });






}



void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/picture/map1.jpg");
    painter.drawPixmap(0,0,/*this->width(),this->height(),*/pix);//慎用图片铺平
    pix.load(":/picture/title.png");
    painter.drawPixmap(0,0,pix);


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::play(){

    scene= new Scene(this);
}


