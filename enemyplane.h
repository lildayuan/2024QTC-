#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H
#include <QPixmap>

class EnemyPlane
{
public:
    EnemyPlane();

    //更新坐标
    void updatePosition();

public:

    QPixmap m_enemy;

    int m_X,m_Y;

    //敌机的矩形边框（碰撞检测）
    QRect m_Rect;
    //状态
    bool m_Free;

    //速度
    int m_Speed;
};


#endif // ENEMYPLANE_H
