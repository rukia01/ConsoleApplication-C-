#include"GetBmi.h"

double GetBmi(double height, double weight)
{
    double bmi;
    bmi = weight / (height * height);
    return bmi;
}