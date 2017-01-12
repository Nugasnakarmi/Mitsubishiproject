#include "login.h"

Login::Login()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("localhost");
        db.setDatabaseName("mitsubishi");
        db.setUserName("root");
        db.setPassword("");
        bool ok = db.open();
        if (ok)
        {

            qDebug()<<"Connected to the database";

            if( db.open() )
            {

                qDebug()<<"opened database";

                QSqlTableModel model ;
                model.setTable("csv_db.tbl_name");
                model.select();

            }
            else
                qDebug()<<"couldn't open database";
}
}
