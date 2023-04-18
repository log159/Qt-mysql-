#include "file.h"


void File::operator =(const File &fl)
{
    id=fl.id;
    name=fl.name;//专业名
    department=fl.department;//所属系别

}
