#include "rightclick.h"

rightClick::rightClick(QWidget * parent):
    QPushButton(parent)
{

}

void rightClick::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::RightButton)
        emit rightClicked();
}
