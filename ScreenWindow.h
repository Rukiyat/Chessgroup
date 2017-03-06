#ifndef SCREENWINDOW_H
#define SCREENWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "LoginUser.h"
#include "newplayer.h"
#include "multiplayerlogin.h"


namespace Ui {
class screenwindow;
}

class screenwindow : public QMainWindow

{
    Q_OBJECT

public:
    explicit screenwindow(QWidget *parent = 0);
    ~screenwindow();

private slots:
    void on_singleplayer_clicked();
    void on_multiplayer_clicked();
private:
    Ui::screenwindow *ui;
    QSqlDatabase pdatabase;
    loginuser loginuser;
    Newplayer newplayer;
    MultiplayerLogin *multiplayerLogin;


};

#endif // SCREENWINDOW_H
