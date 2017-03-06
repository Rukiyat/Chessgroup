//#include "movementlabel.h"
//#include "QMessageBox"
//#include  <QEvent>
//#include "chessboard.h"
//#include <QtGlobal>
//movementlabel::movementlabel(QWidget *parent) :
//    QLabel(parent)
//{
//    this->setMouseTracking(true);
//}

//void movementlabel::mouseMoveEvent(QMouseEvent *event)
//{
//    QPoint movement_pos= event->pos();
//    if(movement_pos.x() <= this->size().width() && movement_pos.y() <= this->size().height())
//    {
//        if (movement_pos.x()>= 0 && movement_pos.y() >= 0 )
//        {
//            emit Mouse_Pos(movement_pos);
//        }
//    }
////    this->x = event->x();
////    this->y = event->y();
////    emit Mouse_Pos();
//}

//void movementlabel::mousePressEvent(QMouseEvent *event)
//{
//    QMessageBox message;
//    if(event ->button()== Qt::LeftButton)
//    {

//        message.setText("left button pressed");
//        message.exec();
//    }
//    else if(event ->button()== Qt::RightButton)
//    {
//        message.setText("right button pressed");
//        message.exec();
//    }
//    emit Mouse_Pressed();
//}

//void movementlabel::leaveEvent(QEvent *)
//{
//    emit Mouse_Left();
//}

//int main()
//{
//   bool isMove=false;
//   float dx=0, dy=0;

//        QEvent event;
//        QMouseEvent even;
//        QPoint movement_pos= even->pos();

//        if (event.type() == QEvent::MouseButtonPress)
//           if (event.KeyPress == QMouseEvent:: Leave)
//               if (movement_pos.x() <= this->size().width() && movement_pos.y() <= this->size().height())
//               {
//                   isMove=true;
//                   dx=this->size().width() - movement_pos.x();
//                   dy=this->size().height() - movement_pos.y();
//               }

//        if (event.type == QEvent::MouseButtonRelease)
//            if (event-> button() == QMouseEvent::Leave)
//                isMove=false;

//   }


//   if (isMove) event->QPoint((this->size().width()-dx,this->size().height()-dy));

//}
