#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QTimer>
#include<QMessageBox>
#include"heroplane.h"
#include"map.h"
#include<QMouseEvent>
#include"enemyplane.h"
#include"bomb.h"
#include "qmediaplayer.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainScene;
}
QT_END_NAMESPACE

class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();
    void initScene();//初始化场景

    void playGame();

    void updatePosition();

    void paintEvent(QPaintEvent *event);

    void mouseMoveEvent(QMouseEvent *);

    void enemyToScene();

    void collisionDetection();

    void startGame();

    void GameOver();

    EnemyPlane m_enemys[ENEMY_NUM];

    int m_recorder;

    Map m_map;

    HeroPlane m_hero;

    QTimer m_Timer;

    Bomb m_bombs[BOMB_NUM];



private:
    Ui::MainScene *ui;
};
#endif // MAINSCENE_H
