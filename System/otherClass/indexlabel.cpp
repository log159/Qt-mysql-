#include "indexlabel.h"

IndexLabel::IndexLabel()
{
    this->setStyleSheet("border:2px solid black;");
}

void IndexLabel::mousePressEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev)
    noChange=!noChange;
    emit pass();
    if(noChange)
        this->setStyleSheet("border:5px solid red;");
    else
        this->setStyleSheet("border:2px solid black;");
}

void IndexLabel::enterEvent(QEvent *)
{
    if(noChange){return;}
    this->setStyleSheet("border:2px solid red;");
}

void IndexLabel::leaveEvent(QEvent *)
{
    if(noChange){return;}
    this->setStyleSheet("border:2px solid black;");
}
