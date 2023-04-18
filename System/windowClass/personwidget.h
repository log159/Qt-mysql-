#ifndef PERSONWIDGET_H
#define PERSONWIDGET_H

#include <QWidget>
#include <QApplication>
#include <QDesktopWidget>
#include <QIcon>
#include <QRect>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QString>
#include <QTimer>
#include <QVector>
#include <QLabel>
#include <QLineEdit>

#include "otherClass/config.h"
#include "otherClass/sportbutton.h"

class PersonWidget : public QWidget
{
    Q_OBJECT
public:
    const int windowWidth=1920*0.5;
    const int windowHeight=1080*0.5;

protected:
    int cardId=-1;
    int findId=-1;
    QSqlQuery query;

public:
    PersonWidget();
    virtual~PersonWidget();
    virtual void setPersonInformation(int cId,int fId)=0;
    void closeEvent(QCloseEvent *event);


signals:
    void closeSignal();

public slots:
};

#endif // PERSONWIDGET_H
