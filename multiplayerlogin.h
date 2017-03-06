#ifndef MULTIPLAYERLOGIN_H
#define MULTIPLAYERLOGIN_H

#include <QDialog>
#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "gamestatus.h"

namespace Ui {
class MultiplayerLogin;
}

class MultiplayerLogin : public QDialog
{
    Q_OBJECT

public:
        QSqlDatabase pdatabase;
           void connClose()
           {
               pdatabase.close();
               pdatabase.removeDatabase(QSqlDatabase::defaultConnection);
           }

           bool connOpen()
           {
               pdatabase=QSqlDatabase::addDatabase("QSQLITE");
               pdatabase.setDatabaseName("/Users/Diana/Documents/database/chessproject.db");

               if(!pdatabase.open()){
                   qDebug()<<("Failed to open the database");
                   return false;
               }
               else{
                   qDebug()<<("Connected...");
                   return true;
               }
           }

public:
    explicit MultiplayerLogin(QWidget *parent = 0);
    ~MultiplayerLogin();

private slots:
        void on_goback_clicked();
        void on_multiplayerenter_clicked();

private:
    Ui::MultiplayerLogin *ui;
    GameStatus gamestatus;


};

#endif // MULTIPLAYERLOGIN_H
