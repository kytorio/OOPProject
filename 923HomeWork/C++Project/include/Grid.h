#ifndef _GRID_H_
#define _GRID_H_

#include <iostream>

class Grid{
    protected:
        int BOX_SIZE;   //子方块大小
        int GRID_SIZE;  //网格大小
        int** grid;
    public:
        Grid();
        Grid(int bs,int gs);
        int* getRow(int row);   //获取指定行内容
        int* getColumn(int col);    //获取指定列内容
        int** getBox(int row,int col);   //获取指定子方块内容,且为浅拷贝
        void setValue(int row,int col,int value);   //设置单元格值
        int getValue(int row,int col);  //获取单元格值
        void print();   //打印网格内值
        int getBoxSize();
        int getGridSize();
        ~Grid();
};

#endif