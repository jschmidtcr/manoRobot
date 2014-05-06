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

    virtual void enviarMovimiento(int dedo_p,int posicion_p) = 0;
    bool getEstado();
    virtual void setPuerto(QString puerto) = 0;
protected:
    bool estado_;
    QString puerto_;



    
};

#endif // EMISORDEDEDOS_H
