#include "sportbutton.h"

SportButton::SportButton()
{
    this->setFixedSize(120,100*0.618);
    this->initPoint.setX(this->width());
    this->initPoint.setY(this->height());
    this->setFocusPolicy(Qt::NoFocus);

    this->setIconSize(QSize(this->width(), this->height()));
//    this->setFlat(true);
//    button->setStyleSheet("border: 0px"); //消除边框

}

SportButton::~SportButton()
{

}

void SportButton::setInitPoint(const QPoint &p)
{
    initPoint.setX(p.x());
    initPoint.setY(p.y());

}

void SportButton::moveLeftToRight(int step)
{
    //创建动画对象
    QPropertyAnimation*animation=new QPropertyAnimation(this,"geometry",this);
    //动画间隔
    animation->setDuration(1000);
    //开始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x()+step,this->y(),this->width(),this->height()));
    //设置动画曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行后销毁
    animation->start(QAbstractAnimation::DeleteWhenStopped);

}

void SportButton::mousePressEvent(QMouseEvent *e)
{
//    this->setFixedSize(QSize(this->initPoint.x()*1.1,this->initPoint.y()*1.1));
    QPushButton::mousePressEvent(e);
}

void SportButton::enterEvent(QEvent *event)
{
    Q_UNUSED(event)

    this->setFixedSize(QSize(this->initPoint.x()*1.1,this->initPoint.y()*1.1));
}

void SportButton::leaveEvent(QEvent *event)
{
    Q_UNUSED(event)
    this->setFixedSize(QSize(this->initPoint.x(),this->initPoint.y()));

}
