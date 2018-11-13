//
// Created by DongHoon Kim on 10/10/2018.
//

#include "Header/Global_Function.h"

void VOID_RootTypeToSetWall(int Type, int INT_X, int INT_Y, int **INT_Array_RootMap){
    int Buff_Num;

    Buff_Num=Type%10;

    if(Type<70){
        switch (Buff_Num){
            case 1:
                INT_Array_RootMap[INT_X+1][INT_Y]=99;
                INT_Array_RootMap[INT_X-1][INT_Y]=99;
                break;
            case 2:
                INT_Array_RootMap[INT_X][INT_Y+1]=99;
                INT_Array_RootMap[INT_X][INT_Y-1]=99;
                break;
            case 3:
                INT_Array_RootMap[INT_X-1][INT_Y]=99;
                INT_Array_RootMap[INT_X][INT_Y+1]=99;
                break;
            case 4:
                INT_Array_RootMap[INT_X-1][INT_Y]=99;
                INT_Array_RootMap[INT_X][INT_Y-1]=99;
                break;
            case 5:
                INT_Array_RootMap[INT_X+1][INT_Y]=99;
                INT_Array_RootMap[INT_X][INT_Y-1]=99;
                break;
            case 6:
                INT_Array_RootMap[INT_X+1][INT_Y]=99;
                INT_Array_RootMap[INT_X][INT_Y+1]=99;
                break;
            default:
                break;
        }
    }
    else if(Type>70){
        switch (Buff_Num){
            case 1:
                INT_Array_RootMap[INT_X+1][INT_Y]=99;
                INT_Array_RootMap[INT_X-1][INT_Y]=99;
                INT_Array_RootMap[INT_X][INT_Y+1]=99;
                break;
            case 2:
                INT_Array_RootMap[INT_X-1][INT_Y]=99;
                INT_Array_RootMap[INT_X][INT_Y-1]=99;
                INT_Array_RootMap[INT_X][INT_Y+1]=99;
                break;
            case 3:
                INT_Array_RootMap[INT_X+1][INT_Y]=99;
                INT_Array_RootMap[INT_X-1][INT_Y]=99;
                INT_Array_RootMap[INT_X][INT_Y-1]=99;
                break;
            case 4:
                INT_Array_RootMap[INT_X+1][INT_Y]=99;
                INT_Array_RootMap[INT_X][INT_Y-1]=99;
                INT_Array_RootMap[INT_X][INT_Y+1]=99;
                break;
            case 8:
                INT_Array_RootMap[INT_X-1][INT_Y]=99;
                INT_Array_RootMap[INT_X+1][INT_Y]=99;
                INT_Array_RootMap[INT_X][INT_Y-1]=99;
                INT_Array_RootMap[INT_X][INT_Y+1]=99;
                break;
            case 9:
                INT_Array_RootMap[INT_X-1][INT_Y]=99;
                INT_Array_RootMap[INT_X+1][INT_Y]=99;
                INT_Array_RootMap[INT_X][INT_Y-1]=99;
                INT_Array_RootMap[INT_X][INT_Y+1]=99;
                break;
            default:
                break;
        }
    }
}

void VOID_CertainRouteWall(int INT_X, int INT_Y, int **INT_Array_RootMap){

    INT_Array_RootMap[INT_X+1][INT_Y]=99;
    INT_Array_RootMap[INT_X-1][INT_Y]=99;
    INT_Array_RootMap[INT_X][INT_Y+1]=99;
    INT_Array_RootMap[INT_X][INT_Y-1]=99;

}

void VOID_SetCenterFlowers(int **INT_Array_RootMap){
    for(int i0=5;i0<9;i0++){
        for(int i1=5;i1<9;i1++){
            INT_Array_RootMap[2*i0+1][2*i1+1]=99;
        }
    }
}

void VOID_DataToMap(int **INT_Array_RootMap,int INT_InputData){

    int INT_Type, INT_X, INT_Y;
    VOID_NumberToTypeXY(INT_InputData,&INT_Type,&INT_X,&INT_Y);

    INT_Array_RootMap[INT_X][INT_Y]=INT_Type;

    VOID_RootTypeToSetWall(INT_Type,INT_X,INT_Y,INT_Array_RootMap);
    VOID_CertainRouteWall(INT_X,INT_Y,INT_Array_RootMap);
}