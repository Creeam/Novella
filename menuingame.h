#ifndef MENUINGAME_H
#define MENUINGAME_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class MenuInGame;
}

class MenuInGame : public QWidget
{
    Q_OBJECT

public:
    explicit MenuInGame(QWidget *parent = 0);
    ~MenuInGame();

    bool isCreate;

signals:
    void Return();

private slots:
    void MakeWindow();

    void on_pushButton_Return_clicked();

    void on_pushButton_Exit_clicked();

private:
    Ui::MenuInGame *ui;

    QTimer* timer;
};

#endif // MENUINGAME_H
