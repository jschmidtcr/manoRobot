#include "encargadoComunicacion.h"


//encargadoComunicacion::encargadoComunicacion()
//{
//    PortSettings settings = {BAUD9600, DATA_8, PAR_NONE, STOP_1, FLOW_OFF, 10};


//    port = new QextSerialPort("ttyACM0",settings);
//    port->open(QIODevice::ReadWrite);
//    port->write("111");
//}

bool encargadoComunicacion::getEstado()
{
    return estado_;
}
