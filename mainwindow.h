#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void MakeWindow();

    void on_pushButton_NewGame_clicked();

    void on_pushButton_Exit_clicked();

private:
    Ui::MainWindow *ui;
    Game* game;
    QTimer* timer;
};

#endif // MAINWINDOW_H
