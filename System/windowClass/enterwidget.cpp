#include "enterwidget.h"


EnterWidget::EnterWidget()
{

    //标题和图标
    this->setWindowTitle("登录");
    this->setWindowIcon(QIcon(WINDOW_START_ICON));
    this->setFixedSize(windowWidth,windowHeight);

    //设置窗口置顶
    ::SetWindowPos(HWND(this->winId()), HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);

    ::SetWindowPos(HWND(this->winId()), HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
    //初始位置屏幕居中
    QRect deskRect = QApplication::desktop()->availableGeometry();
    this->move(deskRect.width()*0.5-this->width()*0.5,deskRect.height()*0.5-this->height()*0.5);

    //输入框
    passLineEdit=new QLineEdit(this);
    idLineEdit=new QLineEdit(this);
    //说明标签
    QLabel * idLab=new QLabel(this);
    QLabel * passLab=new QLabel(this);
    QLabel * backLab=new QLabel(this);
    MouseLabel * mouseLab=new MouseLabel(QString(BIYAN_IMG),QString(YANJING_IMG));
    mouseLab->setParent(this);

    //按钮
    pushOn=new QPushButton(this);
    pushEn=new QPushButton(this);
    //单选框
    QRadioButton * stuGroup=new QRadioButton(this);
    QRadioButton * teaGroup=new QRadioButton(this);
    QRadioButton * admGroup=new QRadioButton(this);

    //img
    QPixmap pix(LOGO_IMG);
    pix=pix.scaled(pix.width()*0.6,pix.height()*0.6);
    //字体
    QFont font;
    font.setFamily("黑体");
    font.setPointSize(10);
    QFont font2;
    font2.setFamily("黑体");
    font2.setPointSize(8);
    //正则
    QRegExp regExpId( "^[0-9]*$" );
    QRegExp regExpPass("^[0-9a-zA-Z_]{1,}$");

    idLineEdit->setFixedSize(lineWidth,lineHeight);
    idLineEdit->move((this->width()-idLineEdit->width())*0.5,80);
    idLineEdit->setPlaceholderText("请输入账号...");
    idLineEdit->setValidator(new QRegExpValidator(regExpId,this));

    passLineEdit->setFixedSize(lineWidth,lineHeight);
    passLineEdit->move((this->width()-idLineEdit->width())*0.5,130);
    passLineEdit->setPlaceholderText("请输入密码...");
    passLineEdit->setEchoMode(QLineEdit::Password);
    passLineEdit->setValidator(new QRegExpValidator(regExpPass,this));


    stuGroup->setText("学生");
    stuGroup->move(passLineEdit->x(),passLineEdit->y()+40);
    stuGroup->setFocusPolicy(Qt::NoFocus);
    teaGroup->setText("教师");
    teaGroup->move(stuGroup->x()+80,stuGroup->y());
    teaGroup->setFocusPolicy(Qt::NoFocus);
    admGroup->setText("管理");
    admGroup->move(teaGroup->x()+80,teaGroup->y());
    admGroup->setFocusPolicy(Qt::NoFocus);

    stuGroup->setChecked(1);


    idLab->setText("账户：");
    passLab->setText("密码：");
    backLab->setPixmap(pix);

    idLab->setFixedSize(lineHeight*2,lineHeight);
    passLab->setFixedSize(lineHeight*2,lineHeight);
    backLab->setFixedSize(pix.width(),pix.height());
    mouseLab->setFixedSize(25,25);

    idLab->setFont(font);
    idLab->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    passLab->setFont(font);
    passLab->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    backLab->setScaledContents(true);


    idLab->move(idLineEdit->x()-50,80);
    passLab->move(passLineEdit->x()-50,130);
    backLab->move((this->width()-backLab->width())*0.5,2);
    mouseLab->move(passLineEdit->x()+passLineEdit->width()+4,passLineEdit->y()+4);

    pushOn->setText("登录");
    pushOn->setFixedSize(90,40);
    pushOn->move((this->width()-idLineEdit->width())*0.5,200);
    pushOn->setFocusPolicy(Qt::NoFocus);

    pushEn->setText("注册");
    pushEn->setFixedSize(90,40);
    pushEn->move(this->width()-(this->width()-idLineEdit->width())*0.5-pushEn->width(),200);
    pushEn->setFocusPolicy(Qt::NoFocus);

    //信号槽连接
    connect(mouseLab,&MouseLabel::mousePress,[=](bool showId){
        if(showId==true)
            passLineEdit->setEchoMode(QLineEdit::Password);
        else
            passLineEdit->setEchoMode(QLineEdit::Normal);
    });


    connect(stuGroup,&QRadioButton::clicked,[=](){cardId=0;});
    connect(teaGroup,&QRadioButton::clicked,[=](){cardId=1;});
    connect(admGroup,&QRadioButton::clicked,[=](){cardId=2;});

    connect(pushOn,&QPushButton::clicked,[=](){
        int personId=-1;
        if(findPerson(personId)){

            idLineEdit->clear();
            passLineEdit->clear();
            emit logon(cardId,personId);
        }
        else{

            if(idLineEdit->text().compare("")==0)QMessageBox::warning(this, " ", "账号不能为空！");
            else if(passLineEdit->text().compare("")==0)QMessageBox::warning(this, " ", "密码不能为空！");
            else QMessageBox::warning(this,"登陆失败","账号或密码有误！");
        }
    });
    connect(pushEn,&QPushButton::clicked,[=](){
        if(cardId==0){QMessageBox::warning(this," ","该功能未开放！");}
        else if(cardId==1){QMessageBox::warning(this," ","教师注册需要学校联系管理员！");}
        else if(cardId==2){QMessageBox::warning(this," ","管理员不允许注册！");}
        else{QMessageBox::warning(this," ","未知错误");}
    });
    this->idLineEdit->setFocus();
    update();
}

bool EnterWidget::findPerson(int & personId)
{
    int id = idLineEdit->text().toInt();
    QString pass=passLineEdit->text();

    QSqlQuery query;

    query.prepare(QString("SELECT id,password FROM "+TableString().tableVec.at(cardId)+" WHERE id IN(%1)").arg(id));
    query.exec();
    query.next();

    //id没找到 false
    if(query.value("id").toString()=="")
    {
        return false;
    }
    //id找到了 密码正确 true
    QString passFindStr=query.value("password").toString();
    if(passFindStr.compare(pass)==0)
    {
        personId=id;
        return true;
    }
    //id找到了 密码错误 false
    else
    {
        return false;
    }
    return false;

}
void EnterWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter(this);
//    QBrush br(QColor(0,0,255));
//    painter.setBrush(br);
//    painter.fillRect(0,0,this->width(),this->height(),QBrush(QColor(100,200,250,200)));

    painter.drawPixmap(0,0,this->width(),this->height(),QPixmap(STARTBACK_IMG));
}

void EnterWidget::mousePressEvent(QMouseEvent *ev)
{
    if(ev->buttons() & Qt::LeftButton)
    {
        canMove=true;
        myLocation=ev->globalPos()-this->pos();
    }

}

void EnterWidget::mouseMoveEvent(QMouseEvent *ev)
{
    if(canMove)this->move(ev->globalPos()-myLocation);
}

void EnterWidget::mouseReleaseEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev)
    canMove=false;

}

void EnterWidget::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key() == Qt::Key_Enter || ev->key() == Qt::Key_Return)
    {
        if(passLineEdit->text().compare("")==0){
            passLineEdit->setFocus();
        }
        else{
            emit pushOn->clicked();
        }
    }

}

