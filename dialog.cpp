#include "dialog.h"
#include "ui_dialog.h"
#include "app_page1.h"
#include <QMessageBox>

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

void Dialog::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_2_password->text();

    if(username == "test" && password == "test") {
        QMessageBox::information(this, "login", "login succeed");
        hide();
    }
    else{
        QMessageBox::warning(this, "login", "username or password is wrong");
    }
}
