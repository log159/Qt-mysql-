#include "administratorfuncwidget.h"

AdministratorFuncWidget::AdministratorFuncWidget()
{

    //展示个人信息
    showMyWidget=new ShowMyWidget;
    showMyWidget->setParent(this);
    showMyWidget->setFixedSize(this->width(),this->height());
    showMyWidget->setFocusPolicy(Qt::NoFocus);
    showMyWidget->show();

    //展示所有人信息
    showAllWidget=new ShowAllWidget;
    showAllWidget->setParent(this);
    showAllWidget->setFixedSize(this->width(),this->height());
    showAllWidget->setFocusPolicy(Qt::NoFocus);
    showAllWidget->hide();


    //修改个人信息
    changeMyWidget=new ChangeMyWidget;
    changeMyWidget->setParent(this);
    changeMyWidget->setFixedSize(this->width(),this->height());
    changeMyWidget->setFocusPolicy(Qt::NoFocus);
    changeMyWidget->hide();


    //修改他人信息
    changeOthersWidget=new ChangeOthersWidget;
    changeOthersWidget->setParent(this);
    changeOthersWidget->setFixedSize(this->width(),this->height());
    changeOthersWidget->setFocusPolicy(Qt::NoFocus);
    changeOthersWidget->hide();


    //添加他人信息
    addOthersWidget=new AddOthersWidget;
    addOthersWidget->setParent(this);
    addOthersWidget->setFixedSize(this->width(),this->height());
    addOthersWidget->setFocusPolicy(Qt::NoFocus);
    addOthersWidget->hide();

    //删除他人信息
    deleteOthersWidget=new DeleteOthersWidget;
    deleteOthersWidget->setParent(this);
    deleteOthersWidget->setFixedSize(this->width(),this->height());
    deleteOthersWidget->setFocusPolicy(Qt::NoFocus);
    deleteOthersWidget->hide();

}

void AdministratorFuncWidget::hideAllWidget()
{
    showMyWidget->hide();
    showAllWidget->hide();
    changeMyWidget->hide();
    changeOthersWidget->hide();
    addOthersWidget->hide();
    deleteOthersWidget->hide();
}

void AdministratorFuncWidget::showMyInformation()
{
    qDebug()<<"show my information";
    if(adm==nullptr){return;}

    hideAllWidget();
    showMyWidget->show();
    showMyWidget->setFocus();
    showMyWidget->func(adm);
}

void AdministratorFuncWidget::showAllInformation()
{
    qDebug()<<"show all information";
    hideAllWidget();
    showAllWidget->show();
    showAllWidget->setFocus();

}

void AdministratorFuncWidget::changeMyInformation()
{
    qDebug()<<"change my information ";
    if(adm==nullptr){return;}

    hideAllWidget();
    changeMyWidget->show();
    changeMyWidget->setFocus();
    changeMyWidget->func(adm);

}

void AdministratorFuncWidget::changeOthersInformation()
{
    qDebug()<<"change others information";
    hideAllWidget();
    changeOthersWidget->show();
    changeOthersWidget->setFocus();

}

void AdministratorFuncWidget::addOthersInformation()
{
    qDebug()<<"add information";
    hideAllWidget();
    addOthersWidget->show();
    addOthersWidget->setFocus();


}

void AdministratorFuncWidget::deleteOthersInformation()
{
    qDebug()<<"delete others information";
    hideAllWidget();
    deleteOthersWidget->show();
    deleteOthersWidget->setFocus();


}
