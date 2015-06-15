#include "gamepad.h"
#include <QtCore>
#include <QDebug>
#include <QVector>


Gamepad::Gamepad()
{
    timer = new QTimer(this);
    timer->setInterval(100);

    connect(timer,SIGNAL(timeout()),this,SLOT(updateJoystick()));
}

void Gamepad::openJoystick()
{
    if(SDL_Init(SDL_INIT_JOYSTICK)==0)
    {
       SDL_JoystickEventState(SDL_DISABLE);

       if(SDL_NumJoysticks()>0)
       {
           joystick = SDL_JoystickOpen(0); //create a gamepad object

           if(joystick)
           {

               //qDebug() << "Gamepad name:" << SDL_JoystickName(0);
               //qDebug() << "Number of Axes:" << SDL_JoystickNumAxes(joystick);
               //qDebug() << "Number of Balls:" << SDL_JoystickNumBalls(joystick);
               //qDebug() << "Number of Hats:" << SDL_JoystickNumHats(joystick);
               //qDebug() << "Number of Buttons:" << SDL_JoystickNumButtons(joystick);


               timer->start();
           }
           else
           {
              qDebug() << "Unable to open gamepad!";
           }
       }
       else
       {
           qDebug() << "Error-No joysticks available!";
       }
    }
    else
    {
            qDebug() << "Error -Unable to initialize SDL!";
    }

}

void Gamepad::updateJoystick()
{
    QVector<int16_t> readJoystick(13);
    int i;
    //int16_t readJoystick[12];

    for(int i=0;i<10;i++)
    {
        readJoystick[i]=0;
    }

    SDL_JoystickUpdate();


    for(i=0;i<10;i++)
    {
      readJoystick[i]=SDL_JoystickGetButton(joystick,i);
      //qDebug() << "Button "<<i<< readJoystick[i];
    }

    i++;
    readJoystick[i]= SDL_JoystickGetAxis(joystick, 0);
    //qDebug() << "Button "<<i<< readJoystick[i];
    i++;
    readJoystick[i]= SDL_JoystickGetAxis(joystick, 1);
    //qDebug() << "Button "<<i<< readJoystick[i];

    emit sendJoystick(readJoystick);

}

