#ifndef gamestatus_H
#define gamestatus_H

#include <QMainWindow>
#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>



namespace Ui {
class gamestatus;
}

class gamestatus : public QDialog
{
    Q_OBJECT

public:
    explicit gamestatus(QWidget *parent = 0);
    ~gamestatus();


private slots:
    void on_newgame_clicked();
    void on_goback_clicked();
    void on_currentgame_clicked();


private:
    Ui::gamestatus *ui;

};

#endif // gamestatus_H
