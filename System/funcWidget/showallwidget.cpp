#include "showallwidget.h"

ShowAllWidget::ShowAllWidget()
{
    idLineEdit=new QLineEdit;
    idLineEdit->setParent(this);
    idLineEdit->setFixedSize(lineWidth,lineHeight);
    idLineEdit->move(200,15);
    idLineEdit->setPlaceholderText("要搜索的账号...");

    nameLineEdit=new QLineEdit;
    nameLineEdit->setParent(this);
    nameLineEdit->setFixedSize(lineWidth,lineHeight);
    nameLineEdit->move(350,15);
    nameLineEdit->setPlaceholderText("要搜索的姓名...");

    //单选框
    QRadioButton * stuGroup=new QRadioButton(this);
    QRadioButton * teaGroup=new QRadioButton(this);
    stuGroup->move(15,20);
    stuGroup->setText("查询学生");
    teaGroup->move(100,20);
    teaGroup->setText("查询教师");

    stuGroup->setChecked(1);


    //正则
    QRegExp regExpId( "^[0-9]*$" );
    idLineEdit->setValidator(new QRegExpValidator(regExpId,this));



    QScrollArea * scroll_area=new QScrollArea(this);
    scroll_area->setWidgetResizable(true);
    scroll_area->setMinimumSize(this->width()*0.95,this->height()-80);
    scroll_area->move(0,50);

    // 创建一个QWidget作为垂直布局的容器，并设置为QScrollArea的widget属性
    QWidget* scroll_widget = new QWidget(scroll_area);
    scroll_layout = new QVBoxLayout(scroll_widget);

    // 设置QScrollArea的widget属性为QWidget容器
    scroll_area->setWidget(scroll_widget);


    numLab=new QLabel(this);
    numLab->setFixedSize(150,30);
    numLab->move(this->width()-150,20);
    numLab->setText("");
    QFont font;
    font.setFamily("楷体");
    font.setPointSize(10);
    numLab->setFont(font);
    numLab->setAlignment(Qt::AlignLeft);
//    numLab->setStyleSheet("border:2px solid red;");//设置边框
    numLab->show();

    connect(stuGroup,&QRadioButton::clicked,[=](){
        cardId=0;
        func();
    });
    connect(teaGroup,&QRadioButton::clicked,[=](){
        cardId=1;
        func();
    });

}

void ShowAllWidget::func()
{
    for(QVector<QLabel*>::iterator it=v_lab.begin();it!=v_lab.end();++it){delete *it;}
    v_lab.clear();
    QString idStr = idLineEdit->text();
    QString nameStr=nameLineEdit->text();
    QSqlQuery query;
    if(idStr.toInt()==0&&nameStr==""){
        if(cardId==0){
            query.prepare("SELECT id,name,field,classname,telephone FROM "+
                          TableString().tableVec.at(cardId));
        }
        else if(cardId==1)
        {
            query.prepare("SELECT id,name,classname,telephone FROM "+
                          TableString().tableVec.at(cardId));

        }

    }
    else
    {
        if(cardId==0){
            query.prepare("SELECT id,name,field,classname,telephone FROM "+
                          TableString().tableVec.at(cardId)+
                          " where (id like '%"+QString::number(idStr.toLongLong())+"%') and "
                          " (name like '%"+nameStr+"%')"
                          );

        }
        else if(cardId==1)
        {
            query.prepare("SELECT id,name,classname,telephone FROM "+
                          TableString().tableVec.at(cardId)+
                          " where (id like '%"+QString::number(idStr.toLongLong())+"%') and "
                          " (name like '%"+nameStr+"%')"
                          );

        }
    }
    query.exec();
    while(query.next())
    {
        QLabel * lab=new QLabel;
        lab->setFixedSize(this->width()*1.2,40);
        QString allInfor="";
        if(cardId==0)
        {
            QSqlQuery fileq;
            fileq.prepare("SELECT name FROM file where id = "+query.value("field").toString());
            fileq.exec();
            fileq.next();

            allInfor="id："+query.value("id").toString()+
                    " 姓名："+query.value("name").toString()+
                    " 专业："+fileq.value("name").toString()+
                    " 班级："+query.value("classname").toString()+
                    " 电话："+query.value("telephone").toString();
        }
        else if(cardId==1)
        {
            allInfor="id："+query.value("id").toString()+
                    " 姓名："+query.value("name").toString()+
                    " 班级："+query.value("classname").toString()+
                    " 电话："+query.value("telephone").toString();

        }
        lab->setText(allInfor);
        lab->setStyleSheet("border:2px solid black;");//设置边框
        v_lab.push_back(lab);

        scroll_layout->addWidget(lab);
    }
    numLab->setText("find："+QString::number(v_lab.size())+"人");
}

void ShowAllWidget::keyPressEvent(QKeyEvent *ev)
{
    if(cardId!=0&&cardId!=1){
        return;
    }

    if(ev->key() == Qt::Key_Enter || ev->key() == Qt::Key_Return||ev->key()==Qt::Key_Space)
    {
        func();
    }
}




