//
// Created by DongHoon Kim on 08/10/2018.
//

#include <iostream>
#include <string>
#include <vector>

int INT_Distance(int INT_Start_X, int INT_Start_Y, int INT_Dest_X, int INT_Dest_Y) {
    return abs(INT_Start_X-INT_Dest_X)/2+abs(INT_Start_Y-INT_Dest_Y)/2;
}

void VOID_Front_Back_XY_RootType(int ForE, int Type,int *INT_X, int *INT_Y) {
    int Buff_Num01;

    Buff_Num01=Type%10;

    if(Type>70)
    {
        switch(Buff_Num01)
        {
            case 3:
                *INT_Y=*INT_Y-2;
                break;
            case 4:
                *INT_X=*INT_X+2;
                break;
            case 5:
                *INT_Y=*INT_Y+2;
                break;
            case 6:
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
            case 3:
                if(ForE==0)
                {
                    *INT_Y=*INT_Y-2;
                }
                else
                {
                    *INT_Y=*INT_Y+2;
                }
                break;
            case 4:
                if(ForE==0)
                {
                    *INT_X=*INT_X-2;
                }
                else
                {
                    *INT_X=*INT_X+2;
                }
                break;
            case 5:
                if(ForE==0)
                {
                    *INT_Y=*INT_Y-2;
                }
                else
                {
                    *INT_X=*INT_X+2;
                }
                break;
            case 6:
                if(ForE==0)
                {
                    *INT_X=*INT_X+2;
                }
                else
                {
                    *INT_Y=*INT_Y+2;
                }
                break;
            case 7:
                if(ForE==0)
                {
                    *INT_X=*INT_X-2;
                }
                else
                {
                    *INT_Y=*INT_Y+2;
                }
                break;
            case 8:
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

std::string AStarAlgorithm(int INT_MinDistance, int INT_MaxDistance, int INT_StartX, int INT_StartY, int INT_DestX, int INT_DestY, std::vector<int> Root_Map) {

    int INT_SizeOfMap = Root_Map.size();
    int INT_SizeOfMap_withWall;
    if (INT_SizeOfMap == 841) {
        INT_SizeOfMap = 14;
        INT_SizeOfMap_withWall = 29;
    } else if (INT_SizeOfMap == 625) {
        INT_SizeOfMap = 12;
        INT_SizeOfMap_withWall = 25;
    } else {
        std::cout << "Wrong RootMap Data is inserted" << std::endl;
        return 0;
    }

    //------------------------------

    int INT_Buff00, INT_Buff01, INT_Buff02, INT_Buff03, INT_Buff04;
    int INT_CurrentX, INT_CurrentY;
    int INT_CurrentDistance;

    std::string STR_Out;
    std::string STR_Buff;

    //------------------------------
    //Array for Copying RootMap, Open and Closed Node for A*,
    int **INT_Array_BuffRootMap = new int *[INT_SizeOfMap_withWall];
    int ***INT_Array_OpenNode = new int **[INT_SizeOfMap_withWall];
    int ***INT_Array_ClosedNode = new int **[INT_SizeOfMap_withWall];

    for (int i0 = 0; i0 < INT_SizeOfMap_withWall; i0++) {
        INT_Array_BuffRootMap[i0] = new int[INT_SizeOfMap_withWall];
        INT_Array_OpenNode[i0] = new int *[INT_SizeOfMap_withWall];
        INT_Array_ClosedNode[i0] = new int *[INT_SizeOfMap_withWall];

        for (int i1 = 0; i1 < INT_SizeOfMap_withWall; i1++) {
            INT_Array_OpenNode[i0][i1] = new int[5];
            INT_Array_ClosedNode[i0][i1] = new int[5];

        }
    }

    //Copy - Initialize
    INT_Buff02 = 0;


    for (int i0 = 0; i0 < INT_SizeOfMap_withWall; i0++) {
        for (int i1 = 0; i1 < INT_SizeOfMap_withWall; i1++) {
            INT_Array_BuffRootMap[i0][i1] = Root_Map[i0 * INT_SizeOfMap_withWall + i1];
        }
    }

    for (int i0 = 0; i0 < INT_SizeOfMap_withWall; i0++) {
        for (int i1 = 0; i1 < INT_SizeOfMap_withWall; i1++) {
            for (int i2 = 0; i2 < 5; i2++) {
                INT_Array_OpenNode[i0][i1][i2] = 9999;
                INT_Array_ClosedNode[i0][i1][i2] = 9999;
            }
        }
    }

    //------------------------------
    //Setting Starting Point on Open, Closed Node
    INT_CurrentX = INT_StartX;
    INT_CurrentY = INT_StartY;

    INT_Array_OpenNode[INT_StartX][INT_StartY][0] = 0;
    INT_Array_OpenNode[INT_StartX][INT_StartY][1] = INT_Distance(INT_StartX, INT_StartY, INT_DestX, INT_DestY);
    INT_Array_OpenNode[INT_StartX][INT_StartY][2] =
            INT_Array_OpenNode[INT_StartX][INT_StartY][0] + INT_Array_OpenNode[INT_StartX][INT_StartY][1];
    INT_Array_OpenNode[INT_StartX][INT_StartY][3] = INT_CurrentX;
    INT_Array_OpenNode[INT_StartX][INT_StartY][4] = INT_CurrentY;

    for (int i0 = 0; i0 < 5; i0++) {
        INT_Array_ClosedNode[INT_StartX][INT_StartY][i0] = INT_Array_OpenNode[INT_StartX][INT_StartY][i0];
    }

    INT_Buff00 = INT_Array_ClosedNode[INT_StartX][INT_StartY][0];
    INT_Buff03 = INT_CurrentX;
    INT_Buff04 = INT_CurrentY;
    //------------------------------

    while (true) {

        if (INT_Buff02 > 1000) {
            std::cout << "OverFlow" << std::endl;
            break;
        }

        if (INT_CurrentX == INT_DestX && INT_CurrentY == INT_DestY && INT_CurrentDistance >= INT_MinDistance) {
            break;
        }

        //------------------------------

        if (INT_CurrentX > 2) {
            INT_Buff01 = INT_Distance(INT_CurrentX - 2, INT_CurrentY, INT_DestX, INT_DestY);
            INT_Array_OpenNode[INT_CurrentX - 2][INT_CurrentY][0] =
                    INT_Buff00 + INT_Array_BuffRootMap[INT_CurrentX - 1][INT_CurrentY];
            INT_Array_OpenNode[INT_CurrentX - 2][INT_CurrentY][1] = INT_Buff01;
            INT_Array_OpenNode[INT_CurrentX - 2][INT_CurrentY][2] =
                    INT_Array_OpenNode[INT_CurrentX - 2][INT_CurrentY][0] +
                    INT_Array_OpenNode[INT_CurrentX - 2][INT_CurrentY][1];
            INT_Array_OpenNode[INT_CurrentX - 2][INT_CurrentY][3] = INT_Buff03;
            INT_Array_OpenNode[INT_CurrentX - 2][INT_CurrentY][4] = INT_Buff04;

        }
        if (INT_CurrentX < (INT_SizeOfMap_withWall - 2)) {
            INT_Buff01 = INT_Distance(INT_CurrentX + 2, INT_CurrentY, INT_DestX, INT_DestY);
            INT_Array_OpenNode[INT_CurrentX + 2][INT_CurrentY][0] =
                    INT_Buff00 + INT_Array_BuffRootMap[INT_CurrentX + 1][INT_CurrentY];
            INT_Array_OpenNode[INT_CurrentX + 2][INT_CurrentY][1] = INT_Buff01;
            INT_Array_OpenNode[INT_CurrentX + 2][INT_CurrentY][2] =
                    INT_Array_OpenNode[INT_CurrentX + 2][INT_CurrentY][0] +
                    INT_Array_OpenNode[INT_CurrentX + 2][INT_CurrentY][1];
            INT_Array_OpenNode[INT_CurrentX + 2][INT_CurrentY][3] = INT_Buff03;
            INT_Array_OpenNode[INT_CurrentX + 2][INT_CurrentY][4] = INT_Buff04;

        }

        if (INT_CurrentY > 2) {
            INT_Buff01 = INT_Distance(INT_CurrentX, INT_CurrentY - 2, INT_DestX, INT_DestY);
            INT_Array_OpenNode[INT_CurrentX][INT_CurrentY - 2][0] =
                    INT_Buff00 + INT_Array_BuffRootMap[INT_CurrentX][INT_CurrentY - 1];
            INT_Array_OpenNode[INT_CurrentX][INT_CurrentY - 2][1] = INT_Buff01;
            INT_Array_OpenNode[INT_CurrentX][INT_CurrentY - 2][2] =
                    INT_Array_OpenNode[INT_CurrentX][INT_CurrentY - 2][0] +
                    INT_Array_OpenNode[INT_CurrentX][INT_CurrentY - 2][1];
            INT_Array_OpenNode[INT_CurrentX][INT_CurrentY - 2][3] = INT_Buff03;
            INT_Array_OpenNode[INT_CurrentX][INT_CurrentY - 2][4] = INT_Buff04;

        }
        if (INT_CurrentY < (INT_SizeOfMap_withWall - 2)) {
            INT_Buff01 = INT_Distance(INT_CurrentX + 2, INT_CurrentY, INT_DestX, INT_DestY);
            INT_Array_OpenNode[INT_CurrentX][INT_CurrentY + 2][0] =
                    INT_Buff00 + INT_Array_BuffRootMap[INT_CurrentX][INT_CurrentY + 1];
            INT_Array_OpenNode[INT_CurrentX][INT_CurrentY + 2][1] = INT_Buff01;
            INT_Array_OpenNode[INT_CurrentX][INT_CurrentY + 2][2] =
                    INT_Array_OpenNode[INT_CurrentX][INT_CurrentY + 2][0] +
                    INT_Array_OpenNode[INT_CurrentX][INT_CurrentY + 2][1];
            INT_Array_OpenNode[INT_CurrentX][INT_CurrentY + 2][3] = INT_Buff03;
            INT_Array_OpenNode[INT_CurrentX][INT_CurrentY + 2][4] = INT_Buff04;

        }

        INT_Buff01 = 99999999;

        //Minimum Weight
        for (int i0 = 0; i0 < INT_SizeOfMap; i0++) {
            for (int i1 = 0; i1 < INT_SizeOfMap; i1++) {
                if (INT_Array_OpenNode[2 * i0 + 1][2 * i1 + 1][2] < INT_Buff01) {
                    INT_Buff01 = INT_Array_OpenNode[2 * i0 + 1][2 * i1 + 1][2];
                    INT_Buff03 = 2 * i0 + 1;
                    INT_Buff04 = 2 * i1 + 1;
                }
            }
        }

        // Copy Selected Path from OpenNode to ClosedNode and initialize OpenNode
        for (int i0 = 0; i0 < 5; i0++) {
            INT_Array_ClosedNode[INT_Buff03][INT_Buff04][i0] = INT_Array_OpenNode[INT_Buff03][INT_Buff04][i0];
            INT_Array_OpenNode[INT_Buff03][INT_Buff04][i0] = 1000;
        }

        // Blocking Path which is already passed
        if (abs(INT_CurrentX - INT_Buff03) >= 1 || abs(INT_CurrentY - INT_Buff04) >= 1) {
            INT_CurrentX = INT_Array_ClosedNode[INT_Buff03][INT_Buff04][3];
            INT_CurrentY = INT_Array_ClosedNode[INT_Buff03][INT_Buff04][4];
        }
        if (INT_CurrentX == INT_Buff03) {
            if (INT_CurrentY > INT_Buff04) {
                INT_Array_BuffRootMap[INT_CurrentX][INT_CurrentY - abs(INT_CurrentY - INT_Buff04) / 2] = 90;
            } else {
                INT_Array_BuffRootMap[INT_CurrentX][INT_CurrentY + abs(INT_CurrentY - INT_Buff04) / 2] = 80;
            }
        }
        if (INT_CurrentY == INT_Buff04) {
            if (INT_CurrentX > INT_Buff03) {
                INT_Array_BuffRootMap[INT_CurrentX - abs(INT_CurrentX - INT_Buff03) / 2][INT_CurrentY] = 90;
            } else {
                INT_Array_BuffRootMap[INT_CurrentX + abs(INT_CurrentX - INT_Buff03) / 2][INT_CurrentY] = 90;
            }
        }


        //Pass data for next loop
        INT_Buff00 = INT_Array_ClosedNode[INT_Buff03][INT_Buff04][0];
        INT_CurrentX = INT_Buff03;
        INT_CurrentY = INT_Buff04;


        INT_Buff02++;

    }

    INT_Buff00 = 0;

    INT_Buff03 = INT_DestX;
    INT_Buff04 = INT_DestY;

    while (true) {

        INT_Buff00++;

        if (INT_Array_ClosedNode[INT_Buff03][INT_Buff04][3] < 10) {
            STR_Buff += "0";
        }
        STR_Buff += std::to_string(INT_Array_ClosedNode[INT_Buff03][INT_Buff04][3]);
        if (INT_Array_ClosedNode[INT_Buff03][INT_Buff04][4] < 10) {
            STR_Buff += "0";
        }
        STR_Buff += std::to_string(INT_Array_ClosedNode[INT_Buff03][INT_Buff04][4]);


        if (INT_Buff03 == INT_StartX && INT_Buff04 == INT_StartY) {
            break;
        }

    }

    STR_Out += std::to_string(INT_Buff00);

    for (int i0 = 0; i0 < INT_SizeOfMap_withWall; i0++) {
        for (int i1 = 0; i1 < 5; i1++) {
            delete[] INT_Array_OpenNode[i0][i1];
            delete[] INT_Array_ClosedNode[i0][i1];

        }
        delete[] INT_Array_OpenNode[i0];
        delete[] INT_Array_ClosedNode[i0];

        delete[] INT_Array_BuffRootMap[i0];
    }
    delete[] INT_Array_OpenNode;
    delete[] INT_Array_ClosedNode;

    delete[] INT_Array_BuffRootMap;

    return STR_Out + STR_Buff;
}