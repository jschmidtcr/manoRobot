#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "encargadocomunicacionserial.h"
#include "control_Leap.h"
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
    void on_rb_leap_clicked(bool checked);

    void on_rb_manual_clicked(bool checked);

private:
    control_leap* controlLeap_;
    Controller controller_;
    encargadoComunicacionSerial* comunicador_;


    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
