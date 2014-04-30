#include "conversorleapservo.h"

conversorLeapServo::conversorLeapServo()
{
    factorEscala_[0] = -9/4;
    factorEscala_[1] = -9/4;
    factorEscala_[2] = -9/4;
    factorEscala_[3] = -9/4;
    factorEscala_[4] = -9/4;
}

int conversorLeapServo::escalarDeLeapAServo(int dedo, float escalaLeap)
{
    return escalaLeap*factorEscala_[dedo];
}
