#include "mypushbutton.h"
#include "QDebug"
#include "QPropertyAnimation.h"

MyPushButton::MyPushButton(QString normalImg,QString pressImg){

    this->normalImgpath=normalImg;
    this->pressImgpath=pressImg;

    QPixmap pix;
    bool ret=pix.load(normalImg);
    if(!ret)
    {
       qDebug()<<"图片加载失败"<<endl;
       return;
    }

    this->setFixedSize(pix.width(),pix.height());//设置图片的固定大小
    this->setStyleSheet("QPushButton{border:5px;}");//设置不规则图片样式
    this->setIcon(pix);//设置图标
    this->setIconSize(QSize(pix.width(),pix.height()));//设置图标大小

}

void MyPushButton::upbounce(){
    QPropertyAnimation *animation= new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);//设置动画时间间隔
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));//起始位置
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));//结束位置
    animation->setEasingCurve(QEasingCurve::OutBounce);//设置inbounce的弹跳曲线
    animation->start();//执行动画
}
void MyPushButton::downbounce(){
    QPropertyAnimation *animation= new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);//设置动画时间间隔
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));//起始位置
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));//结束位置
    animation->setEasingCurve(QEasingCurve::OutBounce);//设置inbounce的弹跳曲线
    animation->start();//执行动画
}
