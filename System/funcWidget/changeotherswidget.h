#ifndef CHANGEOTHERSWIDGET_H
#define CHANGEOTHERSWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QSqlQuery>
#include <QKeyEvent>
#include <QString>
#include <QRegExpValidator>
#include <QRegExp>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QPushButton>
#include <QVector>
#include <QRadioButton>
#include <QComboBox>
#include <QApplication>
#include <QDesktopWidget>
#include <QIcon>
#include <windows.h>
#include <QMessageBox>
#include <QDebug>

#include "otherClass/config.h"
#include "otherClass/indexlabel.h"
#include "informationClass/student.h"
#include "informationClass/teacher.h"
#include "informationClass/administer.h"

class ChangeOthersWidget : public QWidget
{
    Q_OBJECT
public:

    const int lineWidth=140;
    const int lineHeight=30;
    const int windowWidth=600;
    const int windowHeight=450;


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

    int cardId=0;//0 学生 1 老师

    //allinformation func member
    QLineEdit * idLineEdit=nullptr;
    QLineEdit * nameLineEdit=nullptr;

    QLabel * numLab=nullptr;

    QVBoxLayout* scroll_layout=nullptr;

    QWidget * changeStuWidget=nullptr;
    QWidget * changeTeaWidget=nullptr;


    QString selectStuIndex;

    QString selectTeaIndex;

    Student * stuPtr=nullptr;
    Teacher * teaPtr=nullptr;



    QVector<IndexLabel*>v_lab;

    ChangeOthersWidget();
    ~ChangeOthersWidget();

    void initChangeStuWidget();

    void initChangeTeaWidget();

    void sendStuWidget(const QString & idStr);

    void sendTeaWidget(const QString & idStr);

    void saveStuFunc();

    void initStuPass();

    void saveTeaFunc();

    void initTeaPass();

    void func();

    void keyPressEvent(QKeyEvent *ev);


signals:

public slots:
};

#endif // CHANGEOTHERSWIDGET_H
