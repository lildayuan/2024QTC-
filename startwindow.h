#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "mainscene.h"

class StartWindow : public QWidget {
    Q_OBJECT

public:
    StartWindow(QWidget *parent = nullptr);
    ~StartWindow();
    MainScene gameScene;

    QPixmap m_start;

    int m_start_Y;

    void paintEvent(QPaintEvent *event);
signals:
    void startGame();
    void quitGame();
};

#endif // STARTWINDOW_H
