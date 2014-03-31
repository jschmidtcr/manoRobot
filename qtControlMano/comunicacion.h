#ifndef COMUNICACION_H
#define COMUNICACION_H

class QextSerialPort;
class QextSerialEnumerator;
class comunicacion
{

public:
    enum dedos{
        PULGAR,
        INDICE,
        MEDIO,
        ANULAR,
        MENIQUE
    };
    comunicacion();
    void moverDedo(int dedo, int posicion);
private:
    QextSerialPort *port;

};

#endif // COMUNICACION_H
