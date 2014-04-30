#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    comunicador_ = new encargadoComunicacionSerial();


    if(!comunicador_->getEstado())
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Revise la conexion con la mano");
        exit(1);
    }
    comunicador_->enviarMovimiento(encargadoComunicacion::INDICE,1);
    comunicador_->enviarMovimiento(encargadoComunicacion::PULGAR,1);
    comunicador_->enviarMovimiento(encargadoComunicacion::MEDIO,1);
    comunicador_->enviarMovimiento(encargadoComunicacion::MENIQUE,1);
    comunicador_->enviarMovimiento(encargadoComunicacion::ANULAR,1);

    controlLeap_ = new control_leap(comunicador_);
    ui->controlManual_->setEmisor(comunicador_);



}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_rb_leap_clicked(bool checked)
{
    ui->controlManual_->setEnabled(!checked);
    controller_.addListener(*controlLeap_);

}

void MainWindow::on_rb_manual_clicked(bool checked)
{
    ui->controlManual_->setEnabled(checked);
    controller_.removeListener(*controlLeap_);

}
