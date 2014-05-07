/******************************************************************************\
* Define sliders para controlar la mano desde una ventana definida en          *
* controlmanual.ui                                                             *
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
#include "controlmanual.h"
#include "ui_controlmanual.h"

controlManual::controlManual(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::controlManual)
{
    ui->setupUi(this);
}

void controlManual::setEmisor(encargadoComunicacion *emisor)
{
    comunicador_ = emisor;
}

controlManual::~controlManual()
{
    delete ui;
}

void controlManual::on_vs_pulgar_valueChanged(int value)
{
    ui->le_pulgar->setText(QString::number(value));
    comunicador_->enviarMovimiento(encargadoComunicacion::PULGAR,value);

}

void controlManual::on_vs_indice_valueChanged(int value)
{
    ui->le_indice->setText(QString::number(value));
    comunicador_->enviarMovimiento(encargadoComunicacion::INDICE,value);

}

void controlManual::on_vs_medio_valueChanged(int value)
{
    ui->le_medio->setText(QString::number(value));
    comunicador_->enviarMovimiento(encargadoComunicacion::MEDIO,value);

}

void controlManual::on_vs_anular_valueChanged(int value)
{
    ui->le_anular->setText(QString::number(value));
    comunicador_->enviarMovimiento(encargadoComunicacion::ANULAR,value);

}

void controlManual::on_vs_menique_valueChanged(int value)
{
    ui->le_menique->setText(QString::number(value));
    comunicador_->enviarMovimiento(encargadoComunicacion::MENIQUE,value);

}
