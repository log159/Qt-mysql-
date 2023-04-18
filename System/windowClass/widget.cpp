#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    this->db = QSqlDatabase::addDatabase(dataBaseStr);
    db.setHostName(hostNameStr);
    db.setPort(portInt);
    db.setDatabaseName(databaseNameStr);
    db.setUserName(userNameStr);
    db.setPassword(passwordStr);
    db.open();

    //智能指针置空
    enWidget.clear();
    stWidget.clear();
    teWidget.clear();
    adWidget.clear();

    enWidget.reset(new EnterWidget);
    enWidget->show();


    connect(enWidget.data(),&EnterWidget::logon,[=](int windowId,int personId){
        //enWidget->hide();

        if(windowId==0){

            stWidget.reset(new StudentWidget);
            stWidget->setPersonInformation(windowId,personId);
            stWidget->show();
            connect(stWidget.data(),&StudentWidget::closeSignal,[=](){
                stWidget.reset();
            });
        }
        else if(windowId==1){
            teWidget.reset(new TeacherWidget);
            teWidget->setPersonInformation(windowId,personId);
            teWidget->show();
            connect(teWidget.data(),&TeacherWidget::closeSignal,[=](){
                teWidget.reset();
            });
        }
        else if(windowId==2){
            adWidget.reset(new AdministerWidget);
            adWidget->setPersonInformation(windowId,personId);
            adWidget->show();
            connect(adWidget.data(),&AdministerWidget::closeSignal,[=](){
                adWidget.reset();
            });

        }

    });

    enWidget->show();

}


Widget::~Widget()
{

    qDebug()<<"MainWidget delete";
}

