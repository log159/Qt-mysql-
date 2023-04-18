#include "studentwidget.h"

StudentWidget::StudentWidget()
{
    this->setWindowTitle("学生界面");

    myLabel=new QLabel(this);
    myLabel->setFixedSize(200,60);
    myLabel->move(25,25);
    QFont font;
    font.setFamily("楷体");
    font.setPointSize(20);
    myLabel->setFont(font);
    myLabel->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    myLabel->setAttribute(Qt::WA_TransparentForMouseEvents);
    myLabel->setStyleSheet("border:2px solid red;");

    //选项按钮
    //查看个人信息
    SportButton * myInforBut=new SportButton;
    myInforBut->setParent(this);
    myInforBut->setText("查看个人信息");
    myInforBut->move(-myInforBut->width(),150);
    myInforBut->show();
    //查看所有人信息
    SportButton * allInforBut=new SportButton;
    allInforBut->setParent(this);
    allInforBut->setText("查看所有人信息");
    allInforBut->move(-myInforBut->width(),220);
    //更改个人信息
    SportButton * changeInforBut=new SportButton;
    changeInforBut->setParent(this);
    changeInforBut->setText("更改个人信息");
    changeInforBut->move(-myInforBut->width(),290);
    //退出
    SportButton * quitBut=new SportButton;
    quitBut->setParent(this);
    quitBut->setFixedSize(50,50);
    quitBut->setStyleSheet("QPushButton{border:0px;}");
    quitBut->setInitPoint(QPoint(quitBut->width(),quitBut->height()));
    quitBut->move(-quitBut->width(),this->height()-quitBut->height());
    quitBut->setIcon(QIcon(QUIT_IMG));

    QTimer * animTimer=new QTimer(this);

    stuFunPtr=new StudentFuncWidget();
    stuFunPtr->setParent(this);
    stuFunPtr->move(300,40);

    connect(myInforBut,&SportButton::clicked,[=](){stuFunPtr->showMyInformation();});
    connect(allInforBut,&SportButton::clicked,[=](){stuFunPtr->showAllInformation();});
    connect(changeInforBut,&SportButton::clicked,[=](){stuFunPtr->changeInformation();});

    connect(animTimer,&QTimer::timeout,[=](){
        static int t=0;++t;
        if(t==100)myInforBut->moveLeftToRight(myInforBut->width()*1.1);
        if(t==200)allInforBut->moveLeftToRight(allInforBut->width()*1.1);
        if(t==300)changeInforBut->moveLeftToRight(changeInforBut->width()*1.1);
        if(t==350)quitBut->moveLeftToRight(quitBut->width());
        if(t>400){animTimer->stop();t=0;};
    });
    connect(quitBut,&SportButton::clicked,this,&StudentWidget::close);

    animTimer->start(1);

}

void StudentWidget::setPersonInformation(int cId, int fId)
{
    cardId=cId;
    findId=fId;
    if(stuPtr!=nullptr){delete stuPtr;}
    stuPtr=new Student;
    this->stuFunPtr->stu=stuPtr;

    this->query.prepare("SELECT * FROM "+TableString().tableVec.at(cardId)+" where id = "+QString::number(findId)+";");
    this->query.exec();
    while(query.next())
    {
        stuPtr->id=query.value("id").toLongLong();
        stuPtr->password=query.value("password").toString();
        stuPtr->name=query.value("name").toString();
        stuPtr->gender=query.value("gender").toInt();
        stuPtr->telephone=query.value("telephone").toLongLong();
        stuPtr->place=query.value("place").toString();
        stuPtr->field=query.value("field").toLongLong();
        stuPtr->classname=query.value("classname").toString();
    }
    qDebug()<<stuPtr->id<<" "<<
              stuPtr->password<<" "<<
              stuPtr->name<<" "<<
              stuPtr->gender<<" "<<
              stuPtr->telephone<<" "<<
              stuPtr->place<<" "<<
              stuPtr->field<<" "<<
              stuPtr->classname;
    myLabel->setText(stuPtr->name);

}


StudentWidget::~StudentWidget()
{
    qDebug()<<"StudentWidget delete";
    if(stuPtr!=nullptr){delete stuPtr;stuPtr=nullptr;}
}

