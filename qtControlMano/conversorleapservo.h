#ifndef CONVERSORLEAPSERVO_H
#define CONVERSORLEAPSERVO_H

class conversorLeapServo
{
public:
    conversorLeapServo();
    int escalarDeLeapAServo(int dedo,float escalaLeap);
private:
    float factorEscala_[5];
};

#endif // CONVERSORLEAPSERVO_H
