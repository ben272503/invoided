#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "global_login.h"
#include <QMessageBox>
#include <QPixmap>
#include <QDir>

int globl = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("images/background.jpeg");
    ui->label_pic->setPixmap(pix);
//    ui->statusBar->showMessage(QDir::currentPath());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    login Loginpage;
    Loginpage.setModal(true);
    Loginpage.exec();
    if ((globl = 1)) {
        close();
    }
}
