#ifndef DELETEOTHERSWIDGET_H
#define DELETEOTHERSWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QSqlQuery>
#include <QKeyEvent>
#include <QString>
#include <QRegExpValidator>
#include <QRegExp>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QPushButton>
#include <QVector>
#include <QRadioButton>
#include <QMessageBox>
#include <QDebug>

#include "otherClass/config.h"
#include "otherClass/indexlabel.h"

class DeleteOthersWidget : public QWidget
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

    QVBoxLayout * scroll_layout=nullptr;

    QVector<IndexLabel*>v_lab;

    QPushButton * deleteBut=nullptr;


    DeleteOthersWidget();

    void func();

    void deleteFunc();

    void keyPressEvent(QKeyEvent *ev);

signals:

public slots:
};

#endif // DELETEOTHERSWIDGET_H
