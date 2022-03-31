#include <iostream>
#include <vector>
#include "SimplexTable.h"

// Protected Methods
void SimplexTable::set_valueAt(int row, int column, double value) { this->table[column + row * this->numberOfColumns] = value; }
double SimplexTable::get_valueAt(int row, int column) { return this->table[column + row * this->numberOfColumns]; }

bool SimplexTable::isTableFeasible()
{
    for(int solutionRow = 0; solutionRow < this->numberOfRows; solutionRow++)
    {
        double solutionValue = this->get_valueAt(solutionRow, this->numberOfColumns -1);
        if(solutionValue < 0)
            return false;
    }
    return true;
}
bool SimplexTable::isTableOptimum()
{
    for(int i = 0; i < this->numberOfColumns; i++)
        if(this->get_valueAt(0, i) < 0)
            return false;
    return true;
}
double* SimplexTable::getPtr_pivotRow()
{
    return 0;
}
double* SimplexTable::getPtr_pivotColumn()
{
    return 0;
}
void SimplexTable::initializeHolguras()
{
    for(int holguraRow = 0; holguraRow < this->numberOfRows; holguraRow++)
    {
        for(int holguraColumn = this->numberOfDecisionVariables; holguraColumn < this->numberOfColumns -1; holguraColumn++)
        {
            if(holguraRow == holguraColumn+1 - this->numberOfDecisionVariables)
                this->set_valueAt(holguraRow, holguraColumn, 1);
        }
    }
}
void SimplexTable::simplexIteration()
{
}
void SimplexTable::dualSimplexIteration()
{

}

// Constructors
SimplexTable::SimplexTable(int vNumberOfDecisionVariables, int vNumberOfHolguras) :  numberOfDecisionVariables(vNumberOfDecisionVariables), numberOfHolguras(vNumberOfHolguras),
                                                                                     numberOfRows(vNumberOfHolguras +1), numberOfColumns(vNumberOfDecisionVariables + vNumberOfHolguras +1)
{
    this->table.resize(this->numberOfRows * this->numberOfColumns);
    this->initializeHolguras();
}

// Methods
void SimplexTable::printTable()
{
    for(int i = 0; i < numberOfColumns * numberOfRows; i++)
    {
        std::cout << " | " << this->table[i] << " | ";
        if((i+1)%numberOfColumns == 0)
            std::cout << std::endl;
    }
}
void SimplexTable::solveTable()
{

}
