#ifndef EMISORDEDEDOS_H
#define EMISORDEDEDOS_H
#include <QString>

class encargadoComunicacion
{

public:
    enum dedos{
        PULGAR,
        INDICE,
        MEDIO,
        ANULAR,
        MENIQUE
    };

    //metodo abstracto que se debe implementar para enviar un movimiento
    //en la clase que herede de esta
    virtual void enviarMovimiento(int dedo_p,int posicion_p) = 0;

    //mueve todos los dedos listados en el enum dedos a una misma posicion
    void enviarMovimientoATodos(int posicion_p);

    //obtiene el estado de la conexion
    bool getEstado();
    //define el puerto al que se debe realizar la conexion
    virtual void setPuerto(QString puerto) = 0;
protected:
    bool estado_;



    
};

#endif // EMISORDEDEDOS_H
