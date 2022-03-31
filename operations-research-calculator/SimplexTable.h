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
    void set_valueAt(int row, int column, double value);
    double get_valueAt(int row, int column);
    int get_pivotRowIndex();
    int get_pivotColumnIndex();
    void initializeHolguras();
    void simplexIteration();
    void dualSimplexIteration();
public:
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
