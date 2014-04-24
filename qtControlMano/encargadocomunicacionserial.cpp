#include "encargadocomunicacionserial.h"
#include "qextserialport.h"
#include <QDebug>
encargadoComunicacionSerial::encargadoComunicacionSerial()
{
    PortSettings settings = {BAUD9600, DATA_8, PAR_NONE, STOP_1, FLOW_OFF, 10};


    port = new QextSerialPort("ttyACM0",settings);
    port->open(QIODevice::ReadWrite);
}

encargadoComunicacionSerial::~encargadoComunicacionSerial()
{
    port->close();
}

void encargadoComunicacionSerial::enviarMovimiento(int dedo_p, int posicion_p)
{
    port->write((QString::number(dedo_p) + "\n").toStdString().c_str());
    port->write((QString::number(posicion_p) + "\n").toStdString().c_str());
qDebug() << dedo_p << "  " << posicion_p;

}
