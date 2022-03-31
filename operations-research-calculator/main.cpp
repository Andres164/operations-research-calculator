#include <iostream>
#include <stdio.h>
#include "SimplexTable.h"

using namespace std;

void solveSimplexTable(double simplexTable[], int nunumberOfDesicionVariables, int numberOfHolguras);

int main()
{
    SimplexTable mySimplexTable(2, 3);
    mySimplexTable.printTable();
    cout << "is table feasible: "<< mySimplexTable.isTableFeasible() << endl;
    cout << "is table optimum: "<< mySimplexTable.isTableOptimum() << endl;

    int numberOfDesicionVariables, numberOfHolguras;
    cout << "Number of desicion variables: ";
    cin >> numberOfDesicionVariables;
    cout << "Number of Holguras: ";
    cin >> numberOfHolguras;

    int numberOfColumns = numberOfDesicionVariables + numberOfHolguras +1;
    int numberOfRows = numberOfHolguras +1;
    double simplexTable[numberOfColumns * numberOfRows];


    cout << "Write the table values: " << endl;
    cout << "Z row: " << endl << endl;

    for(int rowIndex = 0; rowIndex < numberOfRows; rowIndex++)
    {
        for(int columnIndex = 0; columnIndex < numberOfColumns; columnIndex++)
        {
            if(columnIndex < numberOfDesicionVariables)
            {
                cout << "X" << columnIndex+1 << ": ";
                cin >> simplexTable[columnIndex + rowIndex * numberOfColumns];
            }
            else
            {
                columnIndex += numberOfHolguras;
                cout << "Solution: ";
                cin >> simplexTable[columnIndex + rowIndex * numberOfColumns];
            }
        }
        if(rowIndex < numberOfRows-1)
        {
            cout << endl << "_________________________________________________________________________________" << endl;
            cout << endl << "H" << rowIndex +1 << " row" << endl;
        }
    }

    for(int rowIndex = 0; rowIndex < numberOfRows; rowIndex++)
    {
        for(int holguraIndex = numberOfDesicionVariables; holguraIndex < numberOfHolguras + numberOfDesicionVariables; holguraIndex++)
        {
            if(rowIndex == holguraIndex +1 -numberOfDesicionVariables)
                simplexTable[holguraIndex + rowIndex * numberOfColumns] = 1;
            else
                simplexTable[holguraIndex + rowIndex * numberOfColumns] = 0;
        }
    }

    cout << endl << "_________________________________________________________________________________" << endl;
    cout << endl << "Initial simplex Table: " << endl;
    for(int i = 0; i < numberOfColumns * numberOfRows; i++)
    {
        cout << simplexTable[i] << " | ";
        if((i+1)%numberOfColumns == 0)
            cout << endl;
    }

    solveSimplexTable(&simplexTable[0], numberOfDesicionVariables, numberOfHolguras);

    cout << endl << "_________________________________________________________________________________" << endl;
    cout << endl << "Final simplex Table: " << endl;
    for(int i = 0; i < numberOfColumns * numberOfRows; i++)
    {
        printf("%f | ", simplexTable[i]);
        if((i+1)%numberOfColumns == 0)
            cout << endl;
    }

    return 0;
}

void solveSimplexTable(double simplexTable[], int numberOfDesicionVariables, int numberOfHolguras)
{
    int numberOfColumns = numberOfDesicionVariables + numberOfHolguras +1;
    int numberOfRows = numberOfHolguras +1;


    double* ptr_mostNegativeColumn = &simplexTable[0];
    for(int variableIndex = 1; variableIndex < numberOfDesicionVariables; variableIndex++)
    {
        if(simplexTable[variableIndex] < *ptr_mostNegativeColumn)
            ptr_mostNegativeColumn = &simplexTable[variableIndex];
    }

    double* ptr_pivotRow = &simplexTable[numberOfColumns*2 -1];
    double smallestSolutionRate = *ptr_pivotRow / *(ptr_mostNegativeColumn + numberOfColumns);
    double pivotValue = *(ptr_mostNegativeColumn + numberOfColumns);
    for(int currentRow = 3; currentRow <= numberOfRows; currentRow++)
    {
        double currentPivotColumnValue = *(ptr_mostNegativeColumn + numberOfColumns*(currentRow -1));
        int solutionIndex = numberOfColumns*currentRow -1;
        if(currentPivotColumnValue > 0 && simplexTable[solutionIndex] > 0)
        {
            double currentSolutionRate = simplexTable[solutionIndex] / currentPivotColumnValue;
            if(currentSolutionRate < smallestSolutionRate)
            {
                ptr_pivotRow = &simplexTable[solutionIndex];
                smallestSolutionRate = currentSolutionRate;
                pivotValue = currentPivotColumnValue;
            }
        }
    }
    ptr_pivotRow -= (numberOfColumns -1);
    cout << endl << "_________________________________________________________________________________" << endl;
    cout << "Most negative column value: " << *ptr_mostNegativeColumn << endl;
    cout << "pivot row first value: " << *ptr_pivotRow << endl;
    cout << "Pivot value: " << pivotValue << endl;

    for(int rowIndex = -1; rowIndex < numberOfRows; rowIndex++)
    {
        cout << "iterated trhough" << endl;
        if(rowIndex != -1 && &simplexTable[rowIndex * numberOfColumns] != ptr_pivotRow)
        {
            double pivotColumnValue = *(ptr_mostNegativeColumn + rowIndex * numberOfColumns);
            for(int columnIndex = 0; columnIndex < numberOfColumns; columnIndex++)
            {
                if(pivotColumnValue < 0)
                    simplexTable[columnIndex + rowIndex * numberOfColumns] -= ( pivotColumnValue * (*(ptr_pivotRow + columnIndex)));
                else
                    simplexTable[columnIndex + rowIndex * numberOfColumns] -= ( pivotColumnValue * (*(ptr_pivotRow + columnIndex)));
            }
        }
        else if(rowIndex == -1)
        {
            cout << "ptr_PivotRow: " << ptr_pivotRow << endl;
            cout << "*ptr_PivotRow: " << *ptr_pivotRow << endl;
            for(int columnIndex = 0; columnIndex < numberOfColumns; columnIndex++)
            {
                *ptr_pivotRow = *ptr_pivotRow / pivotValue;
                ptr_pivotRow++;
            }
            ptr_pivotRow -= numberOfColumns;
            cout << "ptr_PivotRow: " << ptr_pivotRow << endl;
            int num;
            cin >> num;
        }
    }
    for(int i = 0; i < numberOfColumns; i++)
    {
        if(simplexTable[i] < 0)
        {
            solveSimplexTable(&simplexTable[0], numberOfDesicionVariables, numberOfHolguras);
            break;
        }
    }
    */
}



