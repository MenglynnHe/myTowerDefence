#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include "QPoint"
#include "tower.h"
#include "enemy.h"
#include <QSize>
class Bullet : QObject
{
    Q_OBJECT
    Q_PROPERTY(QPoint currentPos READ currentPos WRITE setCurrentPos)

public:
    Bullet(QPoint startPos, QPoint targetPoint, int damage, Enemy *target,
           Scene *game, const QPixmap &icon= QPixmap(":/picture/bullet/trisbullet.png"));

    void draw(QPainter *painter) const;
    void move();
    void setCurrentPos(QPoint pos);
    QPoint currentPos() const;

private slots:
    void hitTarget();

private:
    const QPoint	startPos;
    const QPoint	targetPos;
    const QPixmap	icon;
    QPoint			current_Pos;
    Enemy *			target;
    Scene *	game;
    int				damage;

    static const QSize fixedSize;
};


#endif // BULLET_H
