#include "towerposition.h"

#include <QPainter>
#include "QDebug"
const QSize TowerPosition::ms_fixedSize(70, 70);

TowerPosition::TowerPosition(QPoint pos, const QPixmap &sprite/*= QPixmap("://picture/unnamed (4).jpg")*/)//定义时已经定义了，这里不用再初始化
    : m_hasTower(false)
    , m_pos(pos)
    , m_sprite(sprite)
{
    m_sprite=m_sprite.scaled(m_sprite.width() *0.5,m_sprite.height() *0.5);

}

const QPoint TowerPosition::centerPos() const
{
    //寻找中心点
    QPoint offsetPoint(ms_fixedSize.width() / 2, ms_fixedSize.height() / 2);
   // qDebug()<<"centerpos"<<offsetPoint+m_pos<<endl;
    return m_pos + offsetPoint;
}

bool TowerPosition::containPoint(const QPoint &pos) const
{
    //pos是否在区域内
    bool isXInArea = m_pos.x() < pos.x() && pos.x() < (m_pos.x() + ms_fixedSize.width());
    bool isYInArea = m_pos.y() < pos.y() && pos.y() < (m_pos.y() + ms_fixedSize.height());
   // qDebug()<<"containpoint-"<<m_pos.x()<<" "<<m_pos.y()<<endl;
   // qDebug()<<"now here"<<pos.x()<<" "<<pos.y()<<endl;
    return isXInArea && isYInArea;
}

bool TowerPosition::hasTower() const
{
    //判断是否有塔
    return m_hasTower;
}

void TowerPosition::setHasTower(bool hasTower/* = true*/)
{
    //设置成有塔状态
    m_hasTower = hasTower;
}

void TowerPosition::draw(QPainter *painter) const
{

    //绘制塔座，drawPixmap以左上为参考点
    painter->drawPixmap(m_pos.x(), m_pos.y(), m_sprite);
}
