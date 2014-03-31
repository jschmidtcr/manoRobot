#ifndef EMISORDEDEDOS_H
#define EMISORDEDEDOS_H


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
    



    
};

#endif // EMISORDEDEDOS_H
