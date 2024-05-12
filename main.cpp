#include "mainscene.h"

#include <QApplication>
#include <QDebug>
#include<QResource>

#include"config.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //对于是否成功的判断 一开始老是出错 用这个方法可以检测

    QResource::registerResource(GAME_RES_PATH);
    MainScene w;
    w.show();
    return a.exec();
}

