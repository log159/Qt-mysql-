#include "teacher.h"



Teacher::~Teacher()
{

}

void Teacher::operator =(const Teacher &tea)
{
    id=tea.id;
    password=tea.password;
    name=tea.name;
    gender=tea.gender;
    telephone=tea.telephone;
    classname=tea.classname;

}
