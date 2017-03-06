#include "ScreenWindow.h"
#include "ui_screenwindow.h"

screenwindow::screenwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::screenwindow)
{
    ui->setupUi(this);
}

screenwindow::~screenwindow()
{
    delete ui;
}

void screenwindow::on_singleplayer_clicked()
{
    if(ui->existinguser->isChecked())
    {
       this->hide();
       loginuser.show();
     }
    else if(ui->newuser->isChecked())
    {
        this->hide();
        newplayer.show();
    }

}



void screenwindow::on_multiplayer_clicked()
{
    if(ui->existinguser->isChecked())
    {
       this->hide();
       multiplayerLogin = new MultiplayerLogin(this);
       multiplayerLogin->show();
     }
    else if(ui->newuser->isChecked())
    {
        this->hide();
        newplayer.show();

    }

}
