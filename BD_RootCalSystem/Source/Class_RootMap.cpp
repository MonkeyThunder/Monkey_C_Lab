//
// Created by DongHoon Kim on 08/10/2018.
//
#include "Header/Class_RootMap.h"
#include <iostream>

Root_Map_14::Root_Map_14() {
    Map_Initialize_14();
    Set_Flower_14();
}

//------------------------------

void Root_Map_14::Map_Initialize_14() {
    for(int i0=0;i0<29;i0++){
        for(int i1=0;i1<29;i1++){
            Map_Array_14[i1][i0]=0;
        }
    }

    for(int i0=0;i0<15;i0++){
        for(int i1=0;i1<15;i1++){
            Map_Array_14[2*i0][2*i1+1]=1;
            Map_Array_14[2*i0+1][2*i1]=1;
        }
        Map_Array_14[2*i0+1][0]=99;
        Map_Array_14[2*i0+1][28]=99;
        Map_Array_14[0][2*i0+1]=99;
        Map_Array_14[28][2*i0+1]=99;
    }
}
void Root_Map_14::Set_Flower_14() {
    for(int i0=10;i0<19;i0++){
        for(int i1=10;i1<19;i1++){
            Map_Array_14[i0][i1]=97;
        }
    }
}

//------------------------------

void Root_Map_14::NumberToArray_14(int INT_Input) {
    int Buff_Num_X, Buff_Num_Y, Buff_Num_Type;

    Buff_Num_Type=(INT_Input%100);

    Buff_Num_Y=2*((INT_Input%10000-Buff_Num_Type)/100)-1;

    Buff_Num_X=2*(INT_Input/10000)-1;

    Map_Array_14[Buff_Num_X][Buff_Num_Y]=Buff_Num_Type;

    RootTypeToSetWall(Buff_Num_Type,Buff_Num_X,Buff_Num_Y);

    //std::cout<< Buff_Num_X << ", " << Buff_Num_Y << " = " << Buff_Num_Type <<std::endl;
}


void Root_Map_14::RootTypeToSetWall(int Type, int INT_X, int INT_Y){
    int Buff_Num;

    Buff_Num=Type%10;

    if(Type<70){
        switch (Buff_Num){
            case 1:
                if(INT_X<27){
                    Map_Array_14[INT_X+1][INT_Y]=99;
                }
                if(INT_X>0){
                    Map_Array_14[INT_X-1][INT_Y]=99;
                }
                break;
            case 2:
                if(INT_Y<27){
                    Map_Array_14[INT_X][INT_Y+1]=99;
                }
                if(INT_Y>0){
                    Map_Array_14[INT_X][INT_Y-1]=99;
                }
                break;
            case 3:
                if(INT_X>0){
                    Map_Array_14[INT_X-1][INT_Y]=99;
                }
                if(INT_Y<27){
                    Map_Array_14[INT_X][INT_Y+1]=99;
                }
                break;
            case 4:
                if(INT_X>0){
                    Map_Array_14[INT_X-1][INT_Y]=99;
                }
                if(INT_Y>0){
                    Map_Array_14[INT_X][INT_Y-1]=99;
                }
                break;
            case 5:
                if(INT_X<27){
                    Map_Array_14[INT_X+1][INT_Y]=99;
                }
                if(INT_Y>0){
                    Map_Array_14[INT_X][INT_Y-1]=99;
                }
                break;
            case 6:
                if(INT_X<27){
                    Map_Array_14[INT_X+1][INT_Y]=99;
                }
                if(INT_Y<27){
                    Map_Array_14[INT_X][INT_Y+1]=99;
                }
                break;
            default:
                break;
        }
    }
    else if(Type>70){
        switch (Buff_Num){
            case 1:
                Map_Array_14[INT_X+1][INT_Y]=99;
                Map_Array_14[INT_X-1][INT_Y]=99;
                Map_Array_14[INT_X][INT_Y+1]=99;
                break;
            case 2:
                Map_Array_14[INT_X-1][INT_Y]=99;
                Map_Array_14[INT_X][INT_Y-1]=99;
                Map_Array_14[INT_X][INT_Y+1]=99;
                break;
            case 3:
                Map_Array_14[INT_X+1][INT_Y]=99;
                Map_Array_14[INT_X-1][INT_Y]=99;
                Map_Array_14[INT_X][INT_Y+1]=99;
                break;
            case 4:
                Map_Array_14[INT_X+1][INT_Y]=99;
                Map_Array_14[INT_X][INT_Y-1]=99;
                Map_Array_14[INT_X][INT_Y+1]=99;
                break;
            case 8:
                Map_Array_14[INT_X-1][INT_Y]=99;
                Map_Array_14[INT_X+1][INT_Y]=99;
                Map_Array_14[INT_X][INT_Y-1]=99;
                Map_Array_14[INT_X][INT_Y+1]=99;
                break;
            case 9:
                Map_Array_14[INT_X-1][INT_Y]=99;
                Map_Array_14[INT_X+1][INT_Y]=99;
                Map_Array_14[INT_X][INT_Y-1]=99;
                Map_Array_14[INT_X][INT_Y+1]=99;
                break;
            default:
                break;
        }
    }
}

void Root_Map_14::Print_Data() {
    std::cout.fill('0');
    for(int i0=0;i0<15;i0++){
        for(int i1=0;i1<14;i1++){
            if(Map_Array_14[2*i1+1][2*i0]==1){
                std::cout << "   ||";
            }
            else{
                std::cout << "   --";
            }
        }
        std::cout<<std::endl;
        if(i0==14){
            break;
        }
        for(int i1=0;i1<15;i1++){
            if(Map_Array_14[2*i1][2*i0+1]==1){
                std::cout << " = ";
            }
            else{
                std::cout << " | ";
            }
            if(i1==14){
                break;
            }
            std::cout.width(2);
            std::cout<<Map_Array_14[2*i1+1][2*i0+1];
        }
        std::cout<<std::endl;
        if(i0==13){
            //break;
        }

    }
}
