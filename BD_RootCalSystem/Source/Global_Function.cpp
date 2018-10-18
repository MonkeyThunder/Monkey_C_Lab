//
// Created by DongHoon Kim on 08/10/2018.
//

#include <iostream>

void VOID_CopyRootMap(int **INT_Original, int **INT_Copy) {

    for (int i0 = 0; i0 < 29; i0++) {
        for (int i1 = 0; i1 < 29; i1++) {
            INT_Copy[i0][i1]=INT_Original[i0][i1];
        }
    }
}

//------------------------------

int INT_Distance(int INT_Start_X, int INT_Start_Y, int INT_Dest_X, int INT_Dest_Y) {

    return abs(INT_Start_X-INT_Dest_X)/2+abs(INT_Start_Y-INT_Dest_Y)/2;
}

int INT_RouteCost(int INT_Start_X, int INT_Start_Y, int INT_Dest_X, int INT_Dest_Y, int **INT_Array_RootMap){

    if(INT_Start_X-INT_Dest_X){//X direction Move
        if(INT_Start_X<INT_Dest_X){
            return INT_Array_RootMap[INT_Start_X+1][INT_Start_Y];
        }
        else{
            return INT_Array_RootMap[INT_Start_X-1][INT_Start_Y];
        }
    }
    else if(INT_Start_Y-INT_Dest_Y){//Y direction Move
        if(INT_Start_Y<INT_Dest_Y){
            return INT_Array_RootMap[INT_Start_X][INT_Start_Y+1];
        }
        else{
            return INT_Array_RootMap[INT_Start_X][INT_Start_Y-1];
        }
    }
    else{
        return 0;
    }
}

int INT_OneStepRoute(int INT_Integer, int INT_X, int INT_Y, int *INT_Xout, int *INT_Yout, int **INT_Array_RootMap, bool **BOOL_CheckRouteDirection) {


    if (BOOL_CheckRouteDirection[INT_Integer][0]) {

        BOOL_CheckRouteDirection[INT_Integer][0] = false;

        *INT_Xout = INT_X;
        *INT_Yout = INT_Y - 2;

        if (INT_Array_RootMap[INT_X][INT_Y - 1] == 0) {
            BOOL_CheckRouteDirection[INT_Integer + 1][2] = false;
        }

        return INT_Array_RootMap[INT_X][INT_Y - 1];

    } else if (BOOL_CheckRouteDirection[INT_Integer][1]) {

        BOOL_CheckRouteDirection[INT_Integer][1] = false;

        *INT_Xout = INT_X + 2;
        *INT_Yout = INT_Y;

        if (INT_Array_RootMap[INT_X + 1][INT_Y] == 0) {
            BOOL_CheckRouteDirection[INT_Integer + 1][3] = false;
        }

        return INT_Array_RootMap[INT_X + 1][INT_Y];

    } else if (BOOL_CheckRouteDirection[INT_Integer][2]) {

        BOOL_CheckRouteDirection[INT_Integer][2] = false;

        *INT_Xout = INT_X;
        *INT_Yout = INT_Y + 2;

        if (INT_Array_RootMap[INT_X][INT_Y + 1] == 0) {
            BOOL_CheckRouteDirection[INT_Integer + 1][0] = false;
        }

        return INT_Array_RootMap[INT_X][INT_Y + 1];


    } else if (BOOL_CheckRouteDirection[INT_Integer][3]) {

        BOOL_CheckRouteDirection[INT_Integer][3] = false;

        *INT_Xout = INT_X - 2;
        *INT_Yout = INT_Y;

        if (INT_Array_RootMap[INT_X - 1][INT_Y] == 0) {
            BOOL_CheckRouteDirection[INT_Integer + 1][1] = false;
        }

        return INT_Array_RootMap[INT_X - 1][INT_Y];

    } else {
        std::cout << "Integer = " << INT_Integer << " -> {" << BOOL_CheckRouteDirection[INT_Integer][0] << ","
                  << BOOL_CheckRouteDirection[INT_Integer][1] << "," << BOOL_CheckRouteDirection[INT_Integer][2] << ","
                  << BOOL_CheckRouteDirection[INT_Integer][3] << "}" << std::endl;
        return 99;
    }
}
//-return Weight

//------------------------------

void VOID_NumberToTypeXY(int INT_Input, int *Type, int *INT_X, int *INT_Y) {

    *Type=(INT_Input%100);

    *INT_Y=2*((INT_Input%10000)/100)+1; //wall-root-wall = 14 * 2 + 1

    *INT_X=2*(INT_Input/10000)+1;//wall-root-wall = 14 * 2 + 1
}

void VOID_Center_Location(int Center_INDEX, int *INT_X, int *INT_Y) {
    switch (Center_INDEX)
    {
        case 0:
            *INT_X=11;
            *INT_Y=7;
            break;
        case 1:
            *INT_X=13;
            *INT_Y=7;
            break;
        case 2:
            *INT_X=15;
            *INT_Y=7;
            break;
        case 3:
            *INT_X=17;
            *INT_Y=7;
            break;
        case 4:
            *INT_X=21;
            *INT_Y=11;
            break;
        case 5:
            *INT_X=21;
            *INT_Y=13;
            break;
        case 6:
            *INT_X=21;
            *INT_Y=15;
            break;
        case 7:
            *INT_X=21;
            *INT_Y=17;
            break;
        case 8:
            *INT_X=17;
            *INT_Y=21;
            break;
        case 9:
            *INT_X=15;
            *INT_Y=21;
            break;
        case 10:
            *INT_X=13;
            *INT_Y=21;
            break;
        case 11:
            *INT_X=11;
            *INT_Y=21;
            break;
        case 12:
            *INT_X=7;
            *INT_Y=17;
            break;
        case 13:
            *INT_X=7;
            *INT_Y=15;
            break;
        case 14:
            *INT_X=7;
            *INT_Y=13;
            break;
        case 15:
            *INT_X=7;
            *INT_Y=11;
            break;
        default:
            break;
    }
}

void VOID_Front_Back_XY_RootType(int ForE, int Type,int *INT_X, int *INT_Y) {
    int Buff_Num01;

    Buff_Num01=Type%10;

    if(Type>70)
    {
        switch(Buff_Num01)
        {
            case 1:
                *INT_Y=*INT_Y-2;
                break;
            case 2:
                *INT_X=*INT_X+2;
                break;
            case 3:
                *INT_Y=*INT_Y+2;
                break;
            case 4:
                *INT_X=*INT_X-2;
                break;
            default:
                break;
        }
    }
    else
    {
        switch(Buff_Num01)
        {
            case 1:
                if(ForE==0)
                {
                    *INT_Y=*INT_Y-2;
                }
                else
                {
                    *INT_Y=*INT_Y+2;
                }
                break;
            case 2:
                if(ForE==0)
                {
                    *INT_X=*INT_X-2;
                }
                else
                {
                    *INT_X=*INT_X+2;
                }
                break;
            case 3:
                if(ForE==0)
                {
                    *INT_Y=*INT_Y-2;
                }
                else
                {
                    *INT_X=*INT_X+2;
                }
                break;
            case 4:
                if(ForE==0)
                {
                    *INT_X=*INT_X+2;
                }
                else
                {
                    *INT_Y=*INT_Y+2;
                }
                break;
            case 5:
                if(ForE==0)
                {
                    *INT_X=*INT_X-2;
                }
                else
                {
                    *INT_Y=*INT_Y+2;
                }
                break;
            case 6:
                if(ForE==0)
                {
                    *INT_Y=*INT_Y-2;
                }
                else
                {
                    *INT_X=*INT_X-2;
                }
                break;
            default:
                break;
        }
    }


}



int INT_FindPossiblePathPointToPoint(int INT_Start_X, int INT_Start_Y, int INT_Dest_X, int INT_Dest_Y, int INT_MaxDistance, int INT_MinDistance, int **INT_Array_RootMap) {

    int INT_CurrentX, INT_CurrentY;
    int INT_Xout, INT_Yout;

    bool **BOOL_CheckRouteDirection = new bool *[INT_MaxDistance];
    for (int i0 = 0; i0 < INT_MaxDistance; i0++) {
        BOOL_CheckRouteDirection[i0] = new bool[4];
    }

    //------------------------------
    //Initialize
    for (int i1 = 0; i1 < INT_MaxDistance; i1++) {
        for (int i2 = 0; i2 < 4; i2++) {
            BOOL_CheckRouteDirection[i1][i2] = true;
        }
    }
    INT_CurrentX = INT_Start_X;
    INT_CurrentY = INT_Start_Y;

    //------------------------------

    while (true) {

        if (INT_CurrentX == INT_Dest_X && INT_CurrentY == INT_Dest_Y) {
            break;
        }
    }


    for (int i0 = 0; i0 < INT_MaxDistance; i0++) {
        delete[] BOOL_CheckRouteDirection[i0];
    }
    delete[] BOOL_CheckRouteDirection;

    return 0;
}