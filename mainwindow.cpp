#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include "cipher.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbRun_clicked()
{
    QMessageBox msb;
    QString textInput = ui->leMessageInput->text();
    QString decryptionKey = ui->leDecryptKey->text();

    if(!textInput.isEmpty() && !decryptionKey.isEmpty()){
        if (ui->rbEncrypt->isChecked() && !ui->rbDecrypt->isChecked())
        {
            cipher cip;
            string encryptedMessage = cip.EncryptMessage(decryptionKey, textInput);

            ui->leMessageOutput->setText(QString::fromStdString(encryptedMessage));
        }
        else if(!ui->rbEncrypt->isChecked() && ui->rbDecrypt->isChecked())
        {
            cipher cip;
            string decryptedMessage = cip.DecryptMessage(decryptionKey, textInput);

            ui->leMessageOutput->setText(QString::fromStdString(decryptedMessage));
        }
        else
        {
            ui->leMessageOutput->setText("error");
        }
    } else {
        ui->leMessageOutput->setText("One or more inputs are empty.");
    }
}
