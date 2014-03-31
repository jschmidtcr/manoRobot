#include "comunicacion.h"

#include "qextserialport.h"
#include "qextserialenumerator.h"

comunicacion::comunicacion()
{
    PortSettings settings = {BAUD9600, DATA_8, PAR_NONE, STOP_1, FLOW_OFF, 10};


    port = new QextSerialPort("ttyACM0",settings);
    port->open(QIODevice::ReadWrite);
    port->write("111");
}
