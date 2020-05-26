#ifndef SCENE_H
#define SCENE_H
#include "towerposition.h"
#include <QMainWindow>
#include <QList>
#include <tower.h>
#include "QLabel"
#include "mypushbutton.h"
#include "QMovie"
#include "copy.h"
#include "QMouseEvent"
#include "travelpath.h"
#include "enemy.h"
#include "bullet.h"
#include "bloodbar.h"
//场景布置
class Enemy;
class Tower;
class Bullet;
class BloodBar;
class Scene : public QLabel
{
    Q_OBJECT
public:
    explicit Scene(QWidget *parent = nullptr);
    ~Scene();
    void paintEvent(QPaintEvent *);
    void loadTowerPositions();

    bool canBuyTower() const;
    bool loadWave();//加载波数
    void setTowerup();//确定塔可以放的位置
    void setCopyup();//设置基塔放置的地方，就是选择塔的地方
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent *event);

    QList<TravelPath *> m_pathPointsList;	// 在paintEvent中需要进行绘制
    void addPathPoints();			// 形成一条完整的travel节点列表，在构造函数中调用
    void addBullet(Bullet *bullet);

    void removedEnemy(Enemy *enemy);//去除enemy
    void removedBullet(Bullet *bullet);
    void removedBlood(BloodBar *blood);
    void preLoadWavesInfo();
    QList<Enemy *> enemyList() const;



    int settletower=-1;//默认最开始的塔为-1---ashetower
    Copy* settleCopy=nullptr;//确定要安装的塔的复印件
    QList<Copy*> towerCopy;
    QPoint whichtowerPos;//记录你选择的基塔的位置，之后移动基塔后还得放回去
    QPoint pp;
    int						waves;
private:

     QLabel * lab1= new QLabel(this);
     QLabel * lab2= new QLabel(this);
     QLabel * lab3= new QLabel(this);
     QLabel * lab4= new QLabel(this);
     QLabel * lab5= new QLabel(this);
     QLabel * lab6= new QLabel(this);
     QLabel * lab7= new QLabel(this);
     QLabel * lab8= new QLabel(this);
     QLabel * lab9= new QLabel(this);
     QLabel * lab10= new QLabel(this);
     QLabel * lab11= new QLabel(this);
     //QLabel * lab12= new QLabel(this);
     QList<TowerPosition>    m_towerPositionsList;
     QList<Tower *>          m_towersList;
     QLabel* copyBar = new QLabel(this);
     QMovie* copyBarPic = new QMovie(":/picture/copybase.png");
     QList<Enemy *>			m_enemyList;
     QList<Bullet *>			bulletList;
     QList<QVariant>			wavesInfo;
     QList<BloodBar *>      bloodbarList;
   //  QList<TravelPath *>		travelPointList;//航点列表

signals:
     void  toPlay();
public slots:
    void updateMap();
    void gameStart();
};





#endif // SCENE_H
