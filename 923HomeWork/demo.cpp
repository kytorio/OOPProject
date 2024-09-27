#include <iostream>
#include <boost/serialization/base_object.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <string>
#include <fstream>
#include <vector>
#include <boost/serialization/vector.hpp>

class Grid{

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version){
        ar & BOX_SIZE;
        ar & GRID_SIZE;
        ar & grid;
    }
    protected:
        int BOX_SIZE;
        int GRID_SIZE;
        std::vector<std::vector<int>> grid;
    public:
        Grid();
        Grid(int bs,int gs): BOX_SIZE(bs),GRID_SIZE(gs){};


};

int main(){
    Grid grid = Grid(3,9);
    std::ofstream ofs("filename.txt");
    boost::archive::text_oarchive oa(ofs);
    oa << grid;
}