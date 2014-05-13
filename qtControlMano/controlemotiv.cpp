/******************************************************************************\
* Mueve los dedos a partir de señales de teclas presionadas que se espera      *
* hayan sido configuradas en el control panel del emotiv,                      *
*                   solo sirve en Windows                                      *
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

#include "controlemotiv.h"
#include "ui_controlemotiv.h"
#include <QKeyEvent>

controlEmotiv::controlEmotiv(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::controlEmotiv)
{
    ui->setupUi(this);
    setFocusPolicy(Qt::StrongFocus);
}

void controlEmotiv::setEmisor(encargadoComunicacion *emisor)
{
    comunicador_ = emisor;
}

controlEmotiv::~controlEmotiv()
{
    delete ui;
}

void controlEmotiv::keyPressEvent(QKeyEvent* keyevent)
{
    if (keyevent->key()==Qt::Key_A)
    {
        ui->l_accion->setText("abrir");
        comunicador_->enviarMovimientoATodos(0);
    }
    if (keyevent->key()==Qt::Key_C)
    {
        ui->l_accion->setText("cerrar");
        comunicador_->enviarMovimientoATodos(90);
    }
}
