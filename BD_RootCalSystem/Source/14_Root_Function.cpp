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
            Buff_Num=4;
            break;
        case 6:
            Buff_Num=5;
            break;
        case 7:
            Buff_Num=5;
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
            Buff_Num=3;
            break;
        case 5:
            Buff_Num=4;
            break;
        case 6:
            Buff_Num=9;
            break;
        case 7:
            Buff_Num=10;
            break;
        default:
            break;
    }
    return Buff_Num;
}