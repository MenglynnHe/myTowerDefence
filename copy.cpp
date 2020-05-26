#include "copy.h"

Copy::Copy(QLabel* parent) : QLabel(parent)
{
    this->setCursor(Qt::OpenHandCursor);//设置鼠标的样式
}

Copy::~Copy()
{

}

AsheTowerCopy::AsheTowerCopy(QLabel *parent):Copy(parent)
{
    this->setMovie(copypic);
    copypic->start();

}

AsheTowerCopy::~AsheTowerCopy()
{
    delete this->copypic;
}

TristanaTowerCopy::TristanaTowerCopy(QLabel *parent):Copy(parent)
{
    this->setMovie(copypic);
    copypic->start();

}

TristanaTowerCopy::~TristanaTowerCopy()
{
    delete this->copypic;
}
