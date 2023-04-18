#ifndef PERSONFUNCWIDGET_H
#define PERSONFUNCWIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QLabel>
#include <QScrollArea>
#include <QDebug>
#include <QScrollBar>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>
#include <QPoint>
#include <QTimer>
#include <QSqlQuery>

#include "informationClass/student.h"
#include "informationClass/teacher.h"
#include "informationClass/administer.h"
#include "informationClass/file.h"

#include "funcWidget/showmywidget.h"
#include "funcWidget/showallwidget.h"
#include "funcWidget/changemywidget.h"
#include "funcWidget/addotherswidget.h"
#include "funcWidget/changeotherswidget.h"
#include "funcWidget/deleteotherswidget.h"

class PersonFuncWidget : public QWidget
{
    Q_OBJECT
public:
    const int windowWidth=600;
    const int windowHeight=450;

public:
    PersonFuncWidget();

    ~PersonFuncWidget();

    void paintEvent(QPaintEvent *event);




signals:

public slots:
};

#endif // PERSONFUNCWIDGET_H
