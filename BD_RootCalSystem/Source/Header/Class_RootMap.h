//
// Created by MonkeyThunder on 2018-10-06.
//

#include <vector>

class Root_Map_14{

public:
    int Map_Array_14[29][29];//14+15(Wall)

    Root_Map_14();

    void Map_Initialize_14();
    void Set_Flower_14();

    void NumberToArray_14(int INT_Input);

    void RootTypeToSetWall(int Type, int INT_X, int INT_Y);

    void Print_Data();
};