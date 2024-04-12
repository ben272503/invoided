#include "page1.h"
#include "ui_page1.h"
#include <QDesktopWidget>
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>

Page1::Page1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Page1)
{
    ui->setupUi(this);
    resize(QDesktopWidget().availableGeometry(this).size() * 0.7);
}

Page1::~Page1()
{
    delete ui;
}

void Page1::on_pushButtonUpdateDB_clicked()
{
    QMessageBox::warning(this, "Update", "are you sure you want to update Database?");
}

void Page1::on_pushButton_folder_clicked()
{
    QDesktopServices::openUrl(QUrl("file:///" + QApplication::applicationDirPath() + "/Files"));
}
