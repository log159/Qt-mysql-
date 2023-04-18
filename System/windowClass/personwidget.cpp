#include "personwidget.h"

PersonWidget::PersonWidget()
{

    this->setWindowIcon(QIcon(QString(WINDOW_START_ICON)));
    this->setFixedSize(windowWidth,windowHeight);
    //初始位置屏幕居中
    QRect deskRect = QApplication::desktop()->availableGeometry();
    this->move(deskRect.width()*0.5-this->width()*0.5,deskRect.height()*0.5-this->height()*0.5);
    this->setWindowTitle("系统界面");
//    this->setWindowFlags(Qt::CustomizeWindowHint |
//                   Qt::WindowMinimizeButtonHint |
//                   Qt::WindowMaximizeButtonHint);
}

PersonWidget::~PersonWidget()
{

}

void PersonWidget::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event)
    emit closeSignal();
}

