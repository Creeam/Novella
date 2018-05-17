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
    int size = width/5 + width / 8;
    for(unsigned int i = 0; i < VecOfPersons.size();++i)
    {
        VecOfPersons[i]->setPixmap(persons[i].scaled(size,height,Qt::IgnoreAspectRatio));
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
        //numOfPersosns = 1;
        //persons = new QPixmap[numOfPersosns];
        //persons[0].load(":/persons/persons/dd.png");

        ui->textEdit_Text->setText( "Эй, дружище не подольешь вина?");
        BackgroundImg.load(":/background/background/tavern.jpg");

        ui->textEdit_names->setText("Вы");
    }
        break;

    case 1:
    {

        numOfPersosns = 1;
        persons = new QPixmap[numOfPersosns];
        persons[0].load(":/persons/persons/dd.png");

        ui->textEdit_names->setText("Трактирщик");
        BackgroundImg.load(":/background/background/tavern.jpg");
        ui->textEdit_Text->setText("Могу подлить. Каким ветром тебя родной занесло во владения бородатой леди? (бульк-бульк)");

    }
        break;
    case 2:
    {

        numOfPersosns = 1;
        persons = new QPixmap[numOfPersosns];
        persons[0].load(":/persons/persons/dd.png");

        BackgroundImg.load(":/background/background/tavern.jpg");
        ui->textEdit_names->setText("Вы");
        ui->textEdit_Text->setText("Ну, в ее то владения, хвала богам, меня пока не занесло.");


    }
        break;
    case 3:
    {
        numOfPersosns = 1;
        persons = new QPixmap[numOfPersosns];
        persons[0].load(":/persons/persons/dd.png");

        BackgroundImg.load(":/background/background/tavern.jpg");
        ui->textEdit_names->setText("Трактирщик");
        ui->textEdit_Text->setText("На островах голубого пламени и окрест, все ей принадлежит.");

    }
        break;
    case 4:
    {

        numOfPersosns = 1;
        persons = new QPixmap[numOfPersosns];
        persons[0].load(":/persons/persons/dd.png");
        BackgroundImg.load(":/background/background/tavern.jpg");
        ui->textEdit_names->setText("Вы");
        ui->textEdit_Text->setText("Я думал Гангпланку…");

    }
        break;
    case 5:
    {

        numOfPersosns = 1;
        persons = new QPixmap[numOfPersosns];
        persons[0].load(":/persons/persons/dd.png");
        BackgroundImg.load(":/background/background/tavern.jpg");
        ui->textEdit_names->setText("трактирщик");
        ui->textEdit_Text->setText("Даже и сам король пиратов, я тебе скажу. Леди властвует над всеми моряками и утопленниками.");

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
