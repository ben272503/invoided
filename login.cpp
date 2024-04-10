#include "login.h"
#include "ui_login.h"
#include "app_page1.h"
#include <QMessageBox>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_login_button_clicked()
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    if(username == "test" && password == "test") {
        QMessageBox::information(this, "login", "login succeed");
        close();
        app_page1->show();
    }
    else{
        QMessageBox::warning(this, "login", "username or password is wrong");
    }
}
