#ifndef GAMESTATUS_H
#define GAMESTATUS_H

#include <QMainWindow>
#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

//#include "chessboard.h"


namespace Ui {
class GameStatus;
}

class GameStatus : public QDialog
{
    Q_OBJECT

public:
    explicit GameStatus(QWidget *parent = 0);
    ~GameStatus();



private slots:
    void on_newgame_clicked();
    void on_goback_clicked();


private:
    Ui::GameStatus *ui;
//    chessboard chessboard;

};

#endif // GAMESTATUS_H
