#ifndef ENCARGADOCOMUNICACIONSERIAL_H
#define ENCARGADOCOMUNICACIONSERIAL_H

#include "encargadoComunicacion.h"
class QextSerialPort;

class encargadoComunicacionSerial : public encargadoComunicacion
{
public:
    encargadoComunicacionSerial();
    ~encargadoComunicacionSerial();
    void enviarMovimiento(int dedo_p, int posicion_p);
    void setPuerto(QString puerto);
private:
    QextSerialPort *port;

};

#endif // ENCARGADOCOMUNICACIONSERIAL_H
