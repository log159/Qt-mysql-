#ifndef ADDOTHERSWIDGET_H
#define ADDOTHERSWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QRegExp>
#include <QRegExpValidator>
#include <QString>
#include <QRadioButton>
#include <QComboBox>
#include <QSqlQuery>
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>

#include "otherClass/config.h"
#include "informationClass/student.h"
#include "informationClass/teacher.h"
#include "informationClass/administer.h"

class AddOthersWidget : public QWidget
{
    Q_OBJECT
public:

    const int lineWidth=180;
    const int lineHeight=40;
    const int windowWidth=600;
    const int windowHeight=450;

private:
    //student information get
    QLineEdit * idLine;
    QLineEdit * nameLine;
    QComboBox* genderComboBox;
    QLineEdit * teleLine;
    QLineEdit * placeLine;
    QLineEdit * classLine;
    QComboBox* fileComboBox;

    QMap<int,long long>fileIndexMap;

    //teacher information get
    QLineEdit * idLine2;
    QLineEdit * nameLine2;
    QComboBox * genderComboBox2;
    QLineEdit * teleLine2;
    QLineEdit *  classLine2;

public:


    QWidget * addStuWidget=nullptr;

    QWidget * addTeaWidget=nullptr;

    AddOthersWidget();

    void initStuLine();

    void initTeaLine();

    void addStuFunc();

    void addTeaFunc();

signals:

public slots:
};

#endif // ADDOTHERSWIDGET_H
