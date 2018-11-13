//
// Created by DongHoon Kim on 11/10/2018.
//

#include <iostream>
#include "Header/Global_Function.h"

int INT_MinDistanceByType_12(int Root_Type){
    int Buff_Num;

    Buff_Num=Root_Type/10;
    switch(Buff_Num){
        case 4:
            Buff_Num=0;
            break;
        case 5:
            Buff_Num=5;
            break;
        case 6:
            Buff_Num=6;
            break;
        case 7:
            Buff_Num=6;
            break;
        default:
            break;
    }
    return Buff_Num;
}

int INT_MaxDistanceByType_12(int Root_Type){
    int Buff_Num;

    Buff_Num=Root_Type/10;

    switch(Buff_Num){
        case 4:
            Buff_Num=4;
            break;
        case 5:
            Buff_Num=5;
            break;
        case 6:
            Buff_Num=8;
            break;
        case 7:
            Buff_Num=9;
            break;
        default:
            break;
    }
    return Buff_Num;
}

void VOID_RootMapBoundary_12(int **INT_Array_RootMap){

    for(int i0=2;i0<27;i0++){
        INT_Array_RootMap[0][i0]=99;
        INT_Array_RootMap[26][i0]=99;
        INT_Array_RootMap[i0][0]=99;
        INT_Array_RootMap[i0][26]=99;
    }
    for(int i0=0;i0<29;i0++){
        INT_Array_RootMap[i0][1]=99;
        INT_Array_RootMap[i0][27]=99;
        INT_Array_RootMap[1][i0]=99;
        INT_Array_RootMap[27][i0]=99;
    }
}