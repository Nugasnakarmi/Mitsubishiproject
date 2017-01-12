#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include <QtCore/QCoreApplication>
#include <QtGui>
#include <QtSql>
#include<QtDebug>
#include<QTableView>
#include<QModelIndex>
#include<QAbstractItemView>
#include<QTableWidgetItem>
#include <QSqlError>
#include<QDateTime>
#include "connect.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    QSqlQueryModel * model;
    QString  searchItem,VRN, Model , VIN, CuNo, MoNo, DrCo, Date1, Jorder, Jdone;

QSqlQuery  *query;
    explicit Dialog(QWidget *parent = 0) ;
    ~Dialog();

private slots:
    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_tableView_clicked(const QModelIndex &index);

    void on_textBrowser_sourceChanged(const QUrl &arg1);

    void on_Search_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_clearPush_clicked();

    void on_AddnewRecPush_clicked();

    void on_Add_clicked();

    void on_updatepush_clicked();
    void getData();

private:

    Ui::Dialog *ui;
};

#endif // DIALOG_H
