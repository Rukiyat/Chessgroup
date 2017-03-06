#ifndef NEWPLAYER_H
#define NEWPLAYER_H

#include <QDialog>
#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "gamestatus.h"

namespace Ui {
class Newplayer;
}

class Newplayer : public QDialog
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
    explicit Newplayer(QWidget *parent = 0);
    ~Newplayer();

private slots:
     void on_create_clicked();


     void on_goback_clicked();

private:
    Ui::Newplayer *ui;
    GameStatus gamestatus;

};

#endif // NEWPLAYER_H
