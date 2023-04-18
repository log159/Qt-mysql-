#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QApplication>
#include <QIcon>
#include <QDebug>
#include <QSharedPointer>
#include <QSqlError>

#include "otherClass/config.h"
#include "enterwidget.h"
#include "personwidget.h"
#include "studentwidget.h"
#include "teacherwidget.h"
#include "administerwidget.h"

class Widget : public QWidget
{
    Q_OBJECT
private:

    const QString dataBaseStr="QODBC";
    const QString hostNameStr="127.0.0.1";
    const int portInt=3306;
    const QString databaseNameStr="information";
    const QString userNameStr="root";
    const QString passwordStr="333221";

private:
    QSqlDatabase db;//mysql

    QSharedPointer<EnterWidget>enWidget;//登录界面

    QSharedPointer<StudentWidget>stWidget;//学生界面

    QSharedPointer<TeacherWidget>teWidget;//教师界面

    QSharedPointer<AdministerWidget>adWidget;//管理界面


public:
    Widget(QWidget *parent = 0);

    ~Widget();



};

#endif // WIDGET_H
