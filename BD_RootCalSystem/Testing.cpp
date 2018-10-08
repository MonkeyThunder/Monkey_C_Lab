//
// Created by DongHoon Kim on 08/10/2018.
//

#include <iostream>

#include "Source/Header/Class_RootMap.h"
#include "Source/Header/Global_Function.h"
#include "Source/Header/Algorithm_PointToCenter.h"
#include "Source/Header/14_Root_Function.h"

int main(){
    int Test_Num_01=50464;
    int Test_Num_02=60499;

    Root_Map_14 TestClass;

    TestClass.NumberToArray_14(Test_Num_01);

    TestClass.Print_Data();

    std::cout<<AStarAlgorithm(5,0,5,4,6,4,TestClass.Map_Array_14);

    return 0;
}