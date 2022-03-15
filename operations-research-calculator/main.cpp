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
    cout << "| Z";

    for(int rowIndex = 0; rowIndex < numberOfRows; rowIndex++)
    {
        for(int columnIndex = 0; columnIndex < numberOfColumns; columnIndex++)
        {
            if(columnIndex < numberOfDesicionVariables)
            {
                cout << " | X" << columnIndex+1 << ": ";
                cin >> simplexTable[columnIndex + rowIndex * numberOfColumns];
            }
            else
            {
                columnIndex += numberOfHolguras;
                cout << " | Solution: ";
                cin >> simplexTable[columnIndex + rowIndex * numberOfColumns];
            }
        }
        cout << endl << "H" << rowIndex +1;
    }

    return 0;
}
