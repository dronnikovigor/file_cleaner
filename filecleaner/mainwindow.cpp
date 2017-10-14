#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cleaner = new Cleaner();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startBtn_clicked()
{
    if (cleaner->checkPath() && cleaner->checkExt()){
        if (cleaner->clear())
            QMessageBox::information(this, "Info",
                                           "Completed!",
                                           QMessageBox::Ok);
        else
            QMessageBox::warning(this, "Warning",
                                           "Something went wrong!",
                                           QMessageBox::Ok);
    }
    else
        QMessageBox::warning(this, "Warning",
                                       "Check paths and extensions!",
                                       QMessageBox::Ok);
}

void MainWindow::on_selectInput_clicked()
{
    ui->inputPath->setText(QFileDialog::getExistingDirectory(0, "Select first directory",
                                                             "",
                                                             QFileDialog::ShowDirsOnly
                                                             | QFileDialog::DontResolveSymlinks));
    cleaner->setInputPath(ui->inputPath->text());
}

void MainWindow::on_selectOutput_clicked()
{
    ui->outputPath->setText(QFileDialog::getExistingDirectory(0, "Select second directory",
                                                             "",
                                                             QFileDialog::ShowDirsOnly
                                                             | QFileDialog::DontResolveSymlinks));
    cleaner->setOutputPath(ui->outputPath->text());
}

void MainWindow::on_inputExt_editingFinished()
{
    cleaner->setInputExt(ui->inputExt->text());
}

void MainWindow::on_outputExt_editingFinished()
{
    cleaner->setOutputExt(ui->outputExt->text());
}
