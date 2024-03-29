#pragma once
#include <string>
#include "SimplexTable.h"

double getNumberFromString(std::string stringGiven);
void readInitialTable();
SimplexTable getSimplexTableFromUser();

long long int greatestCommonDenominatorOf(long long int numerator, long long int denominator);
void simplifyFraction(long long int& numerator, long long int& denominator);
std::string decimalToFraction(double decimal, char sign = ' ');
