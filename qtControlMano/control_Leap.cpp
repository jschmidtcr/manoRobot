/******************************************************************************\
* Basado en Sample.cpp, distribuido con el LeapDeveloperKit                    *
* Esta clase calcula la posicion de cada dedo y usa un encargadoComunicacion   *
* para enviar los datos obtenidos                                              *
*                                                                              *
********************************************************************************
*                                                                              *
* Copyright (c) 2014 David Díaz <dajose22>                                     *
*                                                                              *
* Permission is hereby granted, free of charge, to any person obtaining a copy *
* of this software and associated documentation files (the "Software"), to deal*
* in the Software without restriction, including without limitation the rights *
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell    *
* copies of the Software, and to permit persons to whom the Software is        *
* furnished to do so, subject to the following conditions:                     *
*                                                                              *
* The above copyright notice and this permission notice shall be included in   *
* all copies or substantial portions of the Software.                          *
*                                                                              *
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR   *
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,     *
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  *
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER       *
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,*
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN    *
* THE SOFTWARE.                                                                *
*                                                                              *
\******************************************************************************/

#include "control_Leap.h"
#include <QDebug>
control_leap::control_leap(encargadoComunicacion *emisor):
    necesitaActualizar(true),
    framesPorSaltar(10),
    framesSaltados(0)
{
    comunicador_ = emisor;
}

void control_leap::onInit(const Controller&) {
    std::cout << "Initialized" << std::endl;
}

void control_leap::onConnect(const Controller&) {
    std::cout << "Connected" << std::endl;
}

void control_leap::onDisconnect(const Controller&) {
    //Note: not dispatched when running in a debugger.
    std::cout << "Disconnected" << std::endl;
}

void control_leap::onExit(const Controller&) {
    std::cout << "Exited" << std::endl;
}

void control_leap::onFrame(const Controller& controller) {
    // Get the most recent frame and report some basic information
    const Frame frame = controller.frame();
    //no se procesan todos los frames
    if(framesSaltados >framesPorSaltar)
    {
        framesSaltados = 0;
        //hay una mano en escena
        if(!frame.hands().isEmpty() )
        {
            //se obtiene la primer mano en escena
            //deberia haber solo una
            Leap::Hand leapHand = frame.hands()[0];

            //no se ha mapeado la mano o bien se perdio el
            //seguimiento de un dedo
            if(necesitaActualizar)
            {
                if(leapHand.fingers().count() < 5)
                    qDebug() << "no mano completa" ;
                else{//se tienen los 5 dedos con lo que se puede actualizar los ID
                    actualizarArregloDedos(leapHand.fingers());
                }

            }
            //se obtiene una matriz para transformar la poscion de los dedos en un eje relativo a la mano
            Leap::Vector handXBasis =  leapHand.palmNormal().cross(leapHand.direction()).normalized();
            Leap::Vector handYBasis = -leapHand.palmNormal();
            Leap::Vector handZBasis = -leapHand.direction();
            Leap::Vector handOrigin =  leapHand.palmPosition();
            Leap::Matrix handTransform = Leap::Matrix(handXBasis, handYBasis, handZBasis, handOrigin);
            handTransform = handTransform.rigidInverse();

            //se procesa cada dedo de la mano
            for( int f = 0; f < 5; f++ )
            {
                //se obtiene el valor actualizado de un dedo con el id almacenado del frame anterior
                Leap::Finger leapFinger = leapHand.finger(listaDedos_[f].id());
                necesitaActualizar |= !leapFinger.isValid();
                //se transforma la posicion del dedo al eje de la mano
                Leap::Vector transformedPosition = handTransform.transformPoint(leapFinger.stabilizedTipPosition());

                qDebug() << f << "," << leapFinger.id() << "," << identificarDedo(leapFinger) << ": " << transformedPosition.x << "          ";
                int dedo = identificarDedo((leapFinger));
                //se envia la posicion en y de la punta del dedo luego de ser escalada
                comunicador_->enviarMovimiento(dedo, conversorEscala_.escalarDeLeapAServo(dedo,transformedPosition.y));
            }
        }
        else
        {
            framesSaltados++;
        }
    }
    framesSaltados++;
}


void control_leap::onFocusGained(const Controller& ) {
  std::cout << "Focus Gained" << std::endl;
}

void control_leap::onFocusLost(const Controller&) {
    std::cout << "Focus Lost" << std::endl;
}


int control_leap::identificarDedo(Finger &finger_p)
{
    for(int i = 0;i<5;i++)
    {
        if(finger_p.id() == listaDedos_[i].id())
            return i;
    }
    return -1;
}


void control_leap::actualizarArregloDedos(FingerList fingers)
{
    //copia el arreglo de dedos
    for(int i = 0; i<5;i++)
        listaDedos_[i] = fingers[i];
    //ordenar los dedos para que esten desde el pulgar en la posicion 0 hasta el menique en la posicion 4
    //metodo burbuja
    Finger temp;
    for(int j = 0; j<4;j++){
        for(int i =j+1; i<5;i++){
            if(listaDedos_[j].tipPosition().x > listaDedos_[i].tipPosition().x)
            {
                temp = listaDedos_[i];
                listaDedos_[i] = listaDedos_[j];
                listaDedos_[j] = temp;
            }
        }
    }
    necesitaActualizar = false;
}


