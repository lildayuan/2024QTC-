#include "heroplane.h"
#include "config.h"
#include <QDir>
#include<QDebug>

HeroPlane::HeroPlane()
{

    m_Plane.load(HERO_PATH);

    //初始化坐标
    m_X = GAME_WIDTH * 0.5 - m_Plane.width()*0.5;
    m_Y = GAME_HEIGHT - m_Plane.height();

    //初始化矩形框
    m_Rect.setWidth(m_Plane.width());
    m_Rect.setHeight(m_Plane.height());
    m_Rect.moveTo(m_X,m_Y);
    //初始化发射间隔记录
    m_recorder = 0;

}

void HeroPlane::setPosition(int x, int y)
{
    m_X = x;
    m_Y = y;
    m_Rect.moveTo(m_X,m_Y);
}

void HeroPlane::shoot()
{
    m_recorder++;
    if(m_recorder < BULLET_INTERVAL)
        {
        return;
        }
     m_recorder = 0;

    for(int i = 0 ; i < BULLET_NUM;i++)
    {
        if(m_bullets[i].m_Free)
        {
            m_bullets[i].m_Free = false;
            m_bullets[i].m_X = m_X +m_Rect.width()*0.5-10;
            m_bullets[i].m_Y = m_Y - 25 ;
            break;
        }
    }
}

