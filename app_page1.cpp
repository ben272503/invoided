#include "app_page1.h"
#include "ui_app_page1.h"

app_page1::app_page1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::app_page1)
{
    ui->setupUi(this);
}

app_page1::~app_page1()
{
    delete ui;
}
