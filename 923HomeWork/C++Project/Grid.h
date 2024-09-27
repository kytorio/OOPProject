#ifndef _GRID_H_
#define _GRID_H_

#include <iostream>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/vector.hpp>
#include <vector>

class Grid {

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& BOX_SIZE;
        ar& GRID_SIZE;
        ar& grid;
    }

protected:
    int BOX_SIZE;   //子方块大小
    int GRID_SIZE;  //网格大小
    std::vector<std::vector<int>> grid;
public:
    Grid();
    Grid(int bs, int gs);
    std::vector<int> getRow(int row);   //获取指定行内容
    std::vector<int> getColumn(int col);    //获取指定列内容
    std::vector<int> getBox(int row, int col);   //获取指定子方块内容,且为浅拷贝
    void setValue(int row, int col, int value);   //设置单元格值
    int getValue(int row, int col);  //获取单元格值
    void print();   //打印网格内值
    int getBoxSize();
    int getGridSize();
    ~Grid();
};

#endif