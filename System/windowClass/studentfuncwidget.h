#ifndef STUDENTFUNCWIDGET_H
#define STUDENTFUNCWIDGET_H

#include "personfuncwidget.h"

class StudentFuncWidget : public PersonFuncWidget
{
    Q_OBJECT
public:
    Student *stu=nullptr;

    ShowMyWidget * showMyWidget=nullptr;//0
    ShowAllWidget * showAllWidget=nullptr;//1
    ChangeMyWidget * changeWidget=nullptr;//2


    StudentFuncWidget();

    void hideAllWidget();

    //func

    void showMyInformation();

    void showAllInformation();

    void changeInformation();

signals:

public slots:

};

#endif // STUDENTFUNCWIDGET_H
