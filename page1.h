#ifndef PAGE1_H
#define PAGE1_H
#include "mainwindow.h"
#include "history.h"
#include <QMainWindow>

#include <QtNetwork/QNetworkAccessManager>//to make request
#include <QtNetwork/QNetworkReply>//to handle replies
//#include <QtNetwork/QNetworkRequest>


namespace Ui {
class Page1;
}

class Page1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Page1(QWidget *parent = 0);
    ~Page1();

private slots:
    void on_pushButtonUpdateDB_clicked();

    void on_pushButton_folder_clicked();

    void on_pushButton_settings_clicked();

    void on_pushButton_mailbox_clicked();

    void on_actionD_connexion_triggered();

    void on_pushButton_history_clicked();

private:
    Ui::Page1 *ui;
    MainWindow *mainWindow;
    History *history;

    QString myUrl = "https://api.mimil-grp.eu/foodinni/public/getAllItems.php";
private slots:
    void downloadFinished(QNetworkReply*);
};

#endif // PAGE1_H
