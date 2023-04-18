#include "administer.h"


void Administer::operator =(const Administer &adm)
{
    id=adm.id;//账号

    password=adm.password;//密码

    name=adm.name;//姓名
}
