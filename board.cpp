#include "board.h"
#include "ui_board.h"



Board::Board(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Board)
{
    ui->setupUi(this);
}

Board::~Board()
{
    delete ui;
}




