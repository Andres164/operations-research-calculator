#include <iostream>
#include <stdio.h>
#include "SimplexTable.h"
#include "operationsResearch.h"

using namespace std;

int main()
{
    SimplexTable mySimplexTable = getSimplexTableFromUser();
    /*/ Tabla 1
    // Z
    mySimplexTable.set_valueAt(0, 0, -10000);
    mySimplexTable.set_valueAt(0, 1, -8000);
    mySimplexTable.set_valueAt(0, 2, -15000);

    // H1
    mySimplexTable.set_valueAt(1, 0, 2);
    mySimplexTable.set_valueAt(1, 1, 1);
    mySimplexTable.set_valueAt(1, 2, 2);
    mySimplexTable.set_valueAt(1, 6, 12);

    // H2
    mySimplexTable.set_valueAt(2, 0, 3);
    mySimplexTable.set_valueAt(2, 1, 3);
    mySimplexTable.set_valueAt(2, 2, 4);
    mySimplexTable.set_valueAt(2, 6, 16);

    // H3
    mySimplexTable.set_valueAt(3, 0, 1);
    mySimplexTable.set_valueAt(3, 1, 2);
    mySimplexTable.set_valueAt(3, 2, 3);
    mySimplexTable.set_valueAt(3, 6, 18);
/*/

    /*/
    // Tabla 2
    // Z
    mySimplexTable.set_valueAt(0, 0, -6);
    mySimplexTable.set_valueAt(0, 1, -12);
    mySimplexTable.set_valueAt(0, 2, -10);

    // H1
    mySimplexTable.set_valueAt(1, 0, 5);
    mySimplexTable.set_valueAt(1, 1, 8);
    mySimplexTable.set_valueAt(1, 2, 13);
    mySimplexTable.set_valueAt(1, 7, 4000);

    // H2
    mySimplexTable.set_valueAt(2, 0, 12);
    mySimplexTable.set_valueAt(2, 1, 18);
    mySimplexTable.set_valueAt(2, 2, 14);
    mySimplexTable.set_valueAt(2, 7, 6000);

    // H3
    mySimplexTable.set_valueAt(3, 0, 1);
    mySimplexTable.set_valueAt(3, 1, 1);
    mySimplexTable.set_valueAt(3, 2, 1);
    mySimplexTable.set_valueAt(3, 7, 600);

    // H4
    mySimplexTable.set_valueAt(4, 0, -1);
    mySimplexTable.set_valueAt(4, 1, 0);
    mySimplexTable.set_valueAt(4, 2, 0);
    mySimplexTable.set_valueAt(4, 7, -200);
/*/
/*/ Tabla 4
    // Z
    mySimplexTable.set_valueAt(0, 0, -10000);
    mySimplexTable.set_valueAt(0, 1, -11000);
    mySimplexTable.set_valueAt(0, 2, -9500);

    // H1
    mySimplexTable.set_valueAt(1, 0, -200);
    mySimplexTable.set_valueAt(1, 1, -300);
    mySimplexTable.set_valueAt(1, 2, -50);
    mySimplexTable.set_valueAt(1, 6, -100);

    // H2
    mySimplexTable.set_valueAt(2, 0, -600);
    mySimplexTable.set_valueAt(2, 1, -500);
    mySimplexTable.set_valueAt(2, 2, -380);
    mySimplexTable.set_valueAt(2, 6, -300);

    // H3
    mySimplexTable.set_valueAt(3, 0, -90);
    mySimplexTable.set_valueAt(3, 1, -80);
    mySimplexTable.set_valueAt(3, 2, -80);
    mySimplexTable.set_valueAt(3, 6, -70);
/*/
    mySimplexTable.printTable();
    string input;
    cout << "Quieres Maximizar o minimizar ( MAX / MIN ) : ";
    cin >> input;
    mySimplexTable.solveTable(input);
}



