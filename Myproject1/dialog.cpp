#include "dialog.h"
#include "ui_dialog.h"
#include "connect.h"
Connect d;




Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_tableView_activated(const QModelIndex &index)
{

}


void Dialog::on_pushButton_clicked()
{

     model = new QSqlQueryModel();

    d.Open();
    query = new QSqlQuery( d.db );
    query->prepare("select * from csv_db.tbl_name");
    query->exec();

    model->setQuery(*query);

    ui->tableView->setModel(model);
    d.close();
    qDebug()<<( model->rowCount());
}

void Dialog::on_Search_lineEdit_textChanged(const QString &arg1)
{
    searchItem = ui->Search_lineEdit->text();


model = new QSqlQueryModel();
    d.Open();

   query = new QSqlQuery( d.db );
    if(searchItem.length()>0 )

    query->prepare("select * from csv_db.tbl_name where VRN like '%"+searchItem+"%' or Model like '%"+searchItem+"%' or CustomerName like '%"+searchItem+"%' ");
   else
    query->prepare("select * from csv_db.tbl_name   ");

    query->exec();

    model->setQuery(*query);
    ui->tableView->setModel(model);
    qDebug()<<( model->rowCount());
    d.close();

}

void Dialog::on_tableView_clicked(const QModelIndex &index)
{

ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);




 QString VRN = (index.sibling( index.row(), 0).data().toString() );
 QString Model = (index.sibling( index.row(), 1).data().toString() );
 QString VIN = (index.sibling( index.row(), 2).data().toString() );
QString CuNo = (index.sibling( index.row(), 3).data().toString() );
 QString MoNo= (index.sibling( index.row(), 4).data().toString() );

 QString DrCo = (index.sibling( index.row(), 5).data().toString() );
 QDate Date = (index.sibling( index.row(), 6).data().toDate() );
 QString Date1 = Date.toString();
 QString Jorder = (index.sibling( index.row(), 7).data().toString() );
 QString Jdone = (index.sibling( index.row(), 8).data().toString() );

ui->VRN_lineEdit->setText( VRN );
ui->Model_lineEdit->setText( Model );
ui->VIN_lineEdit->setText( VIN );
ui->CustomerName_lineEdit->setText( CuNo );
ui->CMobileno_lineEdit->setText( MoNo );

ui->drivercontact_lineEdit->setText( DrCo );
ui->templineEdit->setText( Date1 );
//ui->dateCombobox->setItemText( 0,Date1 );
ui->Joborder_lineEdit->setText( Jorder );
ui->Jobdone_textEdit_2->setText( Jdone );



}

void Dialog::on_textBrowser_sourceChanged(const QUrl &arg1)
{

}





void Dialog::on_clearPush_clicked()
{

    ui->VRN_lineEdit->setText( "" );
    ui->Model_lineEdit->setText( "" );
    ui->VIN_lineEdit->setText( "" );
    ui->CustomerName_lineEdit->setText( "" );
    ui->CMobileno_lineEdit->setText( "" );

    ui->drivercontact_lineEdit->setText( "" );
    ui->templineEdit->setText( "" );
    //ui->dateCombobox->setItemText( 0,Date1 );
    ui->Joborder_lineEdit->setText( "" );
    ui->Jobdone_textEdit_2->setText( "" );
}

void Dialog::getData()
{
    VRN = ui->VRN_lineEdit->text();
    Model = ui->Model_lineEdit->text();
    VIN = ui->VIN_lineEdit->text();
    CuNo = ui->CustomerName_lineEdit->text();
    MoNo = ui->CMobileno_lineEdit->text();
    DrCo= ui->drivercontact_lineEdit->text(  );
    Date1= ui->templineEdit->text(  );
    //ui->dateCombobox->setItemText( 0,Date1 );
    Jorder=ui->Joborder_lineEdit->text(  );
    Jdone= ui->Jobdone_textEdit_2->toPlainText();
}




void Dialog::on_Add_clicked()
{
   getData();

    qDebug()<<(VRN);
      if( ( VRN != "") && (Date1 != "") )
     {
          d.Open();
      query = new QSqlQuery(d.db);//
      query->prepare("INSERT INTO csv_db.tbl_name ( VRN, Model , VIN , CustomerName, MobileNo,DriverContact, Date, Joborder, JobDone ) VALUES ( :VRN, :Model , :VIN , :CustomerName, :MobileNo, :DriverContact, :Date, :Joborder, :JobDone)");

      query->addBindValue(  VRN );
       query->addBindValue( Model );
        query->addBindValue(VIN );
        query->addBindValue( CuNo );
        query->addBindValue( MoNo );
        query->addBindValue( DrCo );
        query->addBindValue( Date1 );
        query->addBindValue(Jorder );
        query->addBindValue( Jdone );

      query->exec();
      qDebug() << (VRN)<<query->lastError();
      d.close();
      }
      else

       qDebug() <<"Error data not added";
}



void Dialog::on_updatepush_clicked()
{
getData();
}
