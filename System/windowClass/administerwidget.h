#ifndef ADMINISTERWIDGET_H
#define ADMINISTERWIDGET_H

#include "personwidget.h"
#include "informationClass/administer.h"
#include "windowClass/administratorfuncwidget.h"
class AdministerWidget : public PersonWidget
{
    Q_OBJECT
private:
    QLabel * myLabel=nullptr;

    Administer * admPtr=nullptr;

    AdministratorFuncWidget * admFunPtr=nullptr;


public:
    AdministerWidget();
    ~AdministerWidget();

   void setPersonInformation(int cId, int fId)override;//初始化个人信息

signals:

public slots:
};

#endif // ADMINISTERWIDGET_H
