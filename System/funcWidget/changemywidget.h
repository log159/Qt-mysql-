#ifndef CHANGEMYWIDGET_H
#define CHANGEMYWIDGET_H

#include <QWidget>
#include <QString>
#include <QLineEdit>
#include <QRegExpValidator>
#include <QRegExp>
#include <QSqlQuery>
#include <QComboBox>
#include <QVBoxLayout>
#include <QDebug>
#include <QPushButton>
#include <QMap>
#include <QSqlError>
#include <QMessageBox>
#include <QApplication>
#include <QDesktopWidget>
#include <QIcon>
#include <QLineEdit>
#include <windows.h>

#include "otherClass/config.h"
#include "informationClass/student.h"
#include "informationClass/teacher.h"
#include "informationClass/administer.h"

class ChangeMyWidget : public QWidget
{
    Q_OBJECT
public:
    const int lineWidth=180;
    const int lineHeight=40;
    const int windowWidth=600;
    const int windowHeight=450;

private:
    QLineEdit * nameLine;
    QComboBox * genderComboBox;
    QLineEdit * teleLine;
    QLineEdit * placeLine;
    QLineEdit * classLine;
    QComboBox * fileComboBox;

public:
    Student * changeStuPtr=nullptr;

    Teacher * changeTeaPtr=nullptr;

    Administer * changeAdmPtr=nullptr;

    bool setEnd=false;

    QPushButton * saveBut=nullptr;

    QPushButton * changePassBut=nullptr;

    QLineEdit * oldPass=nullptr;

    QLineEdit * newPass=nullptr;

    QLineEdit * newPassToo=nullptr;

    QWidget * changePassWidget=nullptr;

    QMap<int,long long>fileIndexMap;


public:
    void changePassFunc(int cardId);

    void func(Student * stu);
    void saveFunc(Student);

    void func(Teacher * tea);
    void saveFunc(Teacher);

    void func(Administer* adm);
    void saveFunc(Administer);

    ChangeMyWidget();
    ~ChangeMyWidget();

signals:

public slots:
};

#endif // CHANGEMYWIDGET_H
