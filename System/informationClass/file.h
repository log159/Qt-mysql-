#ifndef FILE_H
#define FILE_H
#include <QString>

class File
{
public:
    int id;//专业编号
    QString name;//专业名
    QString department;//所属系别
public:
    File():id(-1){}
    ~File()=default;
    void operator =(const File&fl);

};

#endif // FILE_H
