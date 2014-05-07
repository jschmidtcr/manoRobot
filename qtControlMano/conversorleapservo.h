#ifndef CONVERSORLEAPSERVO_H
#define CONVERSORLEAPSERVO_H

class conversorLeapServo
{
public:
    conversorLeapServo();

    //escala un valor float a un int de acuerdo a la escala
    //definida para dedo
    int escalarDeLeapAServo(int dedo,float escalaLeap);
private:
    //factor en el que se escala un valor RAW del LeapMotion
    //para estar en el rango de valores necesarios para el servo
    float factorEscala_[5];
};

#endif // CONVERSORLEAPSERVO_H
