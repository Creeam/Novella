#include "blackout.h"
#include "ui_blackout.h"

Blackout::Blackout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Blackout)
{
    ui->setupUi(this);
}

Blackout::~Blackout()
{
    delete ui;
}


