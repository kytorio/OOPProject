#include <iostream>
#include "Grid.h"

Grid::Grid() {};

Grid::Grid(int bs, int gs) : BOX_SIZE(bs), GRID_SIZE(gs) {
    std::vector<std::vector<int>> grid(gs, std::vector<int>(gs));
    for (int i = 0; i < gs; i++) {
        //初始化为0 表示空
        for (int j = 0; j < gs; j++) {
            grid[i][j] = 0;
        }
    }
};

std::vector<int> Grid::getRow(int row) {
    if (row < 0 || row >= GRID_SIZE) {
        throw std::out_of_range("Row index out of range");
    }
    return grid[row];
}

std::vector<int> Grid::getColumn(int col) {
    if (col < 0 || col >= GRID_SIZE) {
        throw std::out_of_range("Col index out of range");
    }
    std::vector<int> gridcol(GRID_SIZE);
    for (int i = 0; i < GRID_SIZE; i++) {
        gridcol[i] = grid[i][col];
    }
    return gridcol;
}

std::vector<int> Grid::getBox(int row, int col) {
    if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE) {
        throw std::out_of_range("Box index out of range");
    }
    int startrow = row - row % BOX_SIZE;
    int startcol = col - col % BOX_SIZE;
    std::vector<int> box;
    for (int i = 0; i < BOX_SIZE; i++) {
        for (int j = 0; j < BOX_SIZE; j++)
            box.push_back(grid[startrow + i][startcol + j]);
    }
    return box;
}

void Grid::setValue(int row, int col, int value) {
    if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE) {
        throw std::out_of_range("index out of range");
    }
    grid[row][col] = value;
}

int Grid::getValue(int row, int col) {
    if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE) {
        throw std::out_of_range("index out of range");
    }
    return this->grid[row][col];
}

int Grid::getBoxSize() {
    return  this->BOX_SIZE;
}

int Grid::getGridSize() {
    return this->GRID_SIZE;
}

void Grid::print() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

Grid::~Grid() {}