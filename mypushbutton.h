#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
   // explicit MyPushButton(QWidget *parent = nullptr);
    MyPushButton(QString normalImg,QString pressImg="");//正常显示的图片路径；按下后显示的图片路径

    //路径保存
    QString normalImgpath;
    QString pressImgpath;
    //弹跳特效实现
    void upbounce();//向上跳
    void downbounce();//向下跳
signals:

public slots:
};

#endif // MYPUSHBUTTON_H
