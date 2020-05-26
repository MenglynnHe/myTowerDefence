#include "enemy.h"
#include "travelpath.h"
#include "tower.h"
#include "Qpainter"
#include "QDebug"
#include "bloodbar.h"
const QSize Enemy::fixedSize(40, 40);

Enemy::Enemy(TravelPath *nowPoint, Scene*game, const QPixmap &icon )
    : QObject(0)
    , ifFree(false)//初始空闲
    , m_maxHp(40)
    , m_walkingSpeed(2.0)
    , m_rotationSprite(0.0)
    , pos1(nowPoint->get_pos())//坐标赋值
    , targetPathPoint(nowPoint->get_nextTravelPoint())//目标点就是航点列表中的下一个点
    , game(game)
    , icon(icon)
    ,origionlife(100)
    ,life(100)
{
}

Enemy::~Enemy()
{
   // attackedTowersList.clear();
    targetPathPoint = NULL;
    game = NULL;
}

void Enemy::setFree()
{
    ifFree = true;
}


 void Enemy::draw(QPainter *painter) const
{
    if (!ifFree)//空闲状态的enemy
        return;
    // 血条的长度
    // 其实就是2个方框,红色方框表示总生命,固定大小不变
    // 绿色方框表示当前生命,受m_currentHp / m_maxHp的变化影响
//	static const int Health_Bar_Width = 20;
    painter->save();

    static const QPoint offsetPoint(-fixedSize.width() / 2, -fixedSize.height() / 2);
    painter->translate(pos1);
    //painter->rotate(m_rotationSprite);
    // 绘制敌人
    painter->drawPixmap(offsetPoint, icon);
    painter->restore();
}



void Enemy::move()
{
    if (!ifFree)
        return;

    if (if_collision_inCircle(pos1, 1, targetPathPoint->get_pos(), 1))// 敌人抵达了一个航点
    {

        if (targetPathPoint->get_nextTravelPoint())// 如果还存在下一个点
        {

            pos1 = targetPathPoint->get_pos();//修改当前到达的位置，即到达了一个航点
            targetPathPoint = targetPathPoint->get_nextTravelPoint();//更新目标航点
        }
        else
        {
            // 表示进入基地
            //m_game->getHpDamage();
            game->removedEnemy(this);
          //  game->removedBlood();
           // game->bloodbarList.removeOne();
            return;
        }
    }

    // 还在前往航点的路上
    // 目标航点的坐标
    QPoint targetPoint = targetPathPoint->get_pos();
    // 未来修改这个可以添加移动状态,加快,减慢,m_walkingSpeed是基准值

    // 向量标准化(整不明白）
    qreal movementSpeed = m_walkingSpeed;
    QVector2D normalized(targetPoint - pos1);
    normalized.normalize();
    pos1 = pos1 + normalized.toPoint() * movementSpeed;
 //   qDebug()<<"ok to enemy_move"<<endl;

    // 确定敌人选择方向
    // 默认图片向左,需要修正180度转右
    //m_rotationSprite = qRadiansToDegrees(qAtan2(normalized.y(), normalized.x())) + 180;
}

void Enemy::getAttacked(Tower *attacker)
{
    attackTowersList.push_back(attacker);
}
void Enemy::getRemoved()
{
    if (attackTowersList.empty())
        return;

    foreach (Tower *attacker, attackTowersList)
        attacker->targetKilled();
    // 通知game,此敌人已经阵亡
    game->removedEnemy(this);

}

void Enemy::getDamage(int damage)
{
   life -= damage;

    // 阵亡,需要移除
    if (life <= 0)
        getRemoved();
}
