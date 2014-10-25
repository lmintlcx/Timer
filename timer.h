#ifndef TIMER_H
#define TIMER_H

#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QPushButton>
#include <QTimer>

#include <windows.h>

using namespace std;

class Timer : public QWidget
{
    Q_OBJECT

public:
    Timer(QWidget *parent = 0);
    ~Timer();

    QTimer *intimer;
    QLabel *label00;
    QLabel *label10;
    QLabel *label20;
    QLabel *label30;
    QLabel *label40;
    QLabel *label50;
    QLabel *label01;
    QLabel *label11;
    QLabel *label21;
    QLabel *label31;
    QLabel *label41;
    QLabel *label51;
    QVBoxLayout *mainLayout;
    QGridLayout *upLayout;
    QHBoxLayout *downLayout;
    QPushButton *startButton, *endButton, *stopButton, *resetButton;

    LARGE_INTEGER litmp;
    LONGLONG startCounter, endCounter, totalTime;
    double tCounter, tFrequency, tTime;

public slots:
    void timerStart();
    void timerEnd();
    void timerStop();
    void timerReset();

};

#endif // TIMER_H
