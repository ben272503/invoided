#ifndef APP_PAGE1_H
#define APP_PAGE1_H

#include <QMainWindow>

namespace Ui {
class app_page1;
}

class app_page1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit app_page1(QWidget *parent = 0);
    ~app_page1();

private:
    Ui::app_page1 *ui;
};

#endif // APP_PAGE1_H
