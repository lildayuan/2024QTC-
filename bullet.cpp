#include "bullet.h"
#include<QDebug>

Bullet::Bullet():justFreed(false)
{
    m_Bullet.load(BULLET_PATH);

    m_X = GAME_WIDTH *0.5 - m_Bullet.width() * 0.5;
    m_Y = GAME_HEIGHT;

    m_Free = true;

    m_Speed = BULLET_SPEED;

    m_Rect.setWidth(m_Bullet.width());
    m_Rect.setHeight(m_Bullet.height());
    m_Rect.moveTo(m_X,m_Y);
}

void Bullet::updatePosition()
{
    if(m_Free)
    {
        if (justFreed) {
            justFreed = false;  // 重置刚释放标志
            return;  // 保持空闲直到允许重用
        }
        return;
    }
    m_Y -= m_Speed;
    m_Rect.moveTo(m_X, m_Y);
    if(m_Y <= -m_Rect.height())
    {
        m_Free = true;
        justFreed = true;  // 标记为刚刚释放
    }
}
