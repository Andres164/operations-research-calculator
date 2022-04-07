#include <iostream>
#include <cstring>
#include <math.h>
#include <fstream>
#include "operationsResearch.h"
/*
double getNumberFromString(std::string& stringGiven)
{
    for(auto& element : stringGiven)
    {
        if(element )
    }
}
*/

SimplexTable getSimplexTableFromUser()
{
    int decisionVariables, holguras;
    std::cout << "Escribe el numero de variables X: ";
    std::cin >> decisionVariables;
    std::cout << "Escribe el numero de Holguras H: ";
    std::cin >> holguras;

    SimplexTable newSimplexTable(decisionVariables, holguras);
    int numberOfColumns = decisionVariables + holguras +1;
    int numberOfRows = holguras +1;

    std::cout << "Write the table values: " << std::endl;
    std::cout << "Z row: " << std::endl << std::endl;

    for(int rowIndex = 0; rowIndex < numberOfRows; rowIndex++)
    {
        for(int columnIndex = 0; columnIndex < numberOfColumns; columnIndex++)
        {
            int value;
            if(columnIndex < decisionVariables)
                std::cout << "X" << columnIndex+1 << ": ";
            else
            {
                columnIndex += holguras;
                std::cout << "Solution(si es renglon Z pon 0): ";
            }
            std::cin >> value;
            newSimplexTable.set_valueAt(rowIndex, columnIndex, value);
        }
        if(rowIndex < numberOfRows-1)
        {
            std::cout << std::endl << "_________________________________________________________________________________" << std::endl;
            std::cout << std::endl << "H" << rowIndex +1 << " row" << std::endl;
        }
    }
    return newSimplexTable;
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


