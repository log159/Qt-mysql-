#include "changeotherswidget.h"


ChangeOthersWidget::ChangeOthersWidget()
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
    //初始位置屏幕居中
    QRect deskRect = QApplication::desktop()->availableGeometry();

    changeStuWidget=new QWidget;
    changeStuWidget->setFixedSize(480,440);
    changeStuWidget->setWindowIcon(QIcon(WINDOW_START_ICON));
    changeStuWidget->setWindowTitle("更改学生信息");
    changeStuWidget->move(deskRect.width()*0.5-changeStuWidget->width()*0.5,deskRect.height()*0.5-changeStuWidget->height()*0.5);
    changeStuWidget->setFocusPolicy(Qt::NoFocus);
    changeStuWidget->hide();

    QPushButton * saveStuBut=new QPushButton(changeStuWidget);
    saveStuBut->setFixedSize(120,50);
    saveStuBut->setText("保存信息");
    saveStuBut->move(300,30);
    connect(saveStuBut,&QPushButton::clicked,[=](){saveStuFunc();});

    QPushButton * initStuPassBut=new QPushButton(changeStuWidget);
    initStuPassBut->setFixedSize(120,50);
    initStuPassBut->setText("重置密码");
    initStuPassBut->move(300,130);
    connect(initStuPassBut,&QPushButton::clicked,[=](){initStuPass();});


    changeTeaWidget=new QWidget;
    changeTeaWidget->setFixedSize(480,440);
    changeTeaWidget->setWindowIcon(QIcon(WINDOW_START_ICON));
    changeTeaWidget->setWindowTitle("更改教师信息");
    changeTeaWidget->move(deskRect.width()*0.5-changeTeaWidget->width()*0.5,deskRect.height()*0.5-changeTeaWidget->height()*0.5);
    changeTeaWidget->setFocusPolicy(Qt::NoFocus);
    changeTeaWidget->hide();


    QPushButton * saveTeaBut=new QPushButton(changeTeaWidget);
    saveTeaBut->setFixedSize(120,50);
    saveTeaBut->setText("保存信息");
    saveTeaBut->move(300,30);
    connect(saveTeaBut,&QPushButton::clicked,[=](){saveTeaFunc();});

    QPushButton * initTeaPassBut=new QPushButton(changeTeaWidget);
    initTeaPassBut->setFixedSize(120,50);
    initTeaPassBut->setText("重置密码");
    initTeaPassBut->move(300,130);
    connect(initTeaPassBut,&QPushButton::clicked,[=](){initTeaPass();});

    initChangeStuWidget();
    initChangeTeaWidget();




    connect(stuGroup,&QRadioButton::clicked,[=](){
        cardId=0;
        func();
    });
    connect(teaGroup,&QRadioButton::clicked,[=](){
        cardId=1;
        func();
    });
}

ChangeOthersWidget::~ChangeOthersWidget()
{
    delete changeStuWidget;
    delete changeTeaWidget;
    delete stuPtr;
    delete teaPtr;
}

void ChangeOthersWidget::initChangeStuWidget()
{
    for(int i=0;i<Student::showNum;++i)
    {
        QRegExp exp("");

        if(i==0)
        {
            idLine=new QLineEdit(changeStuWidget);
            idLine->setFixedSize(lineWidth,lineHeight);
            idLine->move(30,i*60+30);
            idLine->setPlaceholderText("id：");
            exp.setPattern("^[0-9]*$");
            idLine->setValidator(new QRegExpValidator(exp,changeStuWidget));
            idLine->show();
        }
        else if(i==1){
            nameLine=new QLineEdit(changeStuWidget);
            nameLine->setFixedSize(lineWidth,lineHeight);
            nameLine->move(30,i*60+30);
            nameLine->setPlaceholderText("姓名：");
            nameLine->show();

        }
        else if(i==2)
        {
            genderComboBox = new QComboBox(changeStuWidget);
            genderComboBox->setFixedSize(lineWidth,lineHeight);
            genderComboBox->move(30,i*60+30);
            genderComboBox->addItem("男");
            genderComboBox->addItem("女");
            genderComboBox->setCurrentIndex(0);
            genderComboBox->show();

        }
        else if(i==3)
        {
            teleLine=new QLineEdit(changeStuWidget);
            teleLine->setFixedSize(lineWidth,lineHeight);
            teleLine->move(30,i*60+30);
            teleLine->setPlaceholderText("电话：");
            exp.setPattern("^[0-9]*$");
            teleLine->setValidator(new QRegExpValidator(exp,changeStuWidget));
            teleLine->show();

        }
        else if(i==4){
            placeLine=new QLineEdit(changeStuWidget);
            placeLine->setFixedSize(lineWidth,lineHeight);
            placeLine->move(30,i*60+30);
            placeLine->setPlaceholderText(QString("地址："));
            placeLine->show();
        }
        else if(i==5){
            classLine=new QLineEdit(changeStuWidget);
            classLine->setFixedSize(lineWidth,lineHeight);
            classLine->move(30,i*60+30);
            classLine->setPlaceholderText("班级：");
            classLine->show();
        }
        else if(i==6){
            fileComboBox = new QComboBox(changeStuWidget);
            fileComboBox->setFixedSize(lineWidth,lineHeight);
            fileComboBox->move(30,i*60+30);

            QSqlQuery query;
            query.prepare("SELECT * FROM file");
            query.exec();
            int index=0;
            while(query.next()){
                fileIndexMap.insert(index,query.value("id").toLongLong());
                fileComboBox->addItem(query.value("name").toString());
                ++index;
            }
            fileComboBox->setCurrentIndex(0);
            fileComboBox->show();
        }
    }
}

void ChangeOthersWidget::initChangeTeaWidget()
{
    for(int i=0;i<Teacher::showNum;++i)
    {
        QRegExp exp("");

        if(i==0)
        {
            idLine2=new QLineEdit(changeTeaWidget);
            idLine2->setFixedSize(lineWidth,lineHeight);
            idLine2->move(30,i*60+30);
            idLine2->setPlaceholderText("id：");
            exp.setPattern("^[0-9]*$");
            idLine2->setValidator(new QRegExpValidator(exp,changeTeaWidget));
            idLine2->show();
        }
        else if(i==1){
            nameLine2=new QLineEdit(changeTeaWidget);
            nameLine2->setFixedSize(lineWidth,lineHeight);
            nameLine2->move(30,i*60+30);
            nameLine2->setPlaceholderText("姓名：");
            nameLine2->show();

        }
        else if(i==2)
        {
            genderComboBox2 = new QComboBox(changeTeaWidget);
            genderComboBox2->setFixedSize(lineWidth,lineHeight);
            genderComboBox2->move(30,i*60+30);
            genderComboBox2->addItem("男");
            genderComboBox2->addItem("女");
            genderComboBox2->setCurrentIndex(0);
            genderComboBox2->show();

        }
        else if(i==3)
        {
            teleLine2=new QLineEdit(changeTeaWidget);
            teleLine2->setFixedSize(lineWidth,lineHeight);
            teleLine2->move(30,i*60+30);
            teleLine2->setPlaceholderText("电话：");
            exp.setPattern("^[0-9]*$");
            teleLine2->setValidator(new QRegExpValidator(exp,changeTeaWidget));
            teleLine2->show();

        }
        else if(i==4){
            classLine2=new QLineEdit(changeTeaWidget);
            classLine2->setFixedSize(lineWidth,lineHeight);
            classLine2->move(30,i*60+30);
            classLine2->setPlaceholderText("班级：");
            classLine2->show();
        }
    }


}

void ChangeOthersWidget::sendStuWidget(const QString & idStr)
{
    changeTeaWidget->hide();
    changeStuWidget->show();

    //设置窗口置顶
    ::SetWindowPos(HWND(changeStuWidget->winId()), HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);

    ::SetWindowPos(HWND(changeStuWidget->winId()), HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);

    delete stuPtr;
    stuPtr=new Student;

    QSqlQuery query;
    query.prepare("SELECT * FROM "+TableString().tableVec.at(cardId)+" where id = "+idStr+";");
    query.exec();
    query.next();
    stuPtr->id=query.value("id").toLongLong();
    stuPtr->password=query.value("password").toString();
    stuPtr->name=query.value("name").toString();
    stuPtr->gender=query.value("gender").toInt();
    stuPtr->telephone=query.value("telephone").toLongLong();
    stuPtr->place=query.value("place").toString();
    stuPtr->field=query.value("field").toLongLong();
    stuPtr->classname=query.value("classname").toString();

    for(int i=0;i<Student::showNum;++i)
    {
        if(i==0){idLine->setText(QString::number(stuPtr->id));}
        else if(i==1){nameLine->setText(stuPtr->name);}
        else if(i==2){genderComboBox->setCurrentIndex((stuPtr->gender==1)?0:1);}
        else if(i==3){teleLine->setText(QString::number(stuPtr->telephone));}
        else if(i==4){placeLine->setText(stuPtr->place);}
        else if(i==5){classLine->setText(stuPtr->classname);}
        else if(i==6){
            QSqlQuery query;
            query.prepare("SELECT * FROM file");
            query.exec();
            int index=0;
            int findIn=0;
            while(query.next()){
                fileIndexMap.insert(index,query.value("id").toLongLong());
                if(query.value("id").toLongLong()==stuPtr->field){
                    findIn=index;
                }
                ++index;
            }
            fileComboBox->setCurrentIndex(findIn);
        }
    }

}

void ChangeOthersWidget::sendTeaWidget(const QString & idStr)
{
    changeStuWidget->hide();
    changeTeaWidget->show();


    //设置窗口置顶
    ::SetWindowPos(HWND(changeTeaWidget->winId()), HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);

    ::SetWindowPos(HWND(changeTeaWidget->winId()), HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);

    delete teaPtr;
    teaPtr=new Teacher;


    QSqlQuery query;
    query.prepare("SELECT * FROM "+TableString().tableVec.at(cardId)+" where id = "+idStr+";");
    query.exec();
    query.next();
    teaPtr->id=query.value("id").toLongLong();
    teaPtr->password=query.value("password").toString();
    teaPtr->name=query.value("name").toString();
    teaPtr->gender=query.value("gender").toInt();
    teaPtr->telephone=query.value("telephone").toLongLong();
    teaPtr->classname=query.value("classname").toString();

    for(int i=0;i<Teacher::showNum;++i)
    {
        if(i==0){idLine2->setText(QString::number(teaPtr->id));}
        else if(i==1){nameLine2->setText(teaPtr->name);}
        else if(i==2){genderComboBox2->setCurrentIndex((teaPtr->gender==1)?0:1);}
        else if(i==3){teleLine2->setText(QString::number(teaPtr->telephone));}
        else if(i==4){classLine2->setText(teaPtr->classname);}
    }

}

void ChangeOthersWidget::saveStuFunc()
{
    qDebug()<<"save student yes";
    QSqlQuery query;
    query.prepare("DELETE FROM "+TableString().tableVec.at(0)+" where id = "+selectStuIndex+";");
    query.exec();


    QString temp;
    temp=idLine->text();
    if(temp.isEmpty()==false){stuPtr->id=idLine->text().toLongLong();}
    else{QMessageBox::warning(this," ","id不为空！");return;}
    temp=nameLine->text();
    if(temp.isEmpty()==false){stuPtr->name=nameLine->text();}
    else{QMessageBox::warning(this," ","姓名不为空！");return;}
    stuPtr->gender=(genderComboBox->currentIndex()==0)?1:0;
    temp=teleLine->text();
    if(temp.isEmpty()==false){stuPtr->telephone=teleLine->text().toLongLong();}
    else{QMessageBox::warning(this," ","手机号不为空！");return;}
    temp=placeLine->text();
    if(temp.isEmpty()==false){stuPtr->place=placeLine->text();}
    else{QMessageBox::warning(this," ","地址不为空！");return;}
    temp=classLine->text();
    if(temp.isEmpty()==false){stuPtr->classname=classLine->text();}
    else{QMessageBox::warning(this," ","班级不为空！");return;}
    stuPtr->field=fileIndexMap[fileComboBox->currentIndex()];


    QString intoStr=
            "INSERT INTO "+TableString().tableVec.at(0)+
            "(id,password,name,gender,telephone,place,field,classname)"+
            "VALUES("+
            QString::number(stuPtr->id)+",'"+
            stuPtr->password+"','"+
            stuPtr->name+"',"+
            QString::number(stuPtr->gender)+","+
            QString::number(stuPtr->telephone)+",'"+
            stuPtr->place+"',"+
            QString::number(stuPtr->field)+",'"+
            stuPtr->classname+"'"
            +");";
    query.prepare(intoStr);

    query.exec();

    QMessageBox::warning(this," ","学生信息修改成功！");


}

void ChangeOthersWidget::initStuPass()
{
    QSqlQuery query;
    query.prepare("UPDATE "+TableString().tableVec.at(0)+" SET password = '123456' WHERE id = "+selectStuIndex+";");
    query.exec();
    QMessageBox::warning(this,"","密码重置成功！");
}

void ChangeOthersWidget::saveTeaFunc()
{
    qDebug()<<"save teacher yes";

    QSqlQuery query;
    query.prepare("DELETE FROM "+TableString().tableVec.at(1)+" where id = "+selectTeaIndex+";");
    query.exec();


    QString temp;
    temp=idLine2->text();
    if(temp.isEmpty()==false){teaPtr->id=idLine2->text().toLongLong();}
    else{QMessageBox::warning(this," ","id不为空！");return;}
    temp=nameLine2->text();
    if(temp.isEmpty()==false){teaPtr->name=nameLine2->text();}
    else{QMessageBox::warning(this," ","姓名不为空！");return;}
    teaPtr->gender=(genderComboBox2->currentIndex()==0)?1:0;
    temp=teleLine2->text();
    if(temp.isEmpty()==false){teaPtr->telephone=teleLine2->text().toLongLong();}
    else{QMessageBox::warning(this," ","手机号不为空！");return;}
    temp=classLine2->text();
    if(temp.isEmpty()==false){teaPtr->classname=classLine2->text();}
    else{QMessageBox::warning(this," ","班级不为空！");return;}


    QString intoStr=
            "INSERT INTO "+TableString().tableVec.at(1)+
            "(id,password,name,gender,telephone,classname)"+
            "VALUES("+
            QString::number(teaPtr->id)+",'"+
            teaPtr->password+"','"+
            teaPtr->name+"',"+
            QString::number(teaPtr->gender)+","+
            QString::number(teaPtr->telephone)+",'"+
            teaPtr->classname+"'"
            +");";
    query.prepare(intoStr);

    query.exec();

    QMessageBox::warning(this," ","教师信息修改成功！");

}

void ChangeOthersWidget::initTeaPass()
{
    QSqlQuery query;
    query.prepare("UPDATE "+TableString().tableVec.at(1)+" SET password = '123456' WHERE id = "+selectTeaIndex+";");
    query.exec();
    QMessageBox::warning(this,"","密码重置成功！");

}
void ChangeOthersWidget::func()
{
    for(QVector<IndexLabel*>::iterator it=v_lab.begin();it!=v_lab.end();++it){delete *it;}
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
        IndexLabel * lab=new IndexLabel;
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
            lab->cardId=0;
            lab->idStr=query.value("id").toString();
        }
        else if(cardId==1)
        {
            allInfor="id："+query.value("id").toString()+
                    " 姓名："+query.value("name").toString()+
                    " 班级："+query.value("classname").toString()+
                    " 电话："+query.value("telephone").toString();
            lab->cardId=1;
            lab->idStr=query.value("id").toString();

        }
        lab->setText(allInfor);
        connect(lab,&IndexLabel::pass,[=](){
            if(lab->cardId==0){
                sendStuWidget(lab->idStr);
                selectStuIndex=lab->idStr;
            }
            else if(lab->cardId==1)
            {
                sendTeaWidget(lab->idStr);
                selectTeaIndex=lab->idStr;
            }


        });
        v_lab.push_back(lab);

        scroll_layout->addWidget(lab);
    }
    numLab->setText("find："+QString::number(v_lab.size())+"人");
}

void ChangeOthersWidget::keyPressEvent(QKeyEvent *ev)
{

    if(cardId!=0&&cardId!=1){
        return;
    }

    if(ev->key() == Qt::Key_Enter || ev->key() == Qt::Key_Return||ev->key()==Qt::Key_Space)
    {
        func();
    }
}
