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
    virtual void onFrame(const Controller&);
    virtual void onFocusGained(const Controller&);
    virtual void onFocusLost(const Controller&);

private:
    encargadoComunicacion* comunicador_;
    Finger listaDedos_[5];
    int identificarDedo(Finger& finger_p);
    void actualizarArregloDedos(FingerList fingers);
    bool necesitaActualizar;
    conversorLeapServo conversorEscala_;
    int framesPorSaltar;
    int framesSaltados;
};

#endif // CONTROL_LEAP_H
