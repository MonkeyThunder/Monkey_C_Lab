//
// Created by DongHoon Kim on 08/10/2018.
//

void VOID_CopyRootMap(int **INT_Original, int **INT_Copy);

void VOID_Print_Data(int **INT_Array_RootMap);


int INT_Distance(int INT_Start_X, int INT_Start_Y, int INT_Dest_X, int INT_Dest_Y);

int INT_RouteCost(int INT_Start_X, int INT_Start_Y, int INT_Dest_X, int INT_Dest_Y, int **INT_Array_RootMap);

int INT_OneStepRoute(int INT_Integer, int INT_X, int INT_Y, int *INT_Xout, int *INT_Yout, int **INT_Array_RootMap, bool **BOOL_CheckRouteDirection, bool BOOL_Log);


void VOID_NumberToTypeXY(int INT_Input, int *Type, int *INT_X, int *INT_Y);

void VOID_Center_Location(int Center_INDEX, int *INT_X, int *INT_Y);

void VOID_Front_Back_XY_RootType(int ForE, int Type,int *INT_X, int *INT_Y);


int INT_NumberOfPossibleRoute(int INT_MaxDistance);

int INT_FindPossiblePathPointToPoint(int INT_Start_X, int INT_Start_Y, int INT_Dest_X, int INT_Dest_Y, int INT_MaxDistance, int INT_MinDistance, int ***INT_ArrayResultOut, int **INT_Array_RootMap);


bool BOOL_FindIsolatedCellRecursive(int INT_X, int INT_Y, int INT_ComingDirection, int **INT_Array_RootMap);

void VOID_IsolatedUnkownCells(int **INT_ArrayResultOut, int INT_MapSize, int **INT_Array_RootMap);

void VOID_FindIsolatedCell(int INT_StartX, int INT_StartY, int **INT_Array_RootMap);