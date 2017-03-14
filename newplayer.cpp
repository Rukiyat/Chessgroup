#include "newplayer.h"
#include "ui_newplayer.h"
#include <QMessageBox>
#include "ScreenWindow.h"

Newplayer::Newplayer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Newplayer)
{
    ui->setupUi(this);
}

Newplayer::~Newplayer()
{
    delete ui;
}

void Newplayer::on_create_clicked()

{
    QString forename, surname, newpassword, email, newusername, reenterpassword;
    forename=ui->forename->text();
    surname=ui->surname->text();
    newpassword=ui->newpassword->text();
    reenterpassword=ui->reenterpassword->text();
    email=ui->email->text();
    newusername=ui->newusername->text();
    if (newpassword == reenterpassword)
    {

        connOpen();
        QSqlQuery qry;
        qry.prepare("select * from userprimarydata where Forename='"+forename+"', Surname='"+surname+"', Password ='"+newpassword+"', Email='"+email+"', Username ='"+newusername+"'");
        qry.prepare("INSERT INTO userprimarydata (Forename, Surname, Password, Email, Username) VALUES ('"+forename+"','"+surname+"','"+newpassword+"','"+email+"','"+newusername+"')");
        qry.exec();

        QSqlQuery qry2;
        qry2.prepare("select * from userdata where Password ='"+newpassword+"', Username ='"+newusername+"'");
        qry2.prepare("INSERT INTO userdata(Username, Password) VALUES ('"+newusername+"','"+newpassword+"')");
        qry2.exec();
        this->hide();
        connClose();

        this->hide();
        QMessageBox Welcome;
        Welcome.setText

                       (" ******     **" "\n"
                       "**********   **" "\n"
                     "***            **" "\n"
                   " ***             **            ****       ****        ****   ""\n"
                    "***             **          ********   ***  ***    ***  ***" "\n"
                   " ***             ** ****    ***    *** ***         ***        " "\n"
                    "***             ****  **   **********   ******      ******  " "\n"
                    " ***            ***    **  ***             *****       ***** ""\n"
                       "**********   **     **   ****       ***   **    ***   ** ""\n"
                       " *******     **     **     ****       *****       ***** " "\n"
                       "                                                        ""\n"
                                   " WELCOME TO CAPTURE THE ENEMY!!!                 ");

        Welcome.exec();
        gamestatus.show();
    }



    else if (newpassword != reenterpassword)
    {
        QMessageBox message;
        message.setText("Sorry!!. Password doesn't match, please try again.");
        message.exec();
    }


}



void Newplayer::on_goback_clicked()
{
    this->hide();
    screenwindow *newusermainscreen;
    newusermainscreen = new screenwindow(this);
    newusermainscreen -> show();
}
