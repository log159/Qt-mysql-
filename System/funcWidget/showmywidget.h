#ifndef SHOWMYWIDGET_H
#define SHOWMYWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QVector>
#include <QPoint>
#include <QLabel>
#include <QVariant>
#include <QSqlQuery>
#include <QString>

#include "informationClass/student.h"
#include "informationClass/teacher.h"
#include "informationClass/administer.h"
#include "informationClass/file.h"

class ShowMyWidget : public QWidget
{
    Q_OBJECT
public:
    QTimer * timer=nullptr;

    //animation func menber
    bool isTime=false;
    QPoint initLabPoint;
    QVector<QLabel*>v_Lab;
    QVector<QPoint>v_LabLocation;

    ShowMyWidget();

    void func(Student * stu);

    void func(Teacher * tea);

    void func(Administer * adm);


signals:

public slots:
};

#endif // SHOWMYWIDGET_H
