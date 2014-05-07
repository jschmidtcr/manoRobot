/******************************************************************************\
* Implementacion de la clase encargadoComunicacion.cpp para una conexion serial*
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


#include "encargadocomunicacionserial.h"
#include "qextserialport.h"
#include <QDebug>
encargadoComunicacionSerial::encargadoComunicacionSerial()
{
    port = 0;
}

encargadoComunicacionSerial::~encargadoComunicacionSerial()
{
    port->close();
}

void encargadoComunicacionSerial::enviarMovimiento(int dedo_p, int posicion_p)
{
    //es necesario enviar un cambio de linea para que el arduino lea el valor
    port->write((QString::number(dedo_p) + "\n").toStdString().c_str());
    port->write((QString::number(posicion_p) + "\n").toStdString().c_str());
    qDebug() << dedo_p << "  " << posicion_p;

}
void encargadoComunicacionSerial::setPuerto(QString puerto)
{
    if(port != 0 && port->isOpen())
        port->close();


    PortSettings settings = {BAUD9600, DATA_8, PAR_NONE, STOP_1, FLOW_OFF, 10};
    port = new QextSerialPort(puerto,settings);

    if(!(estado_ = port->open(QIODevice::ReadWrite)))
        qDebug()<< "NO SE CONECTO" ;

}
