#ifndef GAMEPAD_H
#define GAMEPAD_H
#include <QtCore>
#include <QDebug>
#include <SDL2/SDL.h>


class Gamepad:public QObject
{
    //Q_OBJECT
    Q_OBJECT

public:
    Gamepad();
    void openJoystick();

signals:
    void sendJoystick(QVector<int16_t> value);

private:
    SDL_Joystick *joystick;
    QTimer *timer;

public slots:
    void updateJoystick();
};

#endif // GAMEPAD_H
