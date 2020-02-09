#include "signup.h"
#include "ui_signup.h"
#include "login.h"
#include <QSqlQuery>
#include <QMessageBox>
signup::signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    setWindowTitle(tr("签到系统1.0"));
    setWindowIcon(QIcon("://9 (6).jpg"));
}

signup::~signup()
{
    delete ui;
}

void signup::on_pushButton_clicked()
{

    QSqlQuery q;
    //QString sno=q.value(0).toString();
    QString sname=ui->lineEdit->text();
    QString class1=ui->lineEdit_2->text();
    QString sno=ui->lineEdit_3->text();
    QString pwd=ui->lineEdit_4->text();
    q.exec(QString("select * from student where sname='%1'").arg(sname));
    if(q.size()>0)
    {
        QMessageBox::warning(this,"warn","用户名已存在");
    }
    else
    {
        q.exec(QString("insert into student values('%1','%2','%3','%4')").arg(sno).arg(sname).arg(class1).arg(pwd));
        QMessageBox::warning(this,"warn","创建成功");
    }
}
