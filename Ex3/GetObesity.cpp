#include"GetObesity.h"

int GetObesity(double bmi)
{
    int degreeOfObesity;
    if (bmi >= 40)
    {
        degreeOfObesity = 4;
    }
    else if (bmi >= 35)
    {
        degreeOfObesity = 3;
    }
    else if (bmi >= 30)
    {
        degreeOfObesity = 2;
    }
    else if (bmi >= 25)
    {
        degreeOfObesity = 1;
    }
    else if (bmi >= 18.5)
    {
        degreeOfObesity = 0;
    }
    else
    {
        degreeOfObesity = -1;
    }
    return degreeOfObesity;
}