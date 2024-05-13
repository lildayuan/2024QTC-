#include "startwindow.h"
#include "config.h"
#include "mainscene.h"
#include<QApplication>

StartWindow::StartWindow(QWidget *parent) : QWidget(parent) {
    setFixedSize(GAME_WIDTH, GAME_HEIGHT);
    setWindowTitle("飞机荣耀 - 开始界面");

    QPushButton *startButton = new QPushButton("开始游戏", this);
    QPushButton *quitButton = new QPushButton("退出游戏", this);

    QString buttonStyle = "QPushButton {"
                          "   color: white;"
                          "   background-color: #8B0000;"
                          "   border-style: outset;"
                          "   border-width: 2px;"
                          "   border-radius: 10px;"
                          "   border-color: beige;"
                          "   font: bold 14px;"
                          "   padding: 6px;"
                          "}"
                          "QPushButton:hover {"
                          "   background-color: #FF6347;"
                          "}"
                          "QPushButton:pressed {"
                          "   background-color: #CD5C5C;"
                          "   border-style: inset;"
                          "}";

    startButton->setStyleSheet(buttonStyle);
    quitButton->setStyleSheet(buttonStyle);

    startButton->setGeometry((GAME_WIDTH - BUTTON_WIDTH) / 2, (GAME_HEIGHT - 2 * BUTTON_HEIGHT - SPACING) / 2, BUTTON_WIDTH, BUTTON_HEIGHT);
    quitButton->setGeometry((GAME_WIDTH - BUTTON_WIDTH) / 2, (GAME_HEIGHT - 2 * BUTTON_HEIGHT - SPACING) / 2 + BUTTON_HEIGHT + SPACING, BUTTON_WIDTH, BUTTON_HEIGHT);

    gameScene.hide();

    connect(startButton, &QPushButton::clicked, &gameScene, &MainScene::startGame);
    connect(startButton, &QPushButton::clicked, &gameScene, &QWidget::show);
    connect(startButton, &QPushButton::clicked, this, &QWidget::hide);

    connect(quitButton, &QPushButton::clicked, this, &QApplication::quit);
}

StartWindow::~StartWindow() {}

