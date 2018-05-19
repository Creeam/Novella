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
        for( unsigned int i = 0; i < numOfPersosns; ++i )
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
        ui->textEdit_Text->setText( "Эй, дружище не подольешь вина?");
        BackgroundImg.load(":/background/background/tavern.jpg");

        ui->textEdit_names->setText("Вы");
    }
        break;

    case 1:
    {

        if(numOfPersosns <= 0)
        {
            numOfPersosns = 1;
            persons = new QPixmap[numOfPersosns];
        }
        numOfPersosns = 1;

        persons[0].load(":/persons/persons/dd.png");

        ui->textEdit_names->setText("Трактирщик");
        BackgroundImg.load(":/background/background/tavern.jpg");
        ui->textEdit_Text->setText("Могу подлить. Каким ветром тебя родной занесло во владения бородатой леди? (бульк-бульк)");

    }
        break;
    case 2:
    {
        if(numOfPersosns <= 0)
        {
            numOfPersosns = 1;
            persons = new QPixmap[numOfPersosns];
        }
        numOfPersosns = 1;
        persons[0].load(":/persons/persons/dd.png");

        BackgroundImg.load(":/background/background/tavern.jpg");
        ui->textEdit_names->setText("Вы");
        ui->textEdit_Text->setText("Ну, в ее то владения, хвала богам, меня пока не занесло.");


    }
        break;
    case 3:
    {
        if(numOfPersosns <= 0)
        {
            numOfPersosns = 1;
            persons = new QPixmap[numOfPersosns];
        }

        numOfPersosns = 1;
        persons[0].load(":/persons/persons/dd.png");

        BackgroundImg.load(":/background/background/tavern.jpg");
        ui->textEdit_names->setText("Трактирщик");
        ui->textEdit_Text->setText("На островах голубого пламени и окрест, все ей принадлежит.");

    }
        break;
    case 4:
    {
        if(numOfPersosns <= 0)
        {
            numOfPersosns = 1;
            persons = new QPixmap[numOfPersosns];
        }
        numOfPersosns = 1;
        persons[0].load(":/persons/persons/dd.png");
        BackgroundImg.load(":/background/background/tavern.jpg");
        ui->textEdit_names->setText("Вы");
        ui->textEdit_Text->setText("Я думал Гангпланку…");

    }
        break;
    case 5:
    {
        if(numOfPersosns <= 0)
        {
            numOfPersosns = 1;
            persons = new QPixmap[numOfPersosns];
        }
        numOfPersosns = 1;
        persons[0].load(":/persons/persons/dd.png");
        BackgroundImg.load(":/background/background/tavern.jpg");
        ui->textEdit_names->setText("Трактирщик");
        ui->textEdit_Text->setText("Даже и сам король пиратов, я тебе скажу. Леди властвует над всеми моряками и утопленниками.");

    }
        break;
    case 6:
    {
        if(numOfPersosns <= 0)
        {
            numOfPersosns = 1;
            persons = new QPixmap[numOfPersosns];
        }
        numOfPersosns = 1;
        persons[0].load(":/persons/persons/dd.png");
        BackgroundImg.load(":/background/background/tavern.jpg");
        ui->textEdit_names->setText("Вы");
        ui->textEdit_Text->setText("Хы-хы. Как по мне никакой разницы, моряки – те же утопленники, только пока живыми прикидываются.");

    }
        break;
    case 7:
    {
        if(numOfPersosns <= 0)
        {
            numOfPersosns = 1;
            persons = new QPixmap[numOfPersosns];
        }
        numOfPersosns = 1;
        persons[0].load(":/persons/persons/dd.png");
        BackgroundImg.load(":/background/background/tavern.jpg");
        ui->textEdit_names->setText("Трактирщик");
        ui->textEdit_Text->setText("Хы-хы. Моряком только этого не говори, родной. Ни то скормят тебя рыбам. Вот вроде той, что ты сейчас уплетаешь.");

    }
        break;
    case 8:
    {
        if(numOfPersosns <= 0)
        {
            numOfPersosns = 1;
            persons = new QPixmap[numOfPersosns];
        }
        numOfPersosns = 1;
        persons[0].load(":/persons/persons/dd.png");
        BackgroundImg.load(":/background/background/tavern.jpg");
        ui->textEdit_names->setText("Вы");
        ui->textEdit_Text->setText("Сердитая рыбка?");
    }
        break;
    case 9:
    {
        if(numOfPersosns <= 0)
        {
            numOfPersosns = 1;
            persons = new QPixmap[numOfPersosns];
        }
        numOfPersosns = 1;
        persons[0].load(":/persons/persons/dd.png");
        BackgroundImg.load(":/background/background/tavern.jpg");
        ui->textEdit_names->setText("Трактирщик");
        ui->textEdit_Text->setText("Вот эта вот, жаренная?"
                                   " Неет, а вот ее подружки, которые еще в море плавают, обглодают человека быстрее, чем он захлебнется.");
    }
        break;
    case 10:
    {
        if(numOfPersosns <= 0)
        {
            numOfPersosns = 1;
            persons = new QPixmap[numOfPersosns];
        }
        numOfPersosns = 1;
        persons[0].load(":/persons/persons/dd.png");
        BackgroundImg.load(":/background/background/tavern.jpg");
        ui->textEdit_names->setText("Вы");
        ui->textEdit_Text->setText("Значит я сейчас не закусываю, а мщу за тех,"
                                   " кто по пути к бородатой леди недосчитался конечностей."
                                   " Ха-ха. Какая приятная месть.");
    }
        break;
    case 11:
    {
        if(numOfPersosns <= 0)
        {
            numOfPersosns = 1;
            persons = new QPixmap[numOfPersosns];
        }
        numOfPersosns = 1;
        persons[0].load(":/persons/persons/dd.png");
        BackgroundImg.load(":/background/background/tavern.jpg");
        ui->textEdit_names->setText("Трактищик");
        ui->textEdit_Text->setText("Я так мыслю, родной."
                                   " Дважды приятная месть."
                                   " Отомстить жаренной рыбине, да еще и за счет доброго мистера Брауна.");
    }
        break;
    case 12:
    {
        if(numOfPersosns <= 0)
        {
            numOfPersosns = 1;
            persons = new QPixmap[numOfPersosns];
        }
        numOfPersosns = 1;
        persons[0].load(":/persons/persons/dd.png");
        BackgroundImg.load(":/background/background/tavern.jpg");
        ui->textEdit_names->setText("Вы");
        ui->textEdit_Text->setText("Верно. За доброго мистера Брауна!"
                                   " Может я даже выслушаю его предложение.");
    }
        break;
    case 13:
    {
        if(numOfPersosns <= 0)
        {
            numOfPersosns = 1;
            persons = new QPixmap[numOfPersosns];
        }
        numOfPersosns = 1;
        persons[0].load(":/persons/persons/dd.png");
        BackgroundImg.load(":/background/background/tavern.jpg");
        ui->textEdit_names->setText("Трактирщик");
        ui->textEdit_Text->setText("Ни в обиду родной, но что-то не похоже, что у тебя больно много предложений было."
                                   " Уж с такой нежностью ты на эту рыбину глядел, будто неделю постился."
                                   " Да и денег видимо у тебя не много.");
    }
        break;
    case 14:
    {
        if(numOfPersosns <= 0)
        {
            numOfPersosns = 1;
            persons = new QPixmap[numOfPersosns];
        }
        numOfPersosns = 1;
        persons[0].load(":/persons/persons/dd.png");
        BackgroundImg.load(":/background/background/tavern.jpg");
        ui->textEdit_names->setText("Вы");
        ui->textEdit_Text->setText("Твоя правда."
                                   " Прощание с Бандлсити вышло несколько скомканным."
                                   " В жизни не подумал бы, что ерлды могут быть такими настырными."
                                   " Целая, чертова толпа разъярённых ерлдов.");
    }
        break;
    case 15:
    {
        if(numOfPersosns <= 0)
        {
            numOfPersosns = 1;
            persons = new QPixmap[numOfPersosns];
        }
        numOfPersosns = 1;
        persons[0].load(":/persons/persons/dd.png");
        BackgroundImg.load(":/background/background/tavern.jpg");
        ui->textEdit_names->setText("Трактирщик");
        ui->textEdit_Text->setText("Мдауж, с малютками шутки плохи."
                                   " Говорят, они мол от великанов произошли."
                                   " Даже 1 ерлд может делов натворить."
                                   " Слыхал историю про ерлдыху с молотком, про которую даже думать страшно."
                                   " Вот то-то и оно родной.");
    }
        break;
    case 16:
    {
        if(numOfPersosns <= 0)
        {
            numOfPersosns = 1;
            persons = new QPixmap[numOfPersosns];
        }
        numOfPersosns = 1;
        persons[0].load(":/persons/persons/dd.png");
        BackgroundImg.load(":/background/background/tavern.jpg");
        ui->textEdit_names->setText("Вы");
        ui->textEdit_Text->setText("Ну короче, пришлось прятаться от них в трюме первой попавшейся посудине."
                                   " Я так устал, что сразу вырубился, а проснулся я уже в открытом, дьявол его дери, море."
                                   " А оставшиеся деньги пришлось отдать капитану, а не то я бы попал на ужин к этой рыбе, а не она ко мне."
                                   " Но выбор у меня есть, старик, если не понравится этот ваш мистер, покажу публике пару карточных фокусов.");
    }
        break;
    case 17:
    {
        if(numOfPersosns <= 0)
        {
            numOfPersosns = 1;
            persons = new QPixmap[numOfPersosns];
        }
        numOfPersosns = 1;
        persons[0].load(":/persons/persons/dd.png");
        BackgroundImg.load(":/background/background/tavern.jpg");
        ui->textEdit_names->setText("Трактирщик");
        ui->textEdit_Text->setText("Только делай ноги сразу, здешний народ не сильно уважает любителей с картами фокусничать."
                                   " Привяжут камень к ногам и в море, прощай родной, не поминай лихом.");
    }
        break;
    case 18:
    {
        if(numOfPersosns <= 0)
        {
            numOfPersosns = 1;
            persons = new QPixmap[numOfPersosns];
        }
        numOfPersosns = 1;
        persons[0].load(":/persons/persons/dd.png");
        BackgroundImg.load(":/background/background/tavern.jpg");
        ui->textEdit_names->setText("Вы");
        ui->textEdit_Text->setText("Пусть только попробуют, запомнят мои фокусы на всю жизнь, это если они выживут.");
    }
        break;
    case 19:
    {
        if(numOfPersosns > 0)
        {
            numOfPersosns = 1;
             persons[0].load("");
        }
        else numOfPersosns = 0;
        BackgroundImg.load(":/background/background/tavern.jpg");
        ui->textEdit_names->setText("Вы");
        ui->textEdit_Text->setText("'Я все удивляюсь что в паре миль от Белджвотера, вдруг такое заведение: приличная публика,"
                                   " достойный выбор вин, да что там говорить, белые скатерти на столах, чистенько тут у них до омерзения."
                                   " Ни тебе свежих трупов в каналах по утрам, не бодрящей вони в порту."
                                   " На улицах вместо бандитов ходит городская стража. Такие все вежливые, что аж блевать хочется.'");
    }
        break;
    case 20:
    {
        if(numOfPersosns > 0)
        {
            numOfPersosns = 1;
             persons[0].load("");
        }
        else numOfPersosns = 0;
        BackgroundImg.load(":/background/background/tavern.jpg");
        ui->textEdit_names->setText("Вы");
        ui->textEdit_Text->setText(" 'Нее Гангплакт, хозяин Белджвотера мыслит, что к чему."
                                   " Давно мог бы прибрать тихую гавань к рукам, но не трогает ее"
                                   ". А все потому, что, здесь сбывают добро, которое его головорезы из чужих трюмов вытащили."
                                   " Если какой купец будет торговать с королем пиратов на прямую, то его репутации конец, а так все приличия соблюдены."
                                   " Как бы независимая, тихая гавань, где любой может свободно торговать или проворачивать мутные дела."
                                   " Ну, может и опасно это, но пусть опасности сухопутные крысы боятся.'");
    }
        break;
    case 21:
    {
        if(numOfPersosns > 0)
        {
            numOfPersosns = 1;
             persons[0].load("");
        }
        else numOfPersosns = 0;
        BackgroundImg.load(":/background/background/tavern.jpg");
        ui->textEdit_names->setText("");
        ui->textEdit_Text->setText("(вы сидите у стойки еще какое-то время, и к вам подбегает мальчик)");
    }
        break;
    case 22:
    {
        if(numOfPersosns > 0)
        {
            numOfPersosns = 1;
             persons[0].load("");
        }
        else numOfPersosns = 0;
        BackgroundImg.load(":/background/background/tavern.jpg");
        ui->textEdit_names->setText("Мальчик");
        ui->textEdit_Text->setText("Мистер, мистер Браун просит вас подняться к нему. Позвольте вас проводить.");
    }
        break;
    case 23:
    {
        if(numOfPersosns > 0)
        {
            numOfPersosns = 1;
             persons[0].load("");
        }
        else numOfPersosns = 0;
        BackgroundImg.load(":/background/background/tavern.jpg");
        ui->textEdit_names->setText("Вы");
        ui->textEdit_Text->setText("Спасибо, сынок.");
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
    connect(menu, &MenuInGame::backToMainMenu,this,&Game::backToMainMenu);
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
