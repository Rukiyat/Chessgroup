#include "multiplayerlogin.h"
#include "ui_multiplayerlogin.h"
#include "ScreenWindow.h"
#include "gamestatus.h"
#include <QMessageBox>

QString player1username, player1password,player2username, player2password;

MultiplayerLogin::MultiplayerLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MultiplayerLogin)
{
    ui->setupUi(this);

}

MultiplayerLogin::~MultiplayerLogin()
{
    delete ui;
}



void MultiplayerLogin::on_goback_clicked()
{
    this->hide();
    screenwindow *loginmainscreen;
    loginmainscreen = new screenwindow(this);
    loginmainscreen -> show();
}



void MultiplayerLogin::on_multiplayerenter_clicked()
{

    player1username=ui->player1username->text();
    player1password=ui->player1password->text();
    player2username=ui->player2username->text();
    player2password=ui->player2password->text();
    connOpen();
    QSqlQuery qry;
    QSqlQuery qry2;
    if(qry.exec("select * from userdata where Password ='"+player1password+"' and Username ='"+player1username+"'"))
    {
       if(qry2.exec("select * from userdata where Password ='"+player2password+"' and Username ='"+player2username+"'"))
       {
          int count1=0;
          while(qry.next())
          while(qry2.next())
          {
             count1++;
          }
        if (count1==1)
        {
            this->hide();
            gamestatus.show();

         }
        if (count1<1)
        {
             QMessageBox messageout;
             messageout.setText("Sorry!!. Player-details does not exist, please try again.");
             messageout.exec();
             connClose();

        }

       }

    }

}



