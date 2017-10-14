#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cleaner.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_startBtn_clicked();

    void on_selectInput_clicked();

    void on_selectOutput_clicked();

    void on_inputExt_editingFinished();

    void on_outputExt_editingFinished();

private:
    Ui::MainWindow *ui;

    Cleaner *cleaner;
};

#endif // MAINWINDOW_H
