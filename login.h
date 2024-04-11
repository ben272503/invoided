#ifndef LOGIN_H
#define LOGIN_H
#include "page1.h"
#include <QDialog>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    void on_login_button_clicked();

private:
    Ui::login *ui;
    Page1 *page1;
};

#endif // LOGIN_H
