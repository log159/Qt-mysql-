#ifndef ADMINISTRATORFUNCWIDGET_H
#define ADMINISTRATORFUNCWIDGET_H

#include "personfuncwidget.h"

class AdministratorFuncWidget : public PersonFuncWidget
{
    Q_OBJECT
public:
    Administer * adm=nullptr;

    ShowMyWidget * showMyWidget=nullptr;
    ShowAllWidget * showAllWidget=nullptr;
    ChangeMyWidget * changeMyWidget=nullptr;
    ChangeOthersWidget * changeOthersWidget=nullptr;
    AddOthersWidget * addOthersWidget=nullptr;
    DeleteOthersWidget * deleteOthersWidget=nullptr;


    AdministratorFuncWidget();

    void hideAllWidget();

    //func

    void showMyInformation();

    void showAllInformation();

    void changeMyInformation();

    void changeOthersInformation();

    void addOthersInformation();

    void deleteOthersInformation();


signals:

public slots:
};

#endif // ADMINISTRATORFUNCWIDGET_H
