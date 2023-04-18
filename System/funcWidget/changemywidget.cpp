#include "changemywidget.h"


ChangeMyWidget::ChangeMyWidget()
{
    saveBut=new QPushButton(this);
    saveBut->setFixedSize(120,50);
    saveBut->setText("保存信息");
    saveBut->move(300,30);

    changePassBut=new QPushButton(this);
    changePassBut->setFixedSize(120,50);
    changePassBut->move(300,130);
    changePassBut->setText("更改密码");

    changePassWidget=new QWidget;
    changePassWidget->setFixedSize(300,300);
    changePassWidget->move(this->x(),this->y());
    changePassWidget->setWindowIcon(QIcon(":/res/startIcon.png"));
    changePassWidget->setWindowTitle("重设密码");
    changePassWidget->hide();



    oldPass=new QLineEdit(changePassWidget);
    oldPass->setFixedSize(lineWidth,lineHeight);
    oldPass->setPlaceholderText("输入旧密码...");
    oldPass->move(60,30);

    newPass=new QLineEdit(changePassWidget);
    newPass->setFixedSize(lineWidth,lineHeight);
    newPass->setPlaceholderText("输入新密码...");
    newPass->move(60,80);

    newPassToo=new QLineEdit(changePassWidget);
    newPassToo->setFixedSize(lineWidth,lineHeight);
    newPassToo->setPlaceholderText("再次输入新密码...");
    newPassToo->move(60,130);


    QPushButton * newPassPushBut=new QPushButton(changePassWidget);
    newPassPushBut->setFixedSize(120,60);
    newPassPushBut->setText("提交");
    newPassPushBut->move(90,200);


    connect(saveBut,&QPushButton::clicked,[=](){
        if(changeStuPtr!=nullptr){saveFunc(Student());}
        else if(changeTeaPtr!=nullptr){saveFunc(Teacher());}
        else if(changeAdmPtr!=nullptr){saveFunc(Administer());}
    });
    connect(changePassBut,&QPushButton::clicked,[=](){
        QRect deskRect = QApplication::desktop()->availableGeometry();
        changePassWidget->move(deskRect.width()*0.5-changePassWidget->width()*0.5,deskRect.height()*0.5-changePassWidget->height()*0.5);

        //设置窗口置顶
        ::SetWindowPos(HWND(changePassWidget->winId()), HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);

        ::SetWindowPos(HWND(changePassWidget->winId()), HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);

        changePassWidget->show();
    });
    connect(newPassPushBut,&QPushButton::clicked,[=](){
        if(changeStuPtr!=nullptr){changePassFunc(0);}
        else if(changeTeaPtr!=nullptr){changePassFunc(1);}
        else if(changeAdmPtr!=nullptr){changePassFunc(2);}
    });
}

ChangeMyWidget::~ChangeMyWidget()
{
    delete changeStuPtr;
    delete changeTeaPtr;
    delete changePassWidget;
}
void ChangeMyWidget::func(Student *stu)
{
    if(stu==nullptr){return;}
    if(setEnd==true){return;}
    setEnd=true;
    changeStuPtr=new Student;
    *changeStuPtr=*stu;
    for(int i=1;i<Student::showNum;++i)
    {
        QRegExp exp("");

        if(i==1){
            nameLine=new QLineEdit(this);
            nameLine->setFixedSize(lineWidth,lineHeight);
            nameLine->move(30,i*60-30);
            nameLine->setPlaceholderText("姓名："+stu->name);
            nameLine->show();

        }
        else if(i==2)
        {
            genderComboBox = new QComboBox(this);
            genderComboBox->setFixedSize(lineWidth,lineHeight);
            genderComboBox->move(30,i*60-30);
            genderComboBox->addItem("男");
            genderComboBox->addItem("女");
            genderComboBox->setCurrentIndex((stu->gender==1)?0:1);
            genderComboBox->show();

        }
        else if(i==3)
        {
            teleLine=new QLineEdit(this);
            teleLine->setFixedSize(lineWidth,lineHeight);
            teleLine->move(30,i*60-30);
            teleLine->setPlaceholderText("电话："+QString::number(stu->telephone));

            exp.setPattern("^[0-9]*$");
            teleLine->setValidator(new QRegExpValidator(exp,this));
            teleLine->show();

        }
        else if(i==4){
            placeLine=new QLineEdit(this);
            placeLine->setFixedSize(lineWidth,lineHeight);
            placeLine->move(30,i*60-30);
            placeLine->setPlaceholderText(QString("地址：")+stu->place);
            placeLine->show();
        }
        else if(i==5){
            classLine=new QLineEdit(this);
            classLine->setFixedSize(lineWidth,lineHeight);
            classLine->move(30,i*60-30);
            classLine->setPlaceholderText("班级："+stu->classname);
            classLine->show();
        }
        else if(i==6){
            fileComboBox = new QComboBox(this);
            fileComboBox->setFixedSize(lineWidth,lineHeight);
            fileComboBox->move(30,i*60-30);


            QSqlQuery query;
            query.prepare("SELECT * FROM file");
            query.exec();
            int index=0;
            int findIn=0;
            while(query.next()){
                fileIndexMap.insert(index,query.value("id").toLongLong());
                fileComboBox->addItem(query.value("name").toString());
                if(query.value("id").toLongLong()==stu->field){
                    findIn=index;
                }
                ++index;
            }
            fileComboBox->setCurrentIndex(findIn);
            fileComboBox->show();
        }
    }


}

void ChangeMyWidget::func(Teacher *tea)
{
    if(tea==nullptr){return;}
    if(setEnd==true){return;}
    setEnd=true;
    changeTeaPtr=new Teacher;
    *changeTeaPtr=*tea;
    for(int i=1;i<Teacher::showNum;++i)
    {
        QRegExp exp("");

        if(i==1){
            nameLine=new QLineEdit(this);
            nameLine->setFixedSize(lineWidth,lineHeight);
            nameLine->move(30,i*60-30);
            nameLine->setPlaceholderText("姓名："+tea->name);
            nameLine->show();

        }
        else if(i==2)
        {
            genderComboBox = new QComboBox(this);
            genderComboBox->setFixedSize(lineWidth,lineHeight);
            genderComboBox->move(30,i*60-30);
            genderComboBox->addItem("男");
            genderComboBox->addItem("女");
            genderComboBox->setCurrentIndex((tea->gender==1)?0:1);
            genderComboBox->show();

        }
        else if(i==3)
        {
            teleLine=new QLineEdit(this);
            teleLine->setFixedSize(lineWidth,lineHeight);
            teleLine->move(30,i*60-30);
            teleLine->setPlaceholderText("电话："+QString::number(tea->telephone));

            exp.setPattern("^[0-9]*$");
            teleLine->setValidator(new QRegExpValidator(exp,this));
            teleLine->show();

        }
        else if(i==4){
            classLine=new QLineEdit(this);
            classLine->setFixedSize(lineWidth,lineHeight);
            classLine->move(30,i*60-30);
            classLine->setPlaceholderText("班级："+tea->classname);
            classLine->show();
        }

    }
}

void ChangeMyWidget::func(Administer *adm)
{

    if(adm==nullptr){return;}
    if(setEnd==true){return;}
    setEnd=true;
    changeAdmPtr=new Administer;
    *changeAdmPtr=*adm;
    for(int i=1;i<Administer::showNum;++i)
    {
        if(i==1){
            nameLine=new QLineEdit(this);
            nameLine->setFixedSize(lineWidth,lineHeight);
            nameLine->move(30,i*60-30);
            nameLine->setPlaceholderText("姓名："+adm->name);
            nameLine->show();

        }

    }

}

void ChangeMyWidget::saveFunc(Student)
{
    qDebug()<<"save yes";

    QString temp;
    temp=nameLine->text();
    if(temp.isEmpty()==false){changeStuPtr->name=nameLine->text();}
    changeStuPtr->gender=(genderComboBox->currentIndex()==0)?1:0;
    temp=teleLine->text();
    if(temp.isEmpty()==false){changeStuPtr->telephone=teleLine->text().toLongLong();}
    temp=placeLine->text();
    if(temp.isEmpty()==false){changeStuPtr->place=placeLine->text();}
    temp=classLine->text();
    if(temp.isEmpty()==false){changeStuPtr->classname=classLine->text();}
    changeStuPtr->field=fileIndexMap[fileComboBox->currentIndex()];

    QSqlQuery query;
    query.prepare("DELETE FROM "+TableString().tableVec.at(0)+" where id = "+QString::number(changeStuPtr->id));
    query.exec();

    QString intoStr=
            "INSERT INTO "+TableString().tableVec.at(0)+
            "(id,password,name,gender,telephone,place,field,classname)"+
            "VALUES("+
            QString::number(changeStuPtr->id)+",'"+
            changeStuPtr->password+"','"+
            changeStuPtr->name+"',"+
            QString::number(changeStuPtr->gender)+","+
            QString::number(changeStuPtr->telephone)+",'"+
            changeStuPtr->place+"',"+
            QString::number(changeStuPtr->field)+",'"+
            changeStuPtr->classname+"'"
            +");";
    query.prepare(intoStr);

    query.exec();

    QMessageBox::warning(this," ","保存成功！");
}

void ChangeMyWidget::saveFunc(Teacher)
{
    qDebug()<<"save yes";

    QString temp;
    temp=nameLine->text();
    if(temp.isEmpty()==false){changeTeaPtr->name=nameLine->text();}
    changeTeaPtr->gender=(genderComboBox->currentIndex()==0)?1:0;
    temp=teleLine->text();
    if(temp.isEmpty()==false){changeTeaPtr->telephone=teleLine->text().toLongLong();}
    temp=classLine->text();
    if(temp.isEmpty()==false){changeTeaPtr->classname=classLine->text();}

    QSqlQuery query;
    query.prepare("DELETE FROM "+TableString().tableVec.at(1)+" where id = "+QString::number(changeTeaPtr->id));
    query.exec();

    QString intoStr=
            "INSERT INTO "+TableString().tableVec.at(1)+
            "(id,password,name,gender,telephone,classname)"+
            "VALUES("+
            QString::number(changeTeaPtr->id)+",'"+
            changeTeaPtr->password+"','"+
            changeTeaPtr->name+"',"+
            QString::number(changeTeaPtr->gender)+","+
            QString::number(changeTeaPtr->telephone)+",'"+
            changeTeaPtr->classname+"'"
            +");";
    query.prepare(intoStr);

    query.exec();

    QMessageBox::warning(this," ","保存成功！");
}



void ChangeMyWidget::saveFunc(Administer)
{
    qDebug()<<"save yes";

    QString temp;
    temp=nameLine->text();
    if(temp.isEmpty()==false){changeAdmPtr->name=nameLine->text();}

    QSqlQuery query;
    query.prepare("DELETE FROM "+TableString().tableVec.at(2)+" where id = "+QString::number(changeAdmPtr->id));
    query.exec();

    QString intoStr=
            "INSERT INTO "+TableString().tableVec.at(2)+
            "(id,password,name)"+
            "VALUES("+
            QString::number(changeAdmPtr->id)+",'"+
            changeAdmPtr->password+"','"+
            changeAdmPtr->name+"'"
            +");";
    qDebug()<<intoStr;
    query.prepare(intoStr);

    query.exec();

    QMessageBox::warning(this," ","保存成功！");

}


void ChangeMyWidget::changePassFunc(int cardId)
{

    QString oldStr=oldPass->text();
    QString newStr=newPass->text();
    QString newStrToo=newPassToo->text();

    QSqlQuery query;
    if(cardId==0)
        query.prepare("SELECT password FROM "+TableString().tableVec.at(cardId)+" where id = "+QString::number(changeStuPtr->id)+";");
    else if(cardId==1)
        query.prepare("SELECT password FROM "+TableString().tableVec.at(cardId)+" where id = "+QString::number(changeTeaPtr->id)+";");
    else if(cardId==2)
        query.prepare("SELECT password FROM "+TableString().tableVec.at(cardId)+" where id = "+QString::number(changeAdmPtr->id)+";");
    query.exec();
    query.next();
    if(query.size()==0){
        QMessageBox::critical(this," ","出错！");
        return;
    }
    else{
        qDebug()<<query.value("find password").toString();
    }

    if(oldStr.isEmpty()||newStr.isEmpty()||newStrToo.isEmpty())
    {
        QMessageBox::warning(this," ","输入不能为空！");
        return;
    }
    if(oldStr.compare(query.value("password").toString())!=0){
        QMessageBox::warning(this,"","旧密码错误！");
        return;
    }
    if(newStr.compare(newStrToo)!=0){
        QMessageBox::warning(this,"","新旧密码不一致！");
        return;
    }
    else
    {

    QSqlQuery query;
    if(cardId==0)
            query.prepare("UPDATE "+TableString().tableVec.at(cardId)+" SET password = '"+newStr+"' WHERE id = "+QString::number(changeStuPtr->id)+";");
    else if(cardId==1)
            query.prepare("UPDATE "+TableString().tableVec.at(cardId)+" SET password = '"+newStr+"' WHERE id = "+QString::number(changeTeaPtr->id)+";");
    else if(cardId==2)
            query.prepare("UPDATE "+TableString().tableVec.at(cardId)+" SET password = '"+newStr+"' WHERE id = "+QString::number(changeAdmPtr->id)+";");
    query.exec();
    QMessageBox::warning(this,"","修改成功！");

    }

}
