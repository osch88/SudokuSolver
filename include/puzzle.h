#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "variables.h"

class Puzzle
{
private:
    std::string SudokuLine;
    std::string solved;

    SudokuCell_t SudokuTable[SIZE][SIZE];
    minHypos_t minHypos;

    unsigned int valueSetCounter = 0;
    unsigned int guessCounter = 0;

    bool solver();
    bool parser();

    bool constraintPropagation();
    void runUnits(const unsigned int &row, const unsigned int &col);
    void loopPuzzle();

    // Hypos
    void hypoRow(const unsigned int &row, const unsigned int &col);
    void hypoColumn(const unsigned int &row, const unsigned int &col);
    void hypoBox(const unsigned int &row, const unsigned int &col);
    void updateHypos(const unsigned int &row, const unsigned int &col);
    unsigned int findUniqueHypoValue(const unsigned int &row, const unsigned int &col);
    void setValueToCellFromHypo(const unsigned int &row, const unsigned int &col);

    // Peers
    void valueInRow(const unsigned int &row, const unsigned int &col);
    void valueInCol(const unsigned int &row, const unsigned int &col);
    void valueInBox(const unsigned int &row, const unsigned int &col);
    void findUniquePeer(const unsigned int &row, const unsigned int &col);
    unsigned int findUniquePeerValue(const unsigned int &row, const unsigned int &col);
    void setValueToCellFromPeer(const unsigned int &row, const unsigned int &col);

    // Search
    bool findSmallestHypo();
    bool search();

public:
    Puzzle(const std::string &_SudokuLine);
    ~Puzzle() = default;

    void printSudokuOnOneLine();
    void print();
    std::string getSolverName();
    unsigned int getAmountSetValues();
    unsigned int getAmountOfGuesses();
};

#endif