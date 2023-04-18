#-------------------------------------------------
#
# Project created by QtCreator 2023-04-10T16:28:24
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = System
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    informationClass/administer.cpp \
    informationClass/file.cpp \
    informationClass/student.cpp \
    informationClass/teacher.cpp \
    windowClass/administerwidget.cpp \
    windowClass/enterwidget.cpp \
    windowClass/studentwidget.cpp \
    windowClass/teacherwidget.cpp \
    windowClass/widget.cpp \
    otherClass/sportlabel.cpp \
    windowClass/personwidget.cpp \
    otherClass/config.cpp \
    otherClass/sportbutton.cpp \
    otherClass/mouselabel.cpp \
    windowClass/personfuncwidget.cpp \
    windowClass/administratorfuncwidget.cpp \
    windowClass/studentfuncwidget.cpp \
    windowClass/teacherfuncwidget.cpp \
    funcWidget/changemywidget.cpp \
    funcWidget/showallwidget.cpp \
    funcWidget/showmywidget.cpp \
    funcWidget/addotherswidget.cpp \
    funcWidget/changeotherswidget.cpp \
    otherClass/indexlabel.cpp \
    funcWidget/deleteotherswidget.cpp


HEADERS += \
    informationClass/administer.h \
    informationClass/file.h \
    informationClass/student.h \
    informationClass/teacher.h \
    otherClass/config.h \
    windowClass/administerwidget.h \
    windowClass/enterwidget.h \
    windowClass/studentwidget.h \
    windowClass/teacherwidget.h \
    windowClass/widget.h \
    otherClass/sportlabel.h \
    windowClass/personwidget.h \
    otherClass/sportbutton.h \
    otherClass/mouselabel.h \
    windowClass/personfuncwidget.h \
    windowClass/administratorfuncwidget.h \
    windowClass/studentfuncwidget.h \
    windowClass/teacherfuncwidget.h \
    funcWidget/changemywidget.h \
    funcWidget/showallwidget.h \
    funcWidget/showmywidget.h \
    funcWidget/addotherswidget.h \
    funcWidget/changeotherswidget.h \
    otherClass/indexlabel.h \
    funcWidget/deleteotherswidget.h

RESOURCES += \
    res.qrc



