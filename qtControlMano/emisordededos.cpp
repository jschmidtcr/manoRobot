#include "emisordededos.h"

emisorDeDedos::emisorDeDedos(QObject *parent) :
    QObject(parent)
{
}

void emisorDeDedos::emitirSenal(int dedo_p, float posicion_p)
{
    senalDedo(dedo_p,posicion_p);
}
