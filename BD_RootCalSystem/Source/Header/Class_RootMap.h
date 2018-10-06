//
// Created by MonkeyThunder on 2018-10-06.
//

#ifndef ROOT_ALGORITHM_CLASS_ROOTMAP_H
#define ROOT_ALGORITHM_CLASS_ROOTMAP_H

class Root_Map_14{

private:
    int Map_Array_14[29][29];//14+15(Wall)
    int Buff_Map_Array_14[29][29];
    int Root_Path_Array_14[50][50][2];

public:
    void Map_Initialize();
    void Path_Initialize();
    void Set_Flower();
    void CopyArrayToBuff();

    void NumberToArray_14(int INT_Input);
    void NumberToArray_14(int INT_Input, int *Type, int *INT_X, int *INT_Y);

    void Center_Location(int Center_INDEX, int *INT_X, int *INT_Y);
    int Distance(int Start_X, int Start_Y, int Dest_X, int Dest_Y);
    int MinDistanceByType(int Root_Type);
    int MaxDistanceByType(int Root_Type);
    void RootTypeToSetWall(int Type, int INT_X, int INT_Y);

    int AStarAlgorithm(int Path_Index,int Min_Distance, int Start_X, int Start_Y, int Dest_X, int Dest_Y);

    void FindRoute(int INT_Input);

    int Checking_Data(int INT_X, int INT_Y);
    void Print_Data();
    void Buff_Print_Data();
};

#endif //ROOT_ALGORITHM_CLASS_ROOTMAP_H
