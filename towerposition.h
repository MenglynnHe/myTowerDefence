#ifndef TOWERPOSITION_H
#define TOWERPOSITION_H
#include <QPoint>
#include "QPainter"
#include <QSize>
#include <QPixmap>
class TowerPosition
{

public:
    TowerPosition(QPoint pos, const QPixmap &sprite = QPixmap(":/picture/buttom2.png"));

    void setHasTower(bool hasTower = true);
    bool hasTower() const;
    const QPoint centerPos() const;
    bool containPoint(const QPoint &pos) const;

    void draw(QPainter *painter) const;

private:
    QPoint		m_pos;
    bool		m_hasTower;
    QPixmap		m_sprite;

    static const QSize ms_fixedSize;
};


#endif // TOWERPOSITION_H
