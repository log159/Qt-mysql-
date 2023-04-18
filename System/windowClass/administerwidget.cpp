#include "administerwidget.h"

AdministerWidget::AdministerWidget()
{
    this->setWindowTitle("管理界面");

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

    //更改他人信息
    SportButton * changeOthersInforBut=new SportButton;
    changeOthersInforBut->setParent(this);
    changeOthersInforBut->setText("更改他人信息");
    changeOthersInforBut->move(-myInforBut->width(),150);

    //添加信息
    SportButton * addInforBut=new SportButton;
    addInforBut->setParent(this);
    addInforBut->setText("添加信息");
    addInforBut->move(-myInforBut->width(),220);

    //删除信息
    SportButton * deleteInforBut=new SportButton;
    deleteInforBut->setParent(this);
    deleteInforBut->setText("删除信息");
    deleteInforBut->move(-myInforBut->width(),290);


    //退出
    SportButton * quitBut=new SportButton;
    quitBut->setParent(this);
    quitBut->setFixedSize(50,50);
    quitBut->setStyleSheet("QPushButton{border:0px;}");
    quitBut->setInitPoint(QPoint(quitBut->width(),quitBut->height()));
    quitBut->move(-quitBut->width(),this->height()-quitBut->height());
    quitBut->setIcon(QIcon(QUIT_IMG));

    QTimer * animTimer=new QTimer(this);

    admFunPtr=new AdministratorFuncWidget;
    admFunPtr->setParent(this);
    admFunPtr->move(300,40);

    connect(myInforBut,&SportButton::clicked,[=](){admFunPtr->showMyInformation();});
    connect(allInforBut,&SportButton::clicked,[=](){admFunPtr->showAllInformation();});
    connect(changeInforBut,&SportButton::clicked,[=](){admFunPtr->changeMyInformation();});
    connect(changeOthersInforBut,&SportButton::clicked,[=](){admFunPtr->changeOthersInformation();});
    connect(addInforBut,&SportButton::clicked,[=](){admFunPtr->addOthersInformation();});
    connect(deleteInforBut,&SportButton::clicked,[=](){admFunPtr->deleteOthersInformation();});

    connect(animTimer,&QTimer::timeout,[=](){
        static int t=0;++t;
        if(t==100)myInforBut->moveLeftToRight(myInforBut->width()*1.1);
        if(t==200)allInforBut->moveLeftToRight(allInforBut->width()*1.1);
        if(t==300)changeInforBut->moveLeftToRight(changeInforBut->width()*1.1);
        if(t==400)changeOthersInforBut->moveLeftToRight(changeOthersInforBut->width()*2.3);
        if(t==500)addInforBut->moveLeftToRight(addInforBut->width()*2.3);
        if(t==600)deleteInforBut->moveLeftToRight(deleteInforBut->width()*2.3);

        if(t==650)quitBut->moveLeftToRight(quitBut->width());
        if(t>800){animTimer->stop();t=0;}
    });
    connect(quitBut,&SportButton::clicked,this,&AdministerWidget::close);

    animTimer->start(1);
}

void AdministerWidget::setPersonInformation(int cId, int fId)
{
    cardId=cId;
    findId=fId;

    if(admPtr!=nullptr){delete admPtr;}
    admPtr=new Administer;
    this->admFunPtr->adm=admPtr;

    this->query.prepare("SELECT * FROM "+TableString().tableVec.at(cardId)+" where id = "+QString::number(findId)+";");
    this->query.exec();
    while(query.next())
    {
        admPtr->id=query.value("id").toInt();
        admPtr->password=query.value("password").toString();
        admPtr->name=query.value("name").toString();
    }
    qDebug()<<admPtr->id<<" "<<
              admPtr->password<<" "<<
              admPtr->name<<" ";
    myLabel->setText(admPtr->name);

}

AdministerWidget::~AdministerWidget()
{
    qDebug()<<"AdministerWidget delete";
    if(admPtr!=nullptr){delete admPtr;admPtr=nullptr;}

}

