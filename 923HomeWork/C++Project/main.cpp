#include <iostream>
#include <string>
#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>
#include "Grid.h"
#include "Sudoku.h"

void saveSudoku(std::string filename, Sudoku sudoku) {
    std::ofstream ofs(filename);
    boost::archive::text_oarchive oa(ofs);
    oa << sudoku;
    ofs.close();
}


Sudoku loadSudoku(std::string filename) {
    std::ifstream ifs(filename);
    boost::archive::text_iarchive ia(ifs);
    Sudoku sudoku;
    ia >> sudoku;
    ifs.close();
    return sudoku;
}

int main() {
    std::string str = "000840009010209008008000500000036090600000001090750000005000800400508060100064000";
    Sudoku sudoku;
    sudoku.parse(str);
    std::string filename = "sudokufile.txt";

    saveSudoku(filename,sudoku);
    Sudoku sudoku_test = loadSudoku(filename);
    sudoku_test.print();
    sudoku_test.getInference(0, 0);
    return 0;
}