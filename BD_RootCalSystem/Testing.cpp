//
// Created by DongHoon Kim on 08/10/2018.
//

#include <iostream>

#include "Source/Header/InsertDataToMap.h"
#include "Source/Header/Find_All_Route.h"
#include "Source/Header/12_Root_Function.h"
#include "Source/Header/14_Root_Function.h"

int main(){

    int** INT_Array_RootMap_14 = new int*[29]; //wall-root-wall = 14 * 2 + 1
    for(int i0=0;i0<29;i0++){
        INT_Array_RootMap_14[i0] = new int[29];
    }

    std::string STR_OutData;

    int Test_Num_01=50464;
    int Test_Num_02=60499;

    VOID_RootMapBoundary_14(INT_Array_RootMap_14);

    //VOID_DataToMap(INT_Array_RootMap_14,Test_Num_01);

    std::cout<<"Before STR"<<std::endl;
    STR_OutData = STR_AllRouteOfRoot(14,INT_Array_RootMap_14);
    std::cout<<"After STR"<<std::endl;

    std::cout<<STR_OutData<<std::endl;

    for(int i0=0;i0<29;i0++){
        delete[] INT_Array_RootMap_14[i0];
    }
    delete[] INT_Array_RootMap_14;

    return 0;
}