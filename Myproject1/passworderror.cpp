#include "passworderror.h"
#include "ui_passworderror.h"
#include "globals.h"
#include "dialog.h"
#include <QtSql>
#include <QtCore/QCoreApplication>
#include <QtDebug>

passworderror::passworderror(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::passworderror)
{
    ui->setupUi(this);
}

passworderror::~passworderror()
{
    delete ui;
}





void passworderror::on_lineEdit_textChanged(const QString &arg1)
{
    userName = ui->lineEdit->text();
}

void passworderror::on_lineEdit_2_textChanged(const QString &arg1)
{
    passWord = ui->lineEdit_2->text();
}

void passworderror::on_pushButton_clicked()
{
    if( userName == "1" and passWord == "1"){
        this->close();
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("localhost");
            db.setDatabaseName("mitsubishi");
            db.setUserName("root");
            db.setPassword("");
            bool ok = db.open();

            if (ok)
                qDebug()<<"Connected to the database";
            else
                qDebug()<<"failed to connect";
       Dialog *d = new Dialog();
       d->setWindowFlags(Qt::Window);
       d->exec();
        }
        else
        {
            this->close();
            passworderror *p = new passworderror();
            p->exec();
         }
}
