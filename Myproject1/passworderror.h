#ifndef PASSWORDERROR_H
#define PASSWORDERROR_H

#include <QDialog>

namespace Ui {
class passworderror;
}

class passworderror : public QDialog
{
    Q_OBJECT

public:
    explicit passworderror(QWidget *parent = 0);
    ~passworderror();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_2_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_clicked();

private:
    Ui::passworderror *ui;
};

#endif // PASSWORDERROR_H
