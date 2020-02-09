#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QCheckBox>
#include <QDateTime>
#include <QMessageBox>
#include "person.h"

Widget::Widget(QWidget *parent,QString sname) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->sname=sname;
    datatotable("select * from student");
    displayclass();
    displaysno();

    connect(ui->tableWidget,QTableWidget::cellDoubleClicked,[=](int r,int c){
        Person*p=new Person;
        p->init(ui->tableWidget->item(r,0)->text(),ui->tableWidget->item(r,1)->text());
        p->show();
    });
    setWindowTitle(tr("签到系统1.0"));
    setWindowIcon(QIcon("://9 (6).jpg"));


}
//按照班级显示
void Widget::displayclass()
{
    QSqlQuery q4;
    q4.exec("select distinct class1 from student");
    ui->comboBox->addItem("全部班级");
    while(q4.next())
    {
       ui->comboBox->addItem(q4.value(0).toString());
    }
    connect(ui->comboBox,QComboBox::currentTextChanged,[=](QString text){
        if(text=="全部班级")
        {
           datatotable("select * from student");
        }
        else
        {
           datatotable(QString("select * from student where class1='%1'").arg(text));
        }

    });
}
//按照学号查找显示
void Widget::displaysno()
{
    connect(ui->pushButton,QPushButton::clicked,[=](){
        if(ui->lineEdit->text().isEmpty())
        {
            QMessageBox::warning(this,"warn","您输入为空");
        }
        else
        {
            datatotable(QString("select * from student where sno like '%1'").arg(ui->lineEdit->text()));
        }

    });

}
//将数据显示到表格
void Widget::datatotable(QString sql)
{
    qDebug()<<this->sname;
    QSqlQuery q;
    q.exec(QString("select sno from student where sname='%1'").arg(this->sname));
    q.next();
    QString curSno=q.value(0).toString();
    if(q.exec(sql))
    {
        ui->tableWidget->setRowCount(q.size());
        int i=0;
        while(q.next())
        {
            QCheckBox *c=new QCheckBox("未签到");
            QString sno=q.value(0).toString();
            QSqlQuery q3;
            q3.exec(QString("select signTime from signInfo "
                            "where sno=%1 and date(signTime)=curdate()"
                            "order by signtime desc;").arg(sno));
            q3.next();

            if(sno!=curSno)
            {
                c->setDisabled(true);
            }
            if(q3.size())
            {
                c->setText("已签到");
                c->setDisabled(true);
                c->setChecked(true);
                ui->tableWidget->setItem(i,4,new QTableWidgetItem(q3.value(0).toString()));
            }
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(sno));//学号
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(q.value(1).toString()));//姓名
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(q.value(2).toString()));//班级
            ui->tableWidget->setCellWidget(i,3,c);



            connect(c,QCheckBox::clicked,[=](){
               //修改控件本身的状态
                c->setText("已签到");
                c->setDisabled(true);

               //向表格中添加本人签到时间
                ui->tableWidget->setItem(i,4,new QTableWidgetItem(QDateTime::currentDateTime().toString()));
               //向数据库中插入一条数据
                QSqlQuery q1;
                qDebug()<<q1.exec(QString("insert into signInfo values(%1,now())").arg(sno));
            });
            i++;
        }
    }
}

Widget::~Widget()
{
    delete ui;
}
