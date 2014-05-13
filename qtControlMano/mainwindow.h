#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "encargadocomunicacionserial.h"
#include "control_Leap.h"
#include "controlemotiv.h"
#include "qextserialenumerator.h"

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

    void on_cb_puerto_currentIndexChanged(const QString &arg1);


    void on_tb_opciones_currentChanged(int index);

private:
    control_leap* controlLeap_;
    Controller controller_;
    encargadoComunicacionSerial* comunicador_;


    Ui::MainWindow *ui;

    void configurarLeap();

    void configurarManual();

    void configurarEmotiv();

};

#endif // MAINWINDOW_H
