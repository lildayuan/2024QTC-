#include "startwindow.h"
#include "mainscene.h"
#include <QApplication>
#include <QResource>
#include "config.h"
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QResource::registerResource(GAME_RES_PATH);

    StartWindow startWindow;
    MainScene w;

    QObject::connect(&startWindow, &StartWindow::startGame, [&]() {
        w.show();
        startWindow.hide();
    });

    QObject::connect(&startWindow, &StartWindow::quitGame, [&]() {
        QApplication::quit();
    });

    startWindow.show();
    return a.exec();
}
