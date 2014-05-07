#ifndef ENCARGADOCOMUNICACIONSERIAL_H
#define ENCARGADOCOMUNICACIONSERIAL_H

#include "encargadoComunicacion.h"
class QextSerialPort;

class encargadoComunicacionSerial : public encargadoComunicacion
{
public:

    encargadoComunicacionSerial();
    ~encargadoComunicacionSerial();

    //envia una señal para mover dedo_p a la posicion posicion_p
    //por medio de la conexion serie
    void enviarMovimiento(int dedo_p, int posicion_p);

    //establece el puerto al que se debe hacer la conexion y
    //abre el canal de comunicacion serial
    void setPuerto(QString puerto);
private:
    //puerto donde se realiza la conexion
    QextSerialPort *port;

};

#endif // ENCARGADOCOMUNICACIONSERIAL_H
