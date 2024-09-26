#include <iostream>
#include "Grid.h"

Grid::Grid(){};

Grid::Grid(int bs,int gs): BOX_SIZE(bs),GRID_SIZE(gs){
    grid = new int*[gs];
    for(int i = 0;i < gs;i++){
        grid[i] = new int[gs];
        //初始化为0 表示空
        for(int j = 0;j < gs;j++){
            grid[i][j] = 0;
        }
    }
};

int* Grid::getRow(int row){
    if(row < 0 || row >= GRID_SIZE) {
        throw std::out_of_range("Row index out of range");
    }
    return grid[row];
}

int* Grid::getColumn(int col){
    if(col < 0 || col >= GRID_SIZE){
        throw std::out_of_range("Col index out of range");
    }
    int* gridcol = new int[GRID_SIZE];
    for(int i = 0;i < GRID_SIZE;i++){
        gridcol[i] = grid[i][col];
    }
    return gridcol;
}

int** Grid::getBox(int row,int col){
    if(row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE){
        throw std::out_of_range("Box index out of range");
    }
    row = row / BOX_SIZE * BOX_SIZE;
    col = col / BOX_SIZE * BOX_SIZE;
    int** box = new int*[BOX_SIZE];
    for(int i = 0;i < BOX_SIZE;i++){
        box[i] = &grid[row + i][col];
    }
    return box;
}

void Grid::setValue(int row,int col,int value){
    if(row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE){
        throw std::out_of_range("index out of range");
    }
    grid[row][col] = value;
}

int Grid::getValue(int row,int col){
    if(row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE){
        throw std::out_of_range("index out of range");
    }
    return grid[row][col];
}

int Grid::getBoxSize(){
    return  this->BOX_SIZE;
}

int Grid::getGridSize(){
    return this->GRID_SIZE;
}

void Grid::print(){
    for(int i = 0;i < GRID_SIZE;i++){
        for(int j = 0;j < GRID_SIZE;j++){
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout<<std::endl;
}

Grid::~Grid(){
    for(int i = 0;i < GRID_SIZE;i++){
        delete[] grid[i];
    }
    delete[] grid;
}