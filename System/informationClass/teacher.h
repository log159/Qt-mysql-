#ifndef TEACHER_H
#define TEACHER_H

#include <QString>

class Teacher
{
public:
    long long id;//账号（教工号）——唯一

    QString password;//密码

    QString name;//姓名

    int gender;//性别（0 男 1 女）

    long long telephone;//电话

    QString classname;//班级

    static const int showNum=5;

public:
    Teacher():id(-1),telephone(-1){}
    ~Teacher();
    void operator =(const Teacher&tea);
};

#endif // TEACHER_H
