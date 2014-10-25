#include <QApplication>
#include <QFont>
#include "timer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font("Î¢ÈíÑÅºÚ", 24, QFont::Normal, false);
    a.setFont (font);
    Timer w;
    w.resize(640, 320);
    w.show();

    return a.exec();
}
