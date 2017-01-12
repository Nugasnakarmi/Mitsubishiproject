#include "globals.h"

#include "connect.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "passworderror.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
QString userName,passWord;
void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    userName = ui->lineEdit->text();


}

void MainWindow::on_pushButton_clicked()
{if( userName == "1" and passWord == "1"){
    this->close();

        Connect c ;
        c.Open();
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

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    passWord = ui->lineEdit_2->text();
}
