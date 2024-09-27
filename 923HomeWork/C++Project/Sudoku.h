#ifndef _Sudoku_H_
#define _Sudoku_H_

#include <iostream>
#include <string>
#include "Grid.h"
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/vector.hpp>

class Sudoku : public Grid {
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& boost::serialization::base_object<Grid>(*this);
    }
public:
    Sudoku();
    Sudoku(int bs, int gs);
    void parse(std::string str);   //解析字符串
    void getInference(int row, int col); //推理
    bool isValid(int row, int col, int num); //判断是否有效       
    ~Sudoku();
};

#endif