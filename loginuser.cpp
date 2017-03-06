#include "LoginUser.h"
#include "ui_loginuser.h"
#include <QMessageBox>
#include "ScreenWindow.h"


loginuser::loginuser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginuser)
{
    ui->setupUi(this);
}

loginuser::~loginuser()
{
    delete ui;
}

void loginuser::on_enter_clicked()
{
    QString username, password;
    username=ui->name->text();
    password=ui->passkey->text();
    connOpen();
    QSqlQuery qry;

    if(qry.exec("select * from userdata where Password ='"+password+"' and Username ='"+username+"'"))
    {
        int count=0;
        while(qry.next())
        {
             count++;
        }
        if (count==1)
        {
            this->hide();
            gamestatus.show();
            connClose();
         }
        if (count<1)
         {
             QMessageBox message;
             message.setText("Sorry!!. The details entered does not exist, please try again.");
             message.exec();
             connClose();
         }
     }



}

void loginuser::on_gobackbutton_clicked()
{
    this->hide();
    screenwindow *mainscreen;
    mainscreen = new screenwindow(this);
    mainscreen -> show();
}

