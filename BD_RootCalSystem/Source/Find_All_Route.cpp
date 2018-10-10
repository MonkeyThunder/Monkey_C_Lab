//
// Created by DongHoon Kim on 10/10/2018.
//
#include <iostream>
#include "Header/Global_Function.h"

#include "Header/14_Root_Function.h"
#include "Header/12_Root_Function.h"


std::string STR_AllRouteOfRoot(int INT_RootMapSize, int **INT_Array_RootMap) {

    int INT_X, INT_Y;

    int INT_Xout, INT_Yout;

    int INT_RouteMaxLength;
    int INT_RouteLength;

    int INT_Buff00;

    std::string STR_OUT[16];

    int** INT_Array_RootMap_Buff = new int*[29]; //wall-root-wall = 14 * 2 + 1
    for(int i0=0;i0<29;i0++){
        INT_Array_RootMap_Buff[i0] = new int[29];
    }

    bool BOOL_CheckRouteDirection[9][4];
    for(int i0=0;i0<9;i0++){
        for(int i1=0;i1<4;i1++){
            BOOL_CheckRouteDirection[i0][i1]=1;
        }
    }

    if(INT_RootMapSize==12){

        INT_RouteMaxLength=INT_MaxDistanceByType_12(70);

    }else if(INT_RootMapSize==14){

        INT_RouteMaxLength=INT_MaxDistanceByType_14(70);//Root type = end

    }


    VOID_CopyRootMap(INT_Array_RootMap,INT_Array_RootMap_Buff);

    for (int i0 = 0; i0 < 16; i0++) {

        VOID_Center_Location(i0, &INT_X, &INT_Y);

        if(INT_Array_RootMap_Buff[INT_X][INT_Y]==0){

            INT_RouteLength=1;

            //------------------------------
            if(INT_X<10){
                STR_OUT[i0]+="0";
            }
            STR_OUT[i0]+=std::to_string(INT_X);
            if(INT_Y<10){
                STR_OUT[i0]+="0";
            }
            STR_OUT[i0]+=std::to_string(INT_Y);
            //------------------------------

            while(true){
                if(INT_RouteLength>=INT_RouteMaxLength){
                    break;
                }

                INT_Buff00=INT_OneStepRoute(INT_RouteLength-1,INT_X,INT_Y,&INT_Xout,&INT_Yout,INT_Array_RootMap_Buff,BOOL_CheckRouteDirection);

                if(INT_Buff00==0){
                    INT_RouteLength++;

                    INT_X=INT_Xout;
                    INT_Y=INT_Yout;

                    //------------------------------
                    if(INT_X<10){
                        STR_OUT[i0]+="0";
                    }
                    STR_OUT[i0]+=std::to_string(INT_X);
                    if(INT_Y<10){
                        STR_OUT[i0]+="0";
                    }
                    STR_OUT[i0]+=std::to_string(INT_Y);
                    //------------------------------
                }

            }
        }
    }

    for(int i0=0;i0<29;i0++){
        delete[] INT_Array_RootMap_Buff[i0];
    }
    delete[] INT_Array_RootMap_Buff;
}