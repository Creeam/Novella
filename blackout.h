#ifndef BLACKOUT_H
#define BLACKOUT_H

#include <QWidget>

namespace Ui {
class Blackout;
}

class Blackout : public QWidget
{
    Q_OBJECT

public:
    explicit Blackout(QWidget *parent = 0);
    ~Blackout();

private:
    Ui::Blackout *ui;

public:
bool NeedBlackout;
};

#endif // BLACKOUT_H
