//
// Created by DongHoon Kim on 08/10/2018.
//

void VOID_CopyRootMap(int **INT_Original, int **INT_Copy);


int INT_Distance(int INT_Start_X, int INT_Start_Y, int INT_Dest_X, int INT_Dest_Y);

int INT_RouteCost(int INT_Start_X, int INT_Start_Y, int INT_Dest_X, int INT_Dest_Y, int **INT_Array_RootMap);

int INT_OneStepRoute(int INT_Integer, int INT_X, int INT_Y, int *INT_Xout, int *INT_Yout, int **INT_Array_RootMap, bool **BOOL_CheckRouteDirection);


void VOID_NumberToTypeXY(int INT_Input, int *Type, int *INT_X, int *INT_Y);

void VOID_Center_Location(int Center_INDEX, int *INT_X, int *INT_Y);

void VOID_Front_Back_XY_RootType(int ForE, int Type,int *INT_X, int *INT_Y);


int INT_FindPossiblePathPointToPoint(int INT_Start_X, int INT_Start_Y, int INT_Dest_X, int INT_Dest_Y, int INT_MaxDistance, int INT_MinDistance, int ***INT_ArrayResultOut, int **INT_Array_RootMap);