#ifndef _Sudoku_H_
#define _Sudoku_H_
#include <iostream>
#include <string>
#include "Grid.h"

class Sudoku : public Grid {
    public:
        Sudoku();
        Sudoku(int bs,int gs);
        void parse(std::string str);   //解析字符串
        void getInference(int row,int col); //推理
        bool isValid(int row,int col,int num); //判断是否有效       
        ~Sudoku();
};

#endif