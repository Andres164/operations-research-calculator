#pragma once
#include <vector>

class SimplexTable
{
protected:
    std::vector<double> table;
    int numberOfDecisionVariables;
    int numberOfHolguras;
    int numberOfRows;
    int numberOfColumns;

    // Protected Methods
    void initializeHolguras();
    void dualSimplexIteration();
public:
    void set_valueAt(int row, int column, double value);
    double get_valueAt(int row, int column);

    void simplexIteration(const int pivotRow, const int pivotColumn);
    int get_pivotRowIndex(bool isTableFeasibl);
    int get_pivotColumnIndex(bool isTableFeasible);
    // Constructors
    SimplexTable(int vNumberOfDecisionVariables, int vNumberOfHolguras);

    // Methods

    bool isTableFeasible();
    bool isTableOptimum();
    void printTable();
    void solveTable();

    // Getters

    // Setters
};
