//
// Created by DongHoon Kim on 10/10/2018.
//
#include <iostream>
#include "Header/Global_Function.h"

#include "Header/InsertDataToMap.h"

#include "Header/14_Root_Function.h"
#include "Header/12_Root_Function.h"


std::string STR_AllRouteOfRoot(int INT_RootMapSize, int **INT_Array_RootMap) {

    int INT_X, INT_Y;

    int INT_Xout, INT_Yout;

    int INT_RouteMaxLength=0;
    int INT_RouteMinLength=0;
    int INT_RouteLength;
    int INT_LongestRouteLength;

    int INT_Buff00, INT_Buff01;
    int INT_Array_Buff00[13][2];

    std::string STR_OUT;

    int** INT_Array_RootMap_Buff = new int*[29]; //wall-root-wall = 14 * 2 + 1
    for(int i0=0;i0<29;i0++){
        INT_Array_RootMap_Buff[i0] = new int[29];
    }

    bool BOOL_CheckRouteDirection[13][4];


    if(INT_RootMapSize==12){

        INT_RouteMaxLength=INT_MaxDistanceByType_12(70);
        INT_RouteMinLength=INT_MinDistanceByType_12(70);

    }else if(INT_RootMapSize==14){

        INT_RouteMaxLength=INT_MaxDistanceByType_14(70);//Root type = end
        INT_RouteMinLength=INT_MinDistanceByType_14(70);

    }


    VOID_CopyRootMap(INT_Array_RootMap,INT_Array_RootMap_Buff);

    for (int i0 = 0; i0 < 16; i0++) {

        VOID_Center_Location(i0, &INT_X, &INT_Y);

        //------------------------------
        //Initialize
        for(int i1=0;i1<13;i1++){
            for(int i2=0;i2<4;i2++){
                BOOL_CheckRouteDirection[i1][i2]=true;
            }
        }

        //------------------------------

        if(INT_Array_RootMap_Buff[INT_X][INT_Y]==0){

            INT_RouteLength=1;
            INT_LongestRouteLength=1;
            std::cout<<"Before While with i0 = "<<i0<<std::endl;

            INT_Buff01=0;

            while(true){
                INT_Buff01++;
                if(INT_Buff01>50){
                    break;
                }
                //------------------------------
                INT_Array_Buff00[INT_RouteLength-1][0]=INT_X;
                INT_Array_Buff00[INT_RouteLength-1][1]=INT_Y;

                if(INT_RouteLength>=INT_RouteMaxLength){
                    std::cout<<"Break is working!"<<std::endl;
                    break;
                }

                INT_Buff00=INT_OneStepRoute(INT_RouteLength-1,INT_X,INT_Y,&INT_Xout,&INT_Yout,INT_Array_RootMap_Buff,BOOL_CheckRouteDirection);


                if(INT_Buff00==99){
                    INT_RouteLength--;
                    INT_X=INT_Array_Buff00[INT_RouteLength-1][0];
                    INT_Y=INT_Array_Buff00[INT_RouteLength-1][1];

                    BOOL_CheckRouteDirection[INT_RouteLength][0]=true;
                    BOOL_CheckRouteDirection[INT_RouteLength][1]=true;
                    BOOL_CheckRouteDirection[INT_RouteLength][2]=true;
                    BOOL_CheckRouteDirection[INT_RouteLength][3]=true;

                }

                if(INT_RouteLength==0){
                    break;
                }

                if(INT_Buff00==0){// 0 = empty - wall(0) - empty
                    INT_RouteLength++;
                    INT_LongestRouteLength=INT_RouteLength;

                    INT_X=INT_Xout;
                    INT_Y=INT_Yout;
                }

            }

            if(INT_LongestRouteLength>=INT_RouteMinLength){

                for(int i1=0;i1<INT_LongestRouteLength-1;i1++){

                    VOID_CertainRouteWall(INT_Array_Buff00[i1][0],INT_Array_Buff00[i1][1],INT_Array_RootMap_Buff);

                    //------------------------------
                    if(INT_Array_Buff00[i1][0]<10){
                        STR_OUT+="0";
                    }
                    STR_OUT+=std::to_string(INT_Array_Buff00[i1][0]);


                    if(INT_Array_Buff00[i1][1]<10){
                        STR_OUT+="0";
                    }
                    STR_OUT+=std::to_string(INT_Array_Buff00[i1][1]);
                    STR_OUT+=",";

                    //------------------------------
                }
            }

        }
        STR_OUT+="-";
    }

    for(int i0=0;i0<29;i0++){
        delete[] INT_Array_RootMap_Buff[i0];
    }
    delete[] INT_Array_RootMap_Buff;

    return STR_OUT;
}