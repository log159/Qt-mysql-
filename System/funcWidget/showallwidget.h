#ifndef SHOWALLWIDGET_H
#define SHOWALLWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QSqlQuery>
#include <QLabel>
#include <QKeyEvent>
#include <QString>
#include <QRegExpValidator>
#include <QRegExp>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QPushButton>
#include <QVector>
#include <QRadioButton>

#include "otherClass/config.h"

class ShowAllWidget : public QWidget
{
    Q_OBJECT
public:
    const int lineWidth=140;
    const int lineHeight=30;
    const int windowWidth=600;
    const int windowHeight=450;

public:

    int cardId=0;//0 学生 1 老师

    //allinformation func member
    QLineEdit * idLineEdit=nullptr;
    QLineEdit * nameLineEdit=nullptr;

    QLabel * numLab=nullptr;

    QVBoxLayout* scroll_layout=nullptr;

    QVector<QLabel*>v_lab;

    ShowAllWidget();

    void func();

    void keyPressEvent(QKeyEvent *ev);


signals:

public slots:
};

#endif // SHOWALLWIDGET_H
