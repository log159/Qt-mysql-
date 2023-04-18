#include "studentfuncwidget.h"

StudentFuncWidget::StudentFuncWidget()
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
    changeWidget=new ChangeMyWidget;
    changeWidget->setParent(this);
    changeWidget->setFixedSize(this->width(),this->height());
    changeWidget->setFocusPolicy(Qt::NoFocus);
    changeWidget->hide();


}

void StudentFuncWidget::hideAllWidget()
{
    showMyWidget->hide();//0
    showAllWidget->hide();//1
    changeWidget->hide();//2

}

void StudentFuncWidget::showMyInformation()
{
    hideAllWidget();
    if(stu==nullptr){return;}

    qDebug()<<"show my information";

    showMyWidget->show();
    showMyWidget->setFocus();

    showMyWidget->func(stu);



}

void StudentFuncWidget::showAllInformation()
{
    qDebug()<<"show all information";
    hideAllWidget();
    showAllWidget->show();
    showAllWidget->setFocus();

}

void StudentFuncWidget::changeInformation()
{
    hideAllWidget();
    if(stu==nullptr){return;}
    qDebug()<<"change information ";

    changeWidget->show();
    changeWidget->setFocus();

    changeWidget->func(stu);
}
