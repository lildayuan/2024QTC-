#ifndef BULLET_H
#define BULLET_H
#include"config.h"
#include<QPixmap>
#include<QRect>

class Bullet
{
public:
    Bullet();

public:
    void updatePosition();
    QPixmap m_Bullet;

    int m_X,m_Y;

    int m_Speed;

    bool m_Free;

    bool justFreed;

    QRect m_Rect;


};

#endif // BULLET_H
