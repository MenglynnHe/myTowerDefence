#ifndef TRAVELPATH_H
#define TRAVELPATH_H
#include "QPoint"
#include "QPainter"
//小兵行进路线
class TravelPath
{
public:
    TravelPath(QPoint pos);
    void setNextTravelPoint(TravelPath *nextPoint);
    TravelPath* get_nextTravelPoint() const;
    const QPoint get_pos() const;

    void draw(QPainter *painter) const;//画线

private:
    QPoint m_pos;//记下节点
    TravelPath * m_nextTravelPoint;

};

#endif // TRAVELPATH_H
