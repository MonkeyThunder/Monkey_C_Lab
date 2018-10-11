//
// Created by DongHoon Kim on 08/10/2018.
//
#include <iostream>
#include "Header/Global_Function.h"

int INT_MinDistanceByType_14(int Root_Type){
    int Buff_Num;

    Buff_Num=Root_Type/10;
    switch(Buff_Num){
        case 4:
            Buff_Num=0;
            break;
        case 5:
            Buff_Num=7;
            break;
        case 6:
            Buff_Num=8;
            break;
        case 7:
            Buff_Num=8;
            break;
        default:
            break;
    }
    return Buff_Num;
}

int INT_MaxDistanceByType_14(int Root_Type){
    int Buff_Num;

    Buff_Num=Root_Type/10;

    switch(Buff_Num){
        case 4:
            Buff_Num=6;
            break;
        case 5:
            Buff_Num=7;
            break;
        case 6:
            Buff_Num=12;
            break;
        case 7:
            Buff_Num=13;
            break;
        default:
            break;
    }
    return Buff_Num;
}

void VOID_RootMapBoundary_14(int **INT_Array_RootMap){

    for(int i0=0;i0<29;i0++){
        INT_Array_RootMap[0][i0]=99;
        INT_Array_RootMap[28][i0]=99;
        INT_Array_RootMap[i0][0]=99;
        INT_Array_RootMap[i0][28]=99;
    }
}