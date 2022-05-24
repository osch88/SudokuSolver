#ifndef VARIABLES_H
#define VARIABLES_H

#include <iostream>
#include <bitset>
#include <array>

const unsigned int SIZE = 9;

typedef struct SudokuCell
{
    unsigned int value;
    unsigned int initiatedValue;
    unsigned int noHypos;
    std::bitset<9> hypoBits{0b111'111'111};
    std::bitset<9> peers{0b000'000'000};
    bool valueSet = false;

} SudokuCell_t;

typedef struct CellWithMinHypos
{
    unsigned int noHypos = 10;
    unsigned int row;
    unsigned int col;
} minHypos_t;

#endif