#ifndef CONNECT_H
#define CONNECT_H

#include<QtSql>
class Connect
{
public:
    QSqlDatabase db ;

    bool Open()
    {
         db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("localhost");
            db.setDatabaseName("mitsubishi");
            db.setUserName("root");
            db.setPassword("");
            bool ok = db.open();
            if (ok)
            {

                qDebug()<<"Connected to the database";




                }
                else
                    qDebug()<<"couldn't open database";
    }

    void close()
    {
        db.close();
        qDebug()<<" database closed";
    }
    Connect();
};

#endif // CONNECT_H
