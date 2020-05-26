#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include "travelpath.h"
#include "scene.h"
#include <QSize>
#include"bloodbar.h"
class Scene;
class Tower;
class Enemy : public QObject
{
    Q_OBJECT


public:
    //当前敌人前进的位置-nowPoint,在scene场景中玩游戏，敌人的形象icon
    Enemy(TravelPath *nowPoint, Scene*game, const QPixmap &icon = QPixmap(":/enemy/dogface.png"));
    ~Enemy();

    void draw(QPainter *painter) const;
    void move();
    void getDamage(int damage);
    void getRemoved();
    int getLife() {return life;}  //生命长度
    int getOriginalLife()  {return origionlife;}
    void getAttacked(Tower *attacker);
    QList<Tower *>	attackTowersList;//攻击同一个敌人可能有多个列表
    QPoint getpos() const{return pos1;}
    bool getDamage(){return damage;}
    void removedBlood(BloodBar *blood);
    bool isChosen=0;
    bool			ifFree;//判断敌人是否空闲
public slots:
    void setFree();
    void setischosen(bool b){isChosen=b;}
protected:

    bool            damage;
    int				m_maxHp;
    //int				m_currentHp;
    int             life;
    qreal			m_walkingSpeed;
    qreal			m_rotationSprite;
    int             origionlife;//初始生命值
    QPoint			pos1;
    TravelPath *    targetPathPoint;//要去的目的地

    Scene*	        game;
   // QList<Tower *>	attackedTowersList;

    const QPixmap	icon;
    static const QSize fixedSize;//固定敌人的尺寸


signals:

public slots:
};

#endif // ENEMY_H
