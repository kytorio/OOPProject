#include <iostream>
#include <string>
#include "Grid.h"
#include "Sudoku.h"

int main(){
    std::string str = "000840009010209008008000500000036090600000001090750000005000800400508060100064000";
    Sudoku sudoku;
    sudoku.parse(str);
    sudoku.print();
    sudoku.getInference(0,0);
    return 0;
}