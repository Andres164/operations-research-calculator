#include <iostream>
#include <string>
#include "SimplexTable.h"

SimplexTable getSimplexTableFromUser()
{

}

long int greatestCommonDenominatorOf(long int numerator, long int denominator)
{
    if (numerator == 0)
        return denominator;
    return greatestCommonDenominatorOf(denominator % numerator, numerator);
}
void simplifyFraction(long int& numerator, long int& denominator)
{
    long int common_factor = greatestCommonDenominatorOf(numerator, denominator);
    numerator /= common_factor;
    denominator /= common_factor;
}
std::string decimalToFraction(double decimal)
{
    int dec_places = getNumDecPlaces(decimal)- in this case it should return 3;

    int numerator = decimal * 10 ^ dec_places - this will be 125;
    int denominator = 10 ^ dec_places;
}


