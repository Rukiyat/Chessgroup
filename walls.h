#ifndef WALLS_H
#define WALLS_H
#include <QLabel>
//#include <QThread>
#include <QObject>

class walls: public QLabel
{
public:
    //Fields
        int tileColor,piece,pieceColor,row,col,tileNum;
        char  pieceName;
        //Constructors
        walls(QWidget* pParent=0, Qt::WindowFlags f=0) : QLabel(pParent, f) {}
        walls(const QString& text, QWidget* pParent = 0, Qt::WindowFlags f = 0) : QLabel(text, pParent, f){}


        //Methods
        void mousePressEvent(QMouseEvent *event);
        void display(char elem);
        void wallDisplay();


};


#endif // WALLS_H
