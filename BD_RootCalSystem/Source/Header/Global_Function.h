//
// Created by DongHoon Kim on 08/10/2018.
//

int INT_Distance(int INT_Start_X, int INT_Start_Y, int INT_Dest_X, int INT_Dest_Y);
void VOID_Front_Back_XY_RootType(int ForE, int Type,int *INT_X, int *INT_Y);

std::string AStarAlgorithm(int INT_MinDistance, int INT_MaxDistance, int INT_StartX, int INT_StartY, int INT_DestX, int INT_DestY, int Root_Map[29][29]);