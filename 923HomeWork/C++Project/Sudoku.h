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
    void parse(std::string str);   //�����ַ���
    void getInference(int row, int col); //����
    bool isValid(int row, int col, int num); //�ж��Ƿ���Ч       
    ~Sudoku();
};

#endif