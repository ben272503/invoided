#include "page1.h"
#include "ui_page1.h"
#include "settings.h"
#include <QDesktopWidget>
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>
#include <QProcess>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

//define what to do when request is over
void Page1::downloadFinished(QNetworkReply *reply) {
    QJsonDocument json = QJsonDocument::fromJson(reply->readAll());
    QJsonArray jsonArray = json.array();
    if (!jsonArray.isEmpty()) {
        QJsonObject jsonObject = jsonArray[0].toObject();
        QString ean13 = jsonObject["ean13"].toString();
        ui->label_Get->setText(ean13);
     }else{
        qDebug() << "JSON array is empty";
        qDebug() << "JSON data:" << json.toJson(QJsonDocument::Indented);
    }
}


Page1::Page1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Page1)
{
    ui->setupUi(this);
    resize(QDesktopWidget().availableGeometry(this).size() * 0.7);
    QNetworkAccessManager *man = new QNetworkAccessManager(this);
     connect(man, &QNetworkAccessManager::finished, this, &Page1::downloadFinished);
}

Page1::~Page1()
{
    delete ui;
}

// Start of functions that are called by widgets__****

void openOutlook(QWidget* parent) { //open outlook or redirect if it does not exist
    QProcess process;
    process.start("Outlook.exe");
    if (!process.waitForStarted()) {
        QMessageBox::warning(parent, "Warning", "Outlook not found\nPlease link your mail application in the settings.");
        return;
    }
    process.waitForFinished();
}

// End of functions that are called by widgets__****

void Page1::on_pushButtonUpdateDB_clicked()
{
//    QMessageBox::warning(this, "Update", "are you sure you want to update Database?");

    QNetworkAccessManager *man = new QNetworkAccessManager(this);
    connect(man, &QNetworkAccessManager::finished, this, &Page1::downloadFinished);
    const QUrl url = QUrl(myUrl);
    QNetworkRequest request(url);
    man->get(request);
}

void Page1::on_pushButton_folder_clicked()
{
    QDesktopServices::openUrl(QUrl("file:///" + QApplication::applicationDirPath() + "/Resources"));
}

void Page1::on_pushButton_mailbox_clicked()
{
    openOutlook(this);
}

void Page1::on_pushButton_settings_clicked()
{
    Settings Settingpage;
    Settingpage.setModal(true);
    Settingpage.exec();
}

void Page1::on_actionD_connexion_triggered()
{
    mainWindow = new MainWindow();
    mainWindow->show();
    close();
}

void Page1::on_pushButton_history_clicked()
{
        history = new History(this);
        history->show();
}
