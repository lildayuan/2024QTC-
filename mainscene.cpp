#include "mainscene.h"
#include "./ui_mainscene.h"
#include"config.h"
#include<QIcon>
#include<QPainter>
#include<QDebug>
#include<ctime>

MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
    initScene();
    playGame();

}

MainScene::~MainScene()
{
    delete ui;
}

void MainScene::initScene()
{
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    setWindowTitle(GAME_TITLE);

    setWindowIcon(QIcon(GAME_ICON));

    m_Timer.setInterval(GAME_RATE);

    srand((unsigned int)time(NULL));
}

void MainScene::playGame()
{
    m_Timer.start();

    connect(&m_Timer , &QTimer::timeout,[=](){
        enemyToScene();
        updatePosition();
        update();
        collisionDetection();
    });
}

void MainScene::updatePosition()
{
    m_map.mapPosition();
    m_hero.shoot();
    for(int i = 0; i< BULLET_NUM;i++){
        if(!m_hero.m_bullets[i].m_Free){
            m_hero.m_bullets[i].updatePosition();
        }
    }
    for(int i =0;i<ENEMY_NUM;i++){
        if(m_enemys[i].m_Free == false){
            m_enemys[i].updatePosition();
        }
    }
}

void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    // 绘制背景地图
    painter.drawPixmap(0, m_map.m_map1_posY, m_map.m_map1);
    painter.drawPixmap(0, m_map.m_map2_posY, m_map.m_map2);

    // 绘制英雄飞机
    painter.drawPixmap(m_hero.m_X, m_hero.m_Y, m_hero.m_Plane);

    for(int i=0;i<BULLET_NUM;i++){
        painter.drawPixmap(m_hero.m_bullets[i].m_X,m_hero.m_bullets[i].m_Y,m_hero.m_bullets[i].m_Bullet);
    }

    for(int i =0;i<ENEMY_NUM;i++){
        if(m_enemys[i].m_Free == false){
            painter.drawPixmap(m_enemys[i].m_X,m_enemys[i].m_Y,m_enemys[i].m_enemy);
        }
    }
}

void MainScene::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->position().x() - m_hero.m_Rect.width()*0.5;
    int y = event->position().y() - m_hero.m_Rect.height()*0.5;


    //边界检测
    if(x <= 0 )
    {
        x = 0;
    }
    if(x >= GAME_WIDTH - m_hero.m_Rect.width())
    {
        x = GAME_WIDTH - m_hero.m_Rect.width();
    }
    if(y <= 0)
    {
        y = 0;
    }
    if(y >= GAME_HEIGHT - m_hero.m_Rect.height())
    {
        y = GAME_HEIGHT - m_hero.m_Rect.height();
    }
    m_hero.setPosition(x,y);
}

void MainScene::enemyToScene()
{
    m_recorder++;
    if(m_recorder<ENEMY_INTERVAL){
        return;
    }

    m_recorder = 0;

    for(int i = 0 ; i< ENEMY_NUM;i++)
    {
        if(m_enemys[i].m_Free)
        {
            //敌机空闲状态改为false
            m_enemys[i].m_Free = false;
            //设置坐标
            m_enemys[i].m_X = rand() % (GAME_WIDTH - m_enemys[i].m_Rect.width());
            m_enemys[i].m_Y = -m_enemys[i].m_Rect.height();
            break;
        }
    }
}

void MainScene::collisionDetection()
{
    //遍历所有非空闲的敌机
    for(int i = 0 ;i < ENEMY_NUM;i++)
    {
        if(m_enemys[i].m_Free)
        {
            //空闲飞机 跳转下一次循环
            continue;
        }

        //遍历所有 非空闲的子弹
        for(int j = 0 ; j < BULLET_NUM;j++)
        {
            if(m_hero.m_bullets[j].m_Free)
            {
                //空闲子弹 跳转下一次循环
                continue;
            }

            //如果子弹矩形框和敌机矩形框相交，发生碰撞，同时变为空闲状态即可
            if(m_enemys[i].m_Rect.intersects(m_hero.m_bullets[j].m_Rect))
            {
                m_enemys[i].m_Free = true;
                m_hero.m_bullets[j].m_Free = true;
            }
        }
    }
}

