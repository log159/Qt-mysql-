#include "mouselabel.h"

MouseLabel::MouseLabel(const QString &str1, const QString &str2)
{
    img_1=str1;
    img_2=str2;
    if(img_2.compare("")==0){img_2=img_1;}
    this->setPixmap(QPixmap(img_1));

    //图片自适应
    this->setScaledContents(true);

//    this->setStyleSheet("border:2px solid red;");//设置边框

}

void MouseLabel::mousePressEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev)

    imgId=!imgId;
    if(imgId==true)
    {
        this->setPixmap(QPixmap(img_1));
    }
    else
    {
        this->setPixmap(QPixmap(img_2));
    }
    emit mousePress(imgId);

}
