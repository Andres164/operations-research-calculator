#include <iostream>

using namespace std;

int main()
{
    int numberOfDesicionVariables, numberOfHolguras;
    cout << "Number of desicion variables: ";
    cin >> numberOfDesicionVariables;
    cout << "Number of Holguras: ";
    cin >> numberOfHolguras;

    int numberOfColumns = numberOfDesicionVariables + numberOfHolguras +1;
    int numberOfRows = numberOfHolguras +1;
    int simplexTable[numberOfColumns * numberOfRows];


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

    return 0;
}
