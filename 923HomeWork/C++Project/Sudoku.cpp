#include <iostream>
#include <string>
#include <math.h>
#include "Sudoku.h"
#include <vector>
Sudoku::Sudoku() {};

Sudoku::Sudoku(int bs, int gs) : Grid(bs, gs) {};

void Sudoku::parse(std::string str) {
    int gs = (int)sqrt(str.length());
    int bs = (int)sqrt(gs);
    this->BOX_SIZE = bs;
    this->GRID_SIZE = gs;
    this->grid.assign(gs, std::vector<int>(gs, 0));
    for (int i = 0; i < gs; i++) {
        for (int j = 0; j < gs; j++) {
            this->grid[i][j] = str[i * gs + j] - '0';
        }
    }
}

void Sudoku::getInference(int row, int col) { //回溯推理
    if (row == this->GRID_SIZE - 1 && col == this->GRID_SIZE) {
        this->print();
        return;
    }
    if (col == this->GRID_SIZE) {
        row++;
        col = 0;
    }
    if (this->grid[row][col] == 0) {
        for (int digit = 1; digit <= 9; digit++) {
            if (this->isValid(row, col, digit)) {
                this->setValue(row, col, digit);
                this->getInference(row, col + 1);
                this->setValue(row, col, 0);
            }
        }
    }
    else {
        this->getInference(row, col + 1);
    }
}


bool Sudoku::isValid(int row, int col, int num) {
    //检查行重复
    std::vector<int>temprow = this->getRow(row);
    for (int i = 0; i < this->GRID_SIZE; i++) {
        if (temprow[i] == num) return false;
    }

    //检查列重复
    std::vector<int> tempcol = this->getColumn(col);
    for (int i = 0; i < this->GRID_SIZE; i++) {
        if (tempcol[i] == num) return false;
    }

    //检查box重复
    std::vector<int> tempbox = this->getBox(row, col);
    for (int i = 0; i < this->BOX_SIZE; i++) {
        for (int j = 0; j < this->BOX_SIZE; j++) {
            if (tempbox[i * BOX_SIZE + j] == num) return false;
        }
    }
    return true;
}

Sudoku::~Sudoku() {
    //delete[] this;
}