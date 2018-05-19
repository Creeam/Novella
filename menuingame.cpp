#include "menuingame.h"
#include "ui_menuingame.h"
#include "game.h"

#include <QPixmap>

MenuInGame::MenuInGame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuInGame)
    {
        ui->setupUi(this);
        timer = new QTimer();
        connect(timer,QTimer::timeout,this,&MenuInGame::MakeWindow);
        timer->start(1000/100);
    }

MenuInGame::~MenuInGame()
{
    delete ui;
}

void MenuInGame::MakeWindow()
{
    ui->Background->resize(ui->MainWindow->width(),ui->MainWindow->height());
    ui->Background->move(0,0);
    ui->Background->hide();


}

void MenuInGame::on_pushButton_Return_clicked()
{
    emit Return();
    delete timer;
    delete ui;
    delete this;

}

void MenuInGame::on_pushButton_Exit_clicked()
{
    QApplication::quit();
}

void MenuInGame::on_pushButton_4_clicked()
{
    emit backToMainMenu();
}
