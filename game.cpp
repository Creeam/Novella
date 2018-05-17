#include "game.h"
#include "ui_game.h"
#include "menuingame.h"
#include <iostream>
#include <QMessageBox>
#include <QHBoxLayout>


Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game)
    {
        ui->setupUi(this);
        numOfPersosns = 0;
        numOfScene = 0;

        blackout = new Blackout(this);
        blackout->hide();
        blackout->NeedBlackout = false;

        currentWidth = ui->MainWindow->width();
        currentHeight = ui->MainWindow->height();

        //isUpdate = true;

        timer = new QTimer();
        connect(timer, &QTimer::timeout, this, &Game::makeScene);
        timer->start(1);
        ChangeScene();

    }

    Game::~Game()
    {
        delete ui;
    }

void Game::ChangeInterfacePosition(int width, int height)
{
    ui->groupBox_Interface->resize(width, height);
    ui->groupBox_Interface->move(ui->MainWindow->width()/2 - width/2, ui->MainWindow->height() - height);
}

void Game::ChangeBackground(int width, int height)
{
    ui->Background->resize(width,height);
    ui->Background->move(0,0);
    ui->Background->setPixmap(BackgroundImg.scaled(width,height,Qt::IgnoreAspectRatio));
}

void Game::ChangePersons(int width, int height)
{
    if(numOfPersosns != VecOfPersons.size())
    {
        VecOfPersons.clear();
        for( int i = 0; i < numOfPersosns; ++i )
        {
            VecOfPersons.push_back(new QLabel());
        }
    }
    int size = width/5;
    for(unsigned int i = 0; i < VecOfPersons.size();++i)
    {
        VecOfPersons[i]->setPixmap(persons[i].scaled(size,height,Qt::KeepAspectRatio));
        VecOfPersons[i]->setMinimumSize(size,height);
        VecOfPersons[i]->setMaximumSize(size,height);
        ui->PersonsLayout->addWidget(VecOfPersons[i]);
    }


}


void Game::makeScene()
{

    int width = ui->MainWindow->width();
    int height = ui->MainWindow->height();

    if((width != currentWidth) || (height != currentHeight))
    {
        ui->PersonsGroupBox->resize(width,height);
        ui->PersonsGroupBox->move(0,0);

        ChangeInterfacePosition(width*80/100, height*40/100);
        ChangeBackground(width,height);
        ChangePersons(width,height);

        ui->clicedZone->resize(width,height - ui->groupBox_BottomMenu->height() - ui->groupBox_BottomMenu->height()/3);
        ui->clicedZone->move(0,0);

        currentWidth = width;
        currentHeight = height;

    }
   if(blackout->NeedBlackout)
   {
       blackout->resize(ui->MainWindow->width(),ui->MainWindow->height());
       blackout->move(0,0);
       blackout->show();
   }

}

void Game::update()
{
    ChangeBackground(currentWidth,currentHeight);
    ChangePersons(currentWidth,currentHeight);
}


void Game::ChangeScene()
{
    switch (numOfScene++) {
    case 0:
    {
        numOfPersosns = 1;
        persons = new QPixmap[numOfPersosns];
        persons[0].load(":/persons/img/boy.png");

        ui->textEdit_Text->setText( "Действие происходит в королевстве Альда, где вместе живут маги и люди. "
                                 "До того, как появилось это королевство на этой территории располагалось другое государство – Нурия,"
                                 " правила там Инквизиция. Однажды был найден минерал, обладающий необыч-ными свойствами:"
                                 " стоило полить его водой, и он начинал светиться,"
                                 " что было полезно в обычном быту и многими другими свойствами");
        BackgroundImg.load(":/background/background/Tavern.png");

        ui->textEdit_names->setText("Алеша");
    }
        break;

    case 1:
    {
        ui->textEdit_names->setText("Алеша, Иван");
        BackgroundImg.load(":/background/background/Tavern.png");

    }
        break;
    case 2:
    {
        BackgroundImg.load(":/background/background/Tavern.png");
        ui->textEdit_names->setText("Иван");

    }
        break;
    default:
        break;
    }
    update();
}

/**
 * @brief Game::on_clicedZone_clicked vpmvbdbdfxdfvdfvdf
 * @param a -
 * @throws sfdsfgdfsg
 * @return none
 */
void Game::on_clicedZone_clicked()
{
    ChangeScene();
}

/**
 * @brief Game::on_pushButton_menu_clicked
 */
void Game::on_pushButton_menu_clicked()
{
    blackout->NeedBlackout = true;
    int width = ui->MainWindow->width();
    int height = ui->MainWindow->height();

    menu = new MenuInGame(this);
    menu->show();
    connect(menu, &MenuInGame::Return,this,&Game::returnToGame);
    menu->resize(width/3,height);
    menu->move(-menu->width(),0);
    temp = -menu->width();
    t = new QTimer();
    connect(t,&QTimer::timeout,this,&Game::MenuWindowIn);
    t->start(1);


}

void Game::MenuWindowIn()
{
    int speed = ui->MainWindow->width()/56;
    if(temp >= 0)
    {
        menu->move(0,0);
        disconnect(t,&QTimer::timeout,this,&Game::MenuWindowIn);
        delete t;
    }
    else
    {
        menu->move(temp,0);
        temp += speed;
    }
}

void Game::returnToGame()
{
    blackout->NeedBlackout = false;
    blackout->hide();
}
