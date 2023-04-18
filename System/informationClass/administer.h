#ifndef ADMINISTER_H
#define ADMINISTER_H
#include <QString>

class Administer
{
public:
    long long id;//账号

    QString password;//密码

    QString name;//姓名

    static const int showNum=2;


public:
    Administer():id(-1){}
    ~Administer()=default;
    void operator =(const Administer & adm);

};

#endif // ADMINISTER_H
