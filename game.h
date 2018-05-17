#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <Qtimer>
#include <QPixmap>
#include <QLabel>
#include <QBoxLayout>
#include <vector>


#include "blackout.h"
#include "menuingame.h"

namespace Ui {
class Game;
}

class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = 0);
    ~Game();

signals:
    void start();

private slots:
    void on_pushButton_menu_clicked();

    void makeScene();

    void on_clicedZone_clicked();

    void MenuWindowIn();

    void returnToGame();

private:
    Ui::Game *ui;
    QTimer* timer;
    QTimer* t;
    int temp;
    int numOfScene;
    unsigned int numOfPersosns;
    QPixmap BackgroundImg;
    QPixmap* persons;
    QBoxLayout* a;
    std::vector<QLabel*> VecOfPersons;

    Blackout*  blackout;
    MenuInGame* menu;

    int currentWidth;
    int currentHeight;

    void ChangeInterfacePosition(int width, int height);
    void ChangeBackground(int width, int height);
    void ChangePersons(int width, int height);
    void ChangeScene();
    void update();





};

#endif // GAME_H
