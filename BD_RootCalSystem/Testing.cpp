//
// Created by DongHoon Kim on 08/10/2018.
//

#include <iostream>

#include "Source/Header/Global_Function.h"
#include "Source/Header/InsertDataToMap.h"
#include "Source/Header/Find_All_Route.h"
#include "Source/Header/12_Root_Function.h"
#include "Source/Header/14_Root_Function.h"

int main(){

    int** INT_Array_RootMap_14 = new int*[29]; //wall-root-wall = 14 * 2 + 1
    for(int i0=0;i0<29;i0++){
        INT_Array_RootMap_14[i0] = new int[29];
    }

    int INT_MaxDistance = 6;

    int INT_NumberOfPossible;
    INT_NumberOfPossible=INT_NumberOfPossibleRoute(INT_MaxDistance);

    int*** INT_ArrayOut = new int**[INT_NumberOfPossible];
    for(int i0=0;i0<INT_NumberOfPossible;i0++){
        INT_ArrayOut[i0]= new int *[INT_MaxDistance];
        for(int i1=0;i1<INT_MaxDistance;i1++){
            INT_ArrayOut[i0][i1]=new int[2];
        }
    }

    for(int i0=0;i0<INT_NumberOfPossible;i0++){
        for(int i1=0;i1<INT_MaxDistance;i1++){
            INT_ArrayOut[i0][i1][0]=0;
            INT_ArrayOut[i0][i1][1]=0;
        }
    }

    std::string STR_OutData;

    int Test_Num_01=50499;
    int Test_Num_02=60499;

    VOID_SetCenterFlowers(INT_Array_RootMap_14);

    VOID_RootMapBoundary_14(INT_Array_RootMap_14);


    VOID_DataToMap(INT_Array_RootMap_14,20099); //<-Real x,y location not 'with wall' number
    VOID_DataToMap(INT_Array_RootMap_14,10199);
    VOID_DataToMap(INT_Array_RootMap_14,10299);
    VOID_DataToMap(INT_Array_RootMap_14,399);

    VOID_Print_Data(INT_Array_RootMap_14);

    VOID_FindIsolatedCell(INT_Array_RootMap_14);

    VOID_Print_Data(INT_Array_RootMap_14);


    //std::cout<<INT_FindPossiblePathPointToPoint(1,1,7,5,INT_MaxDistance,1,INT_ArrayOut,INT_Array_RootMap_14)<<std::endl;
    /*

    //VOID_DataToMap(INT_Array_RootMap_14,Test_Num_01);

    std::cout<<"Before STR"<<std::endl;
    STR_OutData = STR_AllRouteOfRoot(14,INT_Array_RootMap_14);
    std::cout<<"After STR"<<std::endl;

    std::cout<<STR_OutData<<std::endl;
*/
    for(int i0=0;i0<29;i0++){
        delete[] INT_Array_RootMap_14[i0];
    }
    delete[] INT_Array_RootMap_14;

    for(int i0=0;i0<INT_NumberOfPossible;i0++){
        for(int i1=0;i1<INT_MaxDistance;i1++){
            delete[] INT_ArrayOut[i0][i1];
        }
        delete[] INT_ArrayOut[i0];
    }
    delete[] INT_ArrayOut;

    return 0;
}