#include <iostream>
#include <vector>
#include "SimplexTable.h"

// Protected Methods
void SimplexTable::set_valueAt(int row, int column, double value)
{
    if(row > this->numberOfRows || column > this->numberOfColumns)
        std::cout << "Out of range: Row" << row << " Column: " << column << std::endl;
    else
        this->table[column + row * this->numberOfColumns] = value;
}
double SimplexTable::get_valueAt(int row, int column)
{
    if(row > this->numberOfRows || column > this->numberOfColumns)
    {
        std::cout << "Out of range: Row: " << row << " Column: " << column << std::endl;
        return 0;
    }
    else
        return this->table[column + row * this->numberOfColumns];
}

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
int SimplexTable::get_pivotRowIndex(bool isTableFeasible)
{
    if(isTableFeasible)
    {
        const int solutionColumn = this->numberOfColumns-1;
        const int pivotColumn = this->get_pivotColumnIndex(isTableFeasible);
        int currentRow = 1;
        int pivotRow = 1;
        double smallestRatio = this->get_valueAt(currentRow, solutionColumn) / this->get_valueAt(currentRow, pivotColumn);
        //std::cout << std::endl << "samllestRatio 1st: " << smallestRatio << std::endl;
        for(currentRow++; currentRow < this->numberOfRows; currentRow++)
        {
            double currentSolutionValue = this->get_valueAt(currentRow, solutionColumn);
            if(this->get_valueAt(currentRow, pivotColumn) != 0)
            {
                double currentRatio = currentSolutionValue / this->get_valueAt(currentRow, pivotColumn);
                if(currentRatio > 0 && (currentRatio < smallestRatio || smallestRatio < 0))
                {
                    smallestRatio = currentRatio;
                    pivotRow = currentRow;
                }
            }
        }
        return pivotRow;
    }
    else
    {
        const int solutionColumn = this->numberOfColumns-1;
        int pivotRow = 1;
        double mostNegativeValue = this->get_valueAt(1, solutionColumn);
        for(int currentRow = 2; currentRow < (this->numberOfColumns-1); currentRow++)
        {
            if(this->get_valueAt(currentRow, solutionColumn) < mostNegativeValue)
            {
                mostNegativeValue = this->get_valueAt(currentRow, solutionColumn);
                pivotRow = currentRow;
            }
        }
        return pivotRow;
    }
}
int SimplexTable::get_pivotColumnIndex(bool isTableFeasible)
{
    if(isTableFeasible)
    {
        const int zRow = 0;
        int pivotColumn = 0;
        double mostNegativeValue = this->get_valueAt(zRow, 0);
        for(int currentColumn = 1; currentColumn < (this->numberOfColumns-1); currentColumn++)
        {
            if(this->get_valueAt(zRow, currentColumn) < mostNegativeValue)
            {
                mostNegativeValue = this->get_valueAt(zRow, currentColumn);
                pivotColumn = currentColumn;
            }
        }
        return pivotColumn;
    }
    else
    {
        const int pivotRow = this->get_pivotRowIndex(isTableFeasible);
        const int zRow = 0;
        int currentColumn = 0;
        int pivotColumn = 0;
        double smallestRatio = this->get_valueAt(zRow, currentColumn) / this->get_valueAt(pivotRow, currentColumn);
        //std::cout << std::endl << "samllestRatio 1st: " << smallestRatio << std::endl;
        for(currentColumn++; currentColumn < this->numberOfColumns-1; currentColumn++)
        {
            double currentZRowValue = this->get_valueAt(zRow, currentColumn);
            if(this->get_valueAt(pivotRow, currentColumn) != 0)
            {
                std::cout << "entered the if: " << currentColumn << std::endl;
                double currentRatio = currentZRowValue / this->get_valueAt(pivotRow, currentColumn);
                if(currentRatio > 0 && (currentRatio < smallestRatio || smallestRatio < 0))
                {
                    smallestRatio = currentRatio;
                    pivotColumn = currentColumn;
                }
            }
        }
        return pivotColumn;
    }
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
void SimplexTable::simplexIteration(const int pivotRow, const int pivotColumn)
{
    double currentRowValue = this->get_valueAt(pivotRow, 0), pivotColumnValue = this->get_valueAt(pivotRow, pivotColumn);
    for(int rowIndex = -1; rowIndex < this->numberOfRows; rowIndex++)
    {
        //cout << "iterated trhough" << endl;
        if(rowIndex != -1 && rowIndex != pivotRow)
        {
            pivotColumnValue = this->get_valueAt(rowIndex, pivotColumn);
            for(int columnIndex = 0; columnIndex < this->numberOfColumns; columnIndex++)
            {
                currentRowValue = this->get_valueAt(rowIndex, columnIndex);
                this->set_valueAt(rowIndex, columnIndex,  currentRowValue - pivotColumnValue*(this->get_valueAt(pivotRow, columnIndex)));
            }
        }
        else if(rowIndex == -1)
        {
            /*cout << "ptr_PivotRow: " << ptr_pivotRow << endl;
            cout << "*ptr_PivotRow: " << *ptr_pivotRow << endl;*/
            for(int columnIndex = 0; columnIndex < this->numberOfColumns; columnIndex++)
            {
                this->set_valueAt(pivotRow, columnIndex, currentRowValue / pivotColumnValue);
                currentRowValue = this->get_valueAt(pivotRow, columnIndex+1);
            }
            //cout << "ptr_PivotRow: " << ptr_pivotRow << endl;
            //int num;
            //cin >> num;
        }
    }
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
    std::cout << std::endl;
    for(int i = 0; i < numberOfColumns * numberOfRows; i++)
    {
        std::cout << "| " << this->table[i] << " |";
        if((i+1)%numberOfColumns == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}
void SimplexTable::solveTable()
{
    if(!isTableFeasible())
    {
        this->simplexIteration(this->get_pivotRowIndex(false), this->get_pivotColumnIndex(false));
    }
    else if(!isTableOptimum())
    {
        this->simplexIteration(this->get_pivotRowIndex(true), this->get_pivotColumnIndex(true));
    }
    this->printTable();
    if(!isTableFeasible() || !isTableOptimum())
        this->solveTable();

}
