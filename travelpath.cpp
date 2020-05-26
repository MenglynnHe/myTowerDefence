#include "travelpath.h"
#include "QPoint"
TravelPath::TravelPath(QPoint pos)
    : m_pos(pos)
    , m_nextTravelPoint(nullptr)
{
}

void TravelPath::setNextTravelPoint(TravelPath *nextPoint)
{
    m_nextTravelPoint = nextPoint;
}

TravelPath* TravelPath::get_nextTravelPoint() const
{
    return m_nextTravelPoint;
}

const QPoint TravelPath::get_pos() const
{
    return m_pos;
}

void TravelPath::draw(QPainter *painter) const
{
    painter->save();//保存画笔状态
    painter->setPen(QColor(0, 255, 0));
    painter->drawEllipse(m_pos, 6, 6);
    painter->drawEllipse(m_pos, 2, 2);

    if (m_nextTravelPoint)
        painter->drawLine(m_pos, m_nextTravelPoint->m_pos);
    painter->restore();//恢复画笔状态

}
