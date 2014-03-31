#include "conversorleapservo.h"

conversorLeapServo::conversorLeapServo()
{
    factorEscala_[0] = -9/2;
    factorEscala_[1] = -9/2;
    factorEscala_[2] = -9/2;
    factorEscala_[3] = -9/2;
    factorEscala_[4] = -9/2;
}

int conversorLeapServo::escalarDeLeapAServo(int dedo, float escalaLeap)
{
    return escalaLeap*factorEscala_[dedo];
}
