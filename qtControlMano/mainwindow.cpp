/******************************************************************************\
* Encargada de conectar señales e inicializar el leap y la interfaz de         *
* comunicacion.                                                                *
*                                                                              *
********************************************************************************
*                                                                              *
* Copyright (c) 2014 David Díaz <dajose22>                                     *
*                                                                              *
* Permission is hereby granted, free of charge, to any person obtaining a copy *
* of this software and associated documentation files (the "Software"), to deal*
* in the Software without restriction, including without limitation the rights *
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell    *
* copies of the Software, and to permit persons to whom the Software is        *
* furnished to do so, subject to the following conditions:                     *
*                                                                              *
* The above copyright notice and this permission notice shall be included in   *
* all copies or substantial portions of the Software.                          *
*                                                                              *
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR   *
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,     *
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  *
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER       *
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,*
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN    *
* THE SOFTWARE.                                                                *
*                                                                              *
\******************************************************************************/

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
