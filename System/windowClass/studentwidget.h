#ifndef STUDENTWIDGET_H
#define STUDENTWIDGET_H


#include "personwidget.h"
#include "informationClass/student.h"
#include "windowClass/studentfuncwidget.h"

class StudentWidget : public PersonWidget
{
    Q_OBJECT

private:

    QLabel * myLabel=nullptr;

    Student * stuPtr=nullptr;

    StudentFuncWidget * stuFunPtr=nullptr;

public:
   StudentWidget();
   ~StudentWidget();

   void setPersonInformation(int cId, int fId)override;//初始化个人信息

signals:

public slots:
};

#endif // STUDENTWIDGET_H
