#ifndef BUTTONSHEADER_H
#define BUTTONSHEADER_H


#include <QPushButton>
#include <QObject>

class buttonsheader
        : public QWidget
{
     Q_OBJECT
public:
    buttonsheader();
     QPushButton *undo;

//     public slots:
//         void Undo();

};

#endif // BUTTONSHEADER_H
