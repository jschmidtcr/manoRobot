#ifndef EMISORDEDEDOS_H
#define EMISORDEDEDOS_H

#include <QObject>

class emisorDeDedos : public QObject
{
    Q_OBJECT
public:
    enum dedos{
        PULGAR,
        INDICE,
        MEDIO,
        ANULAR,
        MENIQUE
    };

    explicit emisorDeDedos(QObject *parent = 0);
    void emitirSenal(int dedo_p,float posicion_p);
    
signals:
    void senalDedo(int dedo_p, float posicion_p);

public slots:

    
};

#endif // EMISORDEDEDOS_H
