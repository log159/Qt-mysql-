#ifndef TEACHERFUNCWIDGET_H
#define TEACHERFUNCWIDGET_H

#include "personfuncwidget.h"

class TeacherFuncWidget : public PersonFuncWidget
{
    Q_OBJECT
public:

    Teacher *tea=nullptr;

    ShowMyWidget * showMyWidget=nullptr;//0

    ShowAllWidget * showAllWidget=nullptr;//1

    ChangeMyWidget * changeWidget=nullptr;

    TeacherFuncWidget();

    void hideAllWidget();


    //func
    void showMyInformation();

    void showAllInformation();

    void changeInformation();
signals:

public slots:
};

#endif // TEACHERFUNCWIDGET_H
