#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    comunicador_ = new encargadoComunicacionSerial();

    ui->cb_puerto->blockSignals(true);
    foreach (QextPortInfo info, QextSerialEnumerator::getPorts())
        ui->cb_puerto->addItem(info.portName);
    ui->cb_puerto->blockSignals(false);
    ui->cb_puerto->setCurrentIndex(QextSerialEnumerator::getPorts().count() -1 );


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

void MainWindow::on_cb_puerto_currentIndexChanged(const QString &arg1)
{
    qDebug() << "puerto cambiado " << arg1;
    if(comunicador_ != 0)
        comunicador_->setPuerto(ui->cb_puerto->currentText());
}
