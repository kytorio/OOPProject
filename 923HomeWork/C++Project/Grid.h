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
    int BOX_SIZE;   //�ӷ����С
    int GRID_SIZE;  //�����С
    std::vector<std::vector<int>> grid;
public:
    Grid();
    Grid(int bs, int gs);
    std::vector<int> getRow(int row);   //��ȡָ��������
    std::vector<int> getColumn(int col);    //��ȡָ��������
    std::vector<int> getBox(int row, int col);   //��ȡָ���ӷ�������,��Ϊǳ����
    void setValue(int row, int col, int value);   //���õ�Ԫ��ֵ
    int getValue(int row, int col);  //��ȡ��Ԫ��ֵ
    void print();   //��ӡ������ֵ
    int getBoxSize();
    int getGridSize();
    ~Grid();
};

#endif