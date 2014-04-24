/******************************************************************************\
* Copyright (C) 2012-2013 Leap Motion, Inc. All rights reserved.               *
* Leap Motion proprietary and confidential. Not for distribution.              *
* Use subject to the terms of the Leap Motion SDK Agreement available at       *
* https://developer.leapmotion.com/sdk_agreement, or another agreement         *
* between Leap Motion and you, your company or other organization.             *
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
    //  controller.enableGesture(Gesture::TYPE_CIRCLE);
    //  controller.enableGesture(Gesture::TYPE_KEY_TAP);
    //  controller.enableGesture(Gesture::TYPE_SCREEN_TAP);
    //  controller.enableGesture(Gesture::TYPE_SWIPE);

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
    if(framesSaltados >framesPorSaltar)
    {        framesSaltados = 0;

        if(!frame.hands().isEmpty() )
        {
            Leap::Hand leapHand = frame.hands()[0];

            if(necesitaActualizar)
            {
                if(leapHand.fingers().count() < 5)
                    std::cout << "no mano completa" << std::endl;
                else{
                    actualizarArregloDedos(leapHand.fingers());
                }

            }
            Leap::Vector handXBasis =  leapHand.palmNormal().cross(leapHand.direction()).normalized();
            Leap::Vector handYBasis = -leapHand.palmNormal();
            Leap::Vector handZBasis = -leapHand.direction();
            Leap::Vector handOrigin =  leapHand.palmPosition();
            Leap::Matrix handTransform = Leap::Matrix(handXBasis, handYBasis, handZBasis, handOrigin);
            handTransform = handTransform.rigidInverse();

            for( int f = 0; f < 5; f++ )
            {
                Leap::Finger leapFinger = leapHand.finger(listaDedos_[f].id()); //fingers()[f];
                necesitaActualizar |= !leapFinger.isValid();
                Leap::Vector transformedPosition = handTransform.transformPoint(leapFinger.stabilizedTipPosition());
                //            Leap::Vector transformedDirection = handTransform.transformDirection(leapFinger.direction());
                // Do something with the transformed fingers


                Leap::Vector basePosition = -leapFinger.direction() * leapFinger.length();
                basePosition += leapFinger.tipPosition();

                std::cout << f << "," << leapFinger.id() << "," << identificarDedo(leapFinger) << ": " << transformedPosition.x << "          ";
                //std::cout << leapFinger.direction().y << std::endl;
                //            std::cout << leapFinger.id() << ": " << leapFinger.length() << std::endl;
                int dedo = identificarDedo((leapFinger));
                comunicador_->enviarMovimiento(dedo, conversorEscala_.escalarDeLeapAServo(dedo,transformedPosition.y));

            }


            std::cout  << std::endl;

        }
        else
        {
            //        std::cout << "NO HAND" << std::endl;
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
    std::cout << "............................................" << std::endl;
    for(int i = 0; i<5;i++)
        listaDedos_[i] = fingers[i];

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


