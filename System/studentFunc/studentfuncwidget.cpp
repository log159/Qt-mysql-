#include "studentfuncwidget.h"

StudentFuncWidget::StudentFuncWidget()
{


    showMyWidget=new QWidget;
    showMyWidget->setParent(this);
    showMyWidget->setFixedSize(this->width(),this->height());
    showMyWidget->setFocusPolicy(Qt::NoFocus);
    showMyWidget->show();

    showAllWidget=new QWidget;
    showAllWidget->setParent(this);
    showAllWidget->setFixedSize(this->width(),this->height());
    showAllWidget->setFocusPolicy(Qt::NoFocus);
    showAllWidget->hide();

    changeWidget=new QWidget;
    changeWidget->setParent(this);
    changeWidget->setFixedSize(this->width(),this->height());
    changeWidget->setFocusPolicy(Qt::NoFocus);
    changeWidget->hide();

    timer=new QTimer(this);
    connect(timer,&QTimer::timeout,[=](){
        static int num=0;
        for(int i=0;i<Student::showNum;++i)
        {
            v_Lab.at(i)->move(initLabPoint.x()+((double)num/100)*(v_LabLocation.at(i).x()-initLabPoint.x()),initLabPoint.y()+((double)num/100)*(v_LabLocation.at(i).y()-initLabPoint.y()));
        }
        ++num;
        if(num>=100){
            num=0;
            timer->stop();
        }

    });


}

void StudentFuncWidget::initAllWidget()
{



}

void StudentFuncWidget::showMyInformation()
{
    if(this->windowId!=0||isTime==true){return;}

    timer->start(5);
    isTime=true;
    v_Lab.clear();
    v_LabLocation.clear();
    initLabPoint.setX(-70);
    initLabPoint.setY(-10);
    for(int i=0;i<Student::showNum;++i)
    {
        QLabel * lab=new QLabel(showMyWidget);

        switch(i)
        {
        case 0:
            lab->setText("id："+QString::number(stu->id));break;
        case 1:
            lab->setText("姓名："+stu->name);break;
        case 2:
            lab->setText(QString("性别：")+((stu->gender==1)?"男":"女"));
            break;
        case 3:
            lab->setText("电话："+QString::number(stu->telephone));
            break;
        case 4:
            lab->setText(QString("地址：")+stu->place);
            break;
        case 5:
            lab->setText("班级："+stu->classname);
            break;
        case 6:
            QSqlQuery query;
            query.prepare("SELECT * FROM file where id = "+QString::number(stu->field));
            query.exec();
            query.next();
            lab->setText("专业："+query.value("name").toString());
            break;

        }
        lab->move(initLabPoint);
        lab->setFixedSize(300,50);
        lab->setStyleSheet("border:2px solid red;");//设置边框
        lab->show();
        v_LabLocation.push_back(QPoint(20,i*50+30));
        v_Lab.push_back(lab);
    }


}

void StudentFuncWidget::showAllInformation()
{



}
