//
// Created by MonkeyThunder on 2018-10-06.
//

class Root_Map_14{

private:
    int Map_Array_14[29][29];//14+15(Wall)
    int Buff_Map_Array_14[29][29];
    int Root_Path_Array_14[50][50][2];

public:
    Root_Map_14();

    void Map_Initialize_14();
    void Set_Flower_14();

    void Path_Initialize();

    void RootTypeToSetWall(int Type, int INT_X, int INT_Y);

    int AStarAlgorithm(int Path_Index,int Min_Distance, int Start_X, int Start_Y, int Dest_X, int Dest_Y);

    void FindRoute(int INT_Input);

    void Print_Data();
    void Buff_Print_Data();
};