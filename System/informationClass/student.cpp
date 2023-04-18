#include "student.h"


void Student::operator =(const Student &stu)
{
    id=stu.id;
    password=stu.password;
    name=stu.name;
    gender=stu.gender;
    telephone=stu.telephone;
    place=stu.place;
    classname=stu.classname;
    field=stu.field;

}
