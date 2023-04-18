#ifndef STUDENTFUNCWIDGET_H
#define STUDENTFUNCWIDGET_H

#include "windowClass/personfuncwidget.h"



class StudentFuncWidget : public PersonFuncWidget
{
    Q_OBJECT
public:
    int windowId=0;

    QWidget * showMyWidget=nullptr;//0
    QWidget * showAllWidget=nullptr;//1
    QWidget * changeWidget=nullptr;//2



    Student *stu=nullptr;
    bool isTime=false;
    QTimer * timer=nullptr;


    QPoint initLabPoint;
    QVector<QLabel*>v_Lab;
    QVector<QPoint>v_LabLocation;





    StudentFuncWidget();

    void initAllWidget();

    //func

    void showMyInformation();

    void showAllInformation();

signals:

public slots:

};

#endif // STUDENTFUNCWIDGET_H
