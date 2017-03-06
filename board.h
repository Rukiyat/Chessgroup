#ifndef BOARD_H
#define BOARD_H

#include <QDialog>
#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>



namespace Ui {
class Board;
}

class Board : public QDialog
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = 0);
    ~Board();

private:
    Ui::Board *ui;


};

#endif // BOARD_H
