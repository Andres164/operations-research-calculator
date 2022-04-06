#include <iostream>
#include <cstring>
#include <math.h>
#include "operationsResearch.h"

SimplexTable getSimplexTableFromUser()
{

}

long long int greatestCommonDenominatorOf(long long int numerator, long long int denominator)
{
    while (numerator != denominator)
    {
        if (numerator > denominator)
            numerator -= denominator;
        else
            denominator -= numerator;
    }
    return numerator;
}
void simplifyFraction(long long int& numerator, long long int& denominator)
{
    long long int common_factor = greatestCommonDenominatorOf(numerator, denominator);
    numerator /= common_factor;
    denominator /= common_factor;
}
std::string decimalToFraction(double decimal, char sign)
{
    if(sign == '-')
        decimal *= -1;
    long long int numerator = decimal * 1000000;
    long long int denominator = 1000000;
    simplifyFraction(numerator, denominator);
    std::string fraction = sign + std::to_string(numerator) + '/' + std::to_string(denominator);
    return fraction;
}


