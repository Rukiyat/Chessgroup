#ifndef LOGINUSER_H
#define LOGINUSER_H

#include <QDialog>
#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "gamestatus.h"


namespace Ui {
class loginuser;
}

class loginuser : public QDialog
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
    explicit loginuser(QWidget *parent = 0);
    ~loginuser();

private slots:
     void on_enter_clicked();

     void on_gobackbutton_clicked();

private:
    Ui::loginuser *ui;
    GameStatus gamestatus;

};

#endif // LOGINUSER_H
