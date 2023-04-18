#include "addotherswidget.h"

AddOthersWidget::AddOthersWidget()
{
    addStuWidget=new QWidget(this);
    addStuWidget->setFixedSize(280,440);
    addStuWidget->move(0,0);
    addStuWidget->show();

    addTeaWidget=new QWidget(this);
    addTeaWidget->setFixedSize(280,440);
    addTeaWidget->move(0,0);
    addTeaWidget->hide();

    //单选框
    QRadioButton * stuGroup=new QRadioButton(this);
    QRadioButton * teaGroup=new QRadioButton(this);


    QPushButton * stuBut=new QPushButton(this);
    QPushButton * teaBut=new QPushButton(this);
    stuBut->setFixedSize(120,60);
    stuBut->setText("添加学生");
    stuBut->move(330,200);
    stuBut->show();

    teaBut->setFixedSize(120,60);
    teaBut->setText("添加教师");
    teaBut->move(330,200);
    teaBut->hide();

    stuGroup->setText("添加学生");
    stuGroup->move(330,50);
    stuGroup->setFocusPolicy(Qt::NoFocus);
    stuGroup->setChecked(1);

    teaGroup->setText("添加教师");
    teaGroup->move(330,100);
    teaGroup->setFocusPolicy(Qt::NoFocus);

    connect(stuGroup,&QRadioButton::clicked,[=](){
        teaBut->hide();
        stuBut->show();
        addStuWidget->show();
        addTeaWidget->hide();
    });
    connect(teaGroup,&QRadioButton::clicked,[=](){
        stuBut->hide();
        teaBut->show();
        addTeaWidget->show();
        addStuWidget->hide();

    });
    connect(stuBut,&QPushButton::clicked,[=](){
        addStuFunc();
    });
    connect(teaBut,&QPushButton::clicked,[=](){
        addTeaFunc();
    });


    initStuLine();
    initTeaLine();

    addStuWidget->setFocus();



}

void AddOthersWidget::initStuLine()
{

    for(int i=0;i<Student::showNum;++i)
    {
        QRegExp exp("");

        if(i==0)
        {
            idLine=new QLineEdit(addStuWidget);
            idLine->setFixedSize(lineWidth,lineHeight);
            idLine->move(30,i*60+30);
            idLine->setPlaceholderText("id：");
            exp.setPattern("^[0-9]*$");
            idLine->setValidator(new QRegExpValidator(exp,addStuWidget));
            idLine->show();
        }
        else if(i==1){
            nameLine=new QLineEdit(addStuWidget);
            nameLine->setFixedSize(lineWidth,lineHeight);
            nameLine->move(30,i*60+30);
            nameLine->setPlaceholderText("姓名：");
            nameLine->show();

        }
        else if(i==2)
        {
            genderComboBox = new QComboBox(addStuWidget);
            genderComboBox->setFixedSize(lineWidth,lineHeight);
            genderComboBox->move(30,i*60+30);
            genderComboBox->addItem("男");
            genderComboBox->addItem("女");
            genderComboBox->setCurrentIndex(0);
            genderComboBox->show();

        }
        else if(i==3)
        {
            teleLine=new QLineEdit(addStuWidget);
            teleLine->setFixedSize(lineWidth,lineHeight);
            teleLine->move(30,i*60+30);
            teleLine->setPlaceholderText("电话：");
            exp.setPattern("^[0-9]*$");
            teleLine->setValidator(new QRegExpValidator(exp,addStuWidget));
            teleLine->show();

        }
        else if(i==4){
            placeLine=new QLineEdit(addStuWidget);
            placeLine->setFixedSize(lineWidth,lineHeight);
            placeLine->move(30,i*60+30);
            placeLine->setPlaceholderText(QString("地址："));
            placeLine->show();
        }
        else if(i==5){
            classLine=new QLineEdit(addStuWidget);
            classLine->setFixedSize(lineWidth,lineHeight);
            classLine->move(30,i*60+30);
            classLine->setPlaceholderText("班级：");
            classLine->show();
        }
        else if(i==6){
            fileComboBox = new QComboBox(addStuWidget);
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

void AddOthersWidget::initTeaLine()
{
    for(int i=0;i<Teacher::showNum;++i)
    {
        QRegExp exp("");

        if(i==0)
        {
            idLine2=new QLineEdit(addTeaWidget);
            idLine2->setFixedSize(lineWidth,lineHeight);
            idLine2->move(30,i*60+30);
            idLine2->setPlaceholderText("id：");
            exp.setPattern("^[0-9]*$");
            idLine2->setValidator(new QRegExpValidator(exp,addTeaWidget));
            idLine2->show();
        }
        else if(i==1){
            nameLine2=new QLineEdit(addTeaWidget);
            nameLine2->setFixedSize(lineWidth,lineHeight);
            nameLine2->move(30,i*60+30);
            nameLine2->setPlaceholderText("姓名：");
            nameLine2->show();

        }
        else if(i==2)
        {
            genderComboBox2 = new QComboBox(addTeaWidget);
            genderComboBox2->setFixedSize(lineWidth,lineHeight);
            genderComboBox2->move(30,i*60+30);
            genderComboBox2->addItem("男");
            genderComboBox2->addItem("女");
            genderComboBox2->setCurrentIndex(0);
            genderComboBox2->show();

        }
        else if(i==3)
        {
            teleLine2=new QLineEdit(addTeaWidget);
            teleLine2->setFixedSize(lineWidth,lineHeight);
            teleLine2->move(30,i*60+30);
            teleLine2->setPlaceholderText("电话：");
            exp.setPattern("^[0-9]*$");
            teleLine2->setValidator(new QRegExpValidator(exp,addTeaWidget));
            teleLine2->show();

        }
        else if(i==4){
            classLine2=new QLineEdit(addTeaWidget);
            classLine2->setFixedSize(lineWidth,lineHeight);
            classLine2->move(30,i*60+30);
            classLine2->setPlaceholderText("班级：");
            classLine2->show();
        }
    }

}

void AddOthersWidget::addStuFunc()
{
    Student changeStu;

    qDebug()<<"add student yes";

    QString temp;
    temp=idLine->text();
    if(temp.isEmpty()==false){changeStu.id=idLine->text().toLongLong();}
    else{QMessageBox::warning(this," ","id不为空！");return;}
    temp=nameLine->text();
    if(temp.isEmpty()==false){changeStu.name=nameLine->text();}
    else{QMessageBox::warning(this," ","姓名不为空！");return;}
    changeStu.gender=(genderComboBox->currentIndex()==0)?1:0;
    temp=teleLine->text();
    if(temp.isEmpty()==false){changeStu.telephone=teleLine->text().toLongLong();}
    else{QMessageBox::warning(this," ","手机号不为空！");return;}
    temp=placeLine->text();
    if(temp.isEmpty()==false){changeStu.place=placeLine->text();}
    else{QMessageBox::warning(this," ","地址不为空！");return;}
    temp=classLine->text();
    if(temp.isEmpty()==false){changeStu.classname=classLine->text();}
    else{QMessageBox::warning(this," ","班级不为空！");return;}
    changeStu.field=fileIndexMap[fileComboBox->currentIndex()];


    QSqlQuery query;

    QString intoStr=
            "INSERT INTO "+TableString().tableVec.at(0)+
            "(id,password,name,gender,telephone,place,field,classname)"+
            "VALUES("+
            QString::number(changeStu.id)+",'"+
            "123456"+"','"+
            changeStu.name+"',"+
            QString::number(changeStu.gender)+","+
            QString::number(changeStu.telephone)+",'"+
            changeStu.place+"',"+
            QString::number(changeStu.field)+",'"+
            changeStu.classname+"'"
            +");";
    query.prepare(intoStr);

    query.exec();



    QMessageBox::warning(this," ","添加成功！初始密码为123456");



}

void AddOthersWidget::addTeaFunc()
{
    Teacher changeTea;

    qDebug()<<"add teacher yes";

    QString temp;
    temp=idLine2->text();
    if(temp.isEmpty()==false){changeTea.id=idLine2->text().toLongLong();}
    else{QMessageBox::warning(this," ","id不为空！");return;}
    temp=nameLine2->text();
    if(temp.isEmpty()==false){changeTea.name=nameLine2->text();}
    else{QMessageBox::warning(this," ","姓名不为空！");return;}
    changeTea.gender=(genderComboBox2->currentIndex()==0)?1:0;
    temp=teleLine2->text();
    if(temp.isEmpty()==false){changeTea.telephone=teleLine2->text().toLongLong();}
    else{QMessageBox::warning(this," ","手机号不为空！");return;}
    temp=classLine2->text();
    if(temp.isEmpty()==false){changeTea.classname=classLine2->text();}
    else{QMessageBox::warning(this," ","班级不为空！");return;}

    QSqlQuery query;

    QString intoStr=
            "INSERT INTO "+TableString().tableVec.at(1)+
            "(id,password,name,gender,telephone,classname)"+
            "VALUES("+
            QString::number(changeTea.id)+",'"+
            "123456"+"','"+
            changeTea.name+"',"+
            QString::number(changeTea.gender)+","+
            QString::number(changeTea.telephone)+",'"+
            changeTea.classname+"'"
            +");";
    query.prepare(intoStr);

    query.exec();

    QMessageBox::warning(this," ","添加成功！初始密码为123456");
}
