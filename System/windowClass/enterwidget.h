#ifndef ENTERWIDGET_H
#define ENTERWIDGET_H

#include <QWidget>
#include <QApplication>
#include <QDesktopWidget>
#include <QRect>
#include <QLineEdit>
#include <QLabel>
#include <QIcon>
#include <QPushButton>
#include <QPainter>
#include <QPixmap>
#include <QBrush>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include <QCheckBox>
#include <QRadioButton>
#include <QRegExpValidator>
#include <QPoint>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QMessageBox>
#include <windows.h>

#include "otherClass/config.h"
#include "otherClass/mouselabel.h"

class EnterWidget : public QWidget
{
    Q_OBJECT
private:
    const int windowWidth=400;
    const int windowHeight=300;
    const int lineWidth=200;
    const int lineHeight=30;

    //监听身份
    int cardId=0;//0学生 1教师 2管理

    //功能指针
    QLineEdit * idLineEdit=nullptr;
    QLineEdit * passLineEdit=nullptr;

    //登录
    QPushButton * pushOn;
    QPushButton * pushEn;

    //位移记录
    QPoint myLocation;
    //是否可移动
    bool canMove=false;

public:

   EnterWidget();
   ~EnterWidget()=default;

   bool findPerson(int & personId);

   void paintEvent(QPaintEvent *event);

   void mousePressEvent(QMouseEvent *ev);

   void mouseMoveEvent(QMouseEvent *ev);

   void mouseReleaseEvent(QMouseEvent *ev);

   void keyPressEvent(QKeyEvent *ev);


signals:
   void logon(int windowId,int personId);

public slots:
};

#endif // ENTERWIDGET_H
