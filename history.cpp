#include "history.h"
#include "ui_history.h"

History::History(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::History)
{
    ui->setupUi(this);
    this->setFixedSize(450,400);
}

History::~History()
{
    delete ui;
}

void History::on_pushButton_clicked()
{
    close();
}
