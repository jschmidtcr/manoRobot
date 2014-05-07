#ifndef CONTROL_LEAP_H
#define CONTROL_LEAP_H


#include <iostream>
#include "Leap.h"
#include "encargadoComunicacion.h"
#include "conversorleapservo.h"
using namespace Leap;

class control_leap : public Listener {
  public:
    control_leap(encargadoComunicacion* emisor);
    virtual void onInit(const Controller&);
    virtual void onConnect(const Controller&);
    virtual void onDisconnect(const Controller&);
    virtual void onExit(const Controller&);

    //Metodo llamado con cada frame obtenido del Leap
    //dentro de él se hace seguimiento de cada dedo y se utiliza
    //un encargadoComunicacion para enviar los datos obtenidos
    virtual void onFrame(const Controller&);

    virtual void onFocusGained(const Controller&);
    virtual void onFocusLost(const Controller&);

private:
    encargadoComunicacion* comunicador_;
    Finger listaDedos_[5];

    //dado un Finger, se obtiene la posicion en el arreglo
    //listaDedos_ de este para identificar cual dedo de la mano es.
    int identificarDedo(Finger& finger_p);

    //ordena listaDedos_ de manera que el pulgar está en la posicion 0
    //y asi hasta el menique en la posicion 4
    void actualizarArregloDedos(FingerList fingers);

    //indica si algun dedo se perdio de la escena y es necesario volver
    //a identificarlo
    bool necesitaActualizar;

    conversorLeapServo conversorEscala_;

    //Es innecesario analizar cada frame, se define cada cuantos
    //frame hacer el procesamiento y se lleva una cuenta de cuantos
    //han sido saltados sin procesar
    int framesPorSaltar;
    int framesSaltados;
};

#endif // CONTROL_LEAP_H
