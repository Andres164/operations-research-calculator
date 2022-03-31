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
    double get_valueAt(int row, int column);
    double* getPtr_pivotRow();
    double* getPtr_pivotColumn();
    void initializeHolguras();
    void simplexIteration();
    void dualSimplexIteration();
public:
    // Constructors
    SimplexTable(int vNumberOfDecisionVariables, int vNumberOfHolguras);

    // Methods

    void set_valueAt(int row, int column, double value);
    bool isTableFeasible();
    bool isTableOptimum();

    void printTable();
    void solveTable();

    // Getters

    // Setters
};
