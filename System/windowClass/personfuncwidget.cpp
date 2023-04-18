#include "personfuncwidget.h"

PersonFuncWidget::PersonFuncWidget()
{
    this->setFixedSize(windowWidth,windowHeight);

}


void PersonFuncWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter(this);
    painter.drawRect(0,0,this->width()-1,this->height()-1);

}


PersonFuncWidget::~PersonFuncWidget()
{

}
