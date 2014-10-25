#include "timer.h"

Timer::Timer(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Qt Timer Demo");

    label00 = new QLabel("Start Counter");
    label10 = new QLabel("End Counter");
    label20 = new QLabel("Total Counter");
    label30 = new QLabel("Frequency");
    label40 = new QLabel("Time(us)");
    label50 = new QLabel("Time(s)");
    label01 = new QLabel("0");
    label11 = new QLabel("0");
    label21 = new QLabel("0");
    label31 = new QLabel("0");
    label41 = new QLabel("0");
    label51 = new QLabel("0");

    intimer = new QTimer();
    intimer->setInterval(1);

    startCounter = 0;
    endCounter = 0;
    totalTime = 0;
    tCounter = 0;
    tFrequency = 0;
    tTime = 0;

    startButton = new QPushButton("Start");
    endButton = new QPushButton("End");
    stopButton = new QPushButton("Stop");
    resetButton = new QPushButton("Reset");

    upLayout = new QGridLayout();
    upLayout->addWidget(label00, 0, 0, 1, 1);
    upLayout->addWidget(label10, 1, 0, 1, 1);
    upLayout->addWidget(label20, 2, 0, 1, 1);
    upLayout->addWidget(label30, 3, 0, 1, 1);
    upLayout->addWidget(label40, 4, 0, 1, 1);
    upLayout->addWidget(label50, 5, 0, 1, 1);
    upLayout->addWidget(label01, 0, 1, 1, 1);
    upLayout->addWidget(label11, 1, 1, 1, 1);
    upLayout->addWidget(label21, 2, 1, 1, 1);
    upLayout->addWidget(label31, 3, 1, 1, 1);
    upLayout->addWidget(label41, 4, 1, 1, 1);
    upLayout->addWidget(label51, 5, 1, 1, 1);

    downLayout = new QHBoxLayout();
    downLayout->addWidget(startButton);
    downLayout->addWidget(endButton);
    downLayout->addWidget(stopButton);
    downLayout->addWidget(resetButton);

    mainLayout = new QVBoxLayout();
    mainLayout->addLayout(upLayout);
    mainLayout->addLayout(downLayout);

    this->setLayout(mainLayout);

    connect(startButton, SIGNAL(clicked()), this, SLOT(timerStart()));
    connect(endButton, SIGNAL(clicked()), this, SLOT(timerEnd()));
    connect(stopButton, SIGNAL(clicked()), this, SLOT(timerStop()));
    connect(resetButton, SIGNAL(clicked()), this, SLOT(timerReset()));
}

Timer::~Timer()
{
}


void Timer::timerStart()
{
    QueryPerformanceFrequency(&litmp);
    tFrequency = (double)litmp.QuadPart;

    QueryPerformanceCounter(&litmp);
    startCounter = litmp.QuadPart;

    intimer->start();
    connect(intimer, SIGNAL(timeout()), this, SLOT(timerEnd()));
}

void Timer::timerEnd()
{
    QueryPerformanceCounter(&litmp);
    endCounter = litmp.QuadPart;

    tCounter = (double)(endCounter - startCounter);
    tTime = tCounter / tFrequency;
    totalTime = tTime * 1000000;

    label01->setText(QString::number(startCounter, 10));
    label11->setText(QString::number(endCounter, 10));
    label21->setText(QString::number(qulonglong(tCounter), 10));
    label31->setText(QString::number(qulonglong(tFrequency), 10));
    label41->setText(QString::number(totalTime, 10));
    label51->setText(QString::number(qulonglong(tTime), 10));

}

void Timer::timerStop()
{
    timerEnd();
    intimer->stop();
}

void Timer::timerReset()
{
    timerStop();

    startCounter = 0;
    endCounter = 0;
    totalTime = 0;
    tCounter = 0;
    tFrequency = 0;
    tTime = 0;

    label01->setText("0");
    label11->setText("0");
    label21->setText("0");
    label31->setText("0");
    label41->setText("0");
    label51->setText("0");
}
