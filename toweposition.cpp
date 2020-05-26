#include "towerposition.h"

#include <QPainter>

const QSize TowerPosition::ms_fixedSize(70, 70);

TowerPosition::TowerPosition(QPoint pos, const QPixmap &sprite/*= QPixmap(":/image/open_spot.png")*/)//定义时已经定义了，这里不用再初始化
    : m_hasTower(false)
    , m_pos(pos)
    , m_sprite(sprite)
{
}

const QPoint TowerPosition::centerPos() const
{
    //寻找中心点
    QPoint offsetPoint(ms_fixedSize.width() / 2, ms_fixedSize.height() / 2);
    return m_pos + offsetPoint;
}

bool TowerPosition::containPoint(const QPoint &pos) const
{
    //pos是否在区域内
    bool isXInArea = m_pos.x() < pos.x() && pos.x() < (m_pos.x() + ms_fixedSize.width());
    bool isYInArea = m_pos.y() < pos.y() && pos.y() < (m_pos.y() + ms_fixedSize.height());
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

