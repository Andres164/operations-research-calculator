#pragma once
#include <vector>
#include <string>

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
public:
    // Constructors
    SimplexTable(int vNumberOfDecisionVariables, int vNumberOfHolguras);

    // Methods to see if they go in protected
    void makeIteration(const std::string MAXorMIN);
    void set_valueAt(int row, int column, double value);
    double get_valueAt(int row, int column);

    int get_pivotRowIndex(const std::string MAXorMIN);
    int get_pivotColumnIndex(const std::string MAXorMIN);

    // Methods

    bool isTableFeasible();
    bool isTableOptimum(const std::string MAXorMIN);
    void printTable();
    void solveTable(const std::string MAXorMIN);

    // Getters

    // Setters
};
