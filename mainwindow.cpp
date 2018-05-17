#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
        timer = new QTimer();
        connect(timer, &QTimer::timeout, this, &MainWindow::MakeWindow);
        timer->start(1000/100);
    }

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::MakeWindow()
{
    ui->Background->resize(ui->MainWindo->width(),ui->MainWindo->height());
    ui->Background->move(0,0);
    QPixmap background(":/MainMenu/Menu/fonmenu.jpg");
    ui->Background->setPixmap(background.scaled(ui->Background->width(),ui->Background->height(),Qt::IgnoreAspectRatio));

    ui->Buttons->resize((ui->Background->width()*22)/100, ui->Background->height() * 55 / 100);
    ui->Buttons->move(ui->Background->width()/11,ui->Background->height()/2 - ui->Buttons->height()/2 + ui->Buttons->height()/15);

}

void MainWindow::on_pushButton_NewGame_clicked()
{
    game = new Game();
    game->showFullScreen();
    hide();
}

void MainWindow::on_pushButton_Exit_clicked()
{
    QApplication::quit();
}
