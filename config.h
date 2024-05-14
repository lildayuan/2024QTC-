#ifndef CONFIG_H
#define CONFIG_H

#define GAME_WIDTH  512  //宽度
#define GAME_HEIGHT 768  //高度
#define GAME_TITLE "科幻风飞机大战 v3.0" //标题  后期改这里
#define GAME_RES_PATH  "./plane.rcc" //rcc文件路径 后期改这里
#define GAME_ICON  ":/res/app.ico"  //后期改这里
#define GAME_RATE 10

#define MAP_PATH  ":/res/6af74b135fac912d94013a47873bdbf.jpg"//地图图片路径 后期改这里
#define MAP_SCROLL_SPEED 2  //地图滚动速度

#define HERO_PATH ":/res/heroplane.png"

#define BULLET_PATH ":/res/bullet_9.png"   //子弹图片路径
#define BULLET_SPEED 5  //子弹移动速度
#define BULLET_NUM 400   //弹匣中子弹总数
#define BULLET_INTERVAL 50 //发射子弹时间间隔

#define ENEMY_PATH  ":/res/img-plane_3.png"  //敌机资源图片
#define ENEMY_SPEED 5  //敌机移动速度
#define ENEMY_NUM   20  //敌机总数量
#define ENEMY_INTERVAL  30  //敌机出场时间间隔

#define BOMB_PATH  ":/res/bomb-%1.png"   //爆炸资源图片
#define BOMB_NUM  20     //爆炸数量
#define BOMB_MAX  7      //爆炸图片最大索引
#define BOMB_INTERVAL 20   //爆炸切图时间间隔

#define BUTTON_WIDTH 100 // 按钮宽度
#define BUTTON_HEIGHT 30  // 按钮高度
#define SPACING 10    // 按钮之间的间距

#define SOUND_BACKGROUND ":/res/bg.wav"
#define SOUND_BOMB ":/res/bomb.wav"
#define GAME_OVER_SOUND "/res/Defeated.wav"


#define Startpicture_Path ":/res/start.jpg" //开始界面图片

#endif // CONFIG_H
