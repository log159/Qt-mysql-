#ifndef TEACHERWIDGET_H
#define TEACHERWIDGET_H


#include "personwidget.h"
#include "informationClass/teacher.h"
#include "windowClass/teacherfuncwidget.h"

class TeacherWidget : public PersonWidget
{
    Q_OBJECT
private:
    QLabel * myLabel=nullptr;

    Teacher * teaPtr=nullptr;

    TeacherFuncWidget * teaFunPtr=nullptr;
public:
    TeacherWidget();
    ~TeacherWidget();

   void setPersonInformation(int cId, int fId)override;//初始化个人信息

signals:

public slots:
};

#endif // TEACHERWIDGET_H
