#ifndef STUDENT_H
#define STUDENT_H
#include <QString>

class Student
{


public:
    long long id;//账号（学号）——唯一

    QString password;//密码

    QString name;//姓名

    int gender;//性别（1 男 0 女）

    long long telephone;//电话

    QString place;//家庭地址

    long long field;//专业系别id

    QString classname;//班级

    static const int showNum=7;

public:

    Student():id(-1),gender(-1),telephone(-1),field(-1){}
    ~Student()=default;

    void operator =(const Student&stu);

};

#endif // STUDENT_H
