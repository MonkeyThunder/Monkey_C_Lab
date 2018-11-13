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

void VOID_Print_Data(int **INT_Array_RootMap) {
    std::cout.fill('0');
    for(int i0=0;i0<15;i0++){
        for(int i1=0;i1<14;i1++){
            if(INT_Array_RootMap[2*i1+1][2*i0]!=99){
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
            if(INT_Array_RootMap[2*i1][2*i0+1]!=99){
                std::cout << " = ";
            }
            else{
                std::cout << " | ";
            }
            if(i1==14){
                break;
            }
            std::cout.width(2);
            std::cout<<INT_Array_RootMap[2*i1+1][2*i0+1];
        }
        std::cout<<std::endl;
        if(i0==13){
            //break;
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

int INT_OneStepRoute(int INT_Integer, int INT_X, int INT_Y, int *INT_Xout, int *INT_Yout, int **INT_Array_RootMap, bool **BOOL_CheckRouteDirection, bool BOOL_Log) {

    *INT_Xout = INT_X;
    *INT_Yout = INT_Y;

    if (BOOL_CheckRouteDirection[INT_Integer][0]) {

        BOOL_CheckRouteDirection[INT_Integer][0] = false;

        if(INT_Array_RootMap[INT_X][INT_Y - 1]==0){
            *INT_Xout = INT_X;
            *INT_Yout = INT_Y - 2;
        }

        if (INT_Array_RootMap[INT_X][INT_Y - 1] == 0) {
            BOOL_CheckRouteDirection[INT_Integer + 1][2] = false;
        }

        if(BOOL_Log){
            std::cout<<"Integer = "<<INT_Integer<<" - Direction = 0 - up"<<std::endl;
        }

        return INT_Array_RootMap[INT_X][INT_Y - 1];

    } else if (BOOL_CheckRouteDirection[INT_Integer][1]) {

        BOOL_CheckRouteDirection[INT_Integer][1] = false;

        if(INT_Array_RootMap[INT_X + 1][INT_Y]==0){
            *INT_Xout = INT_X + 2;
            *INT_Yout = INT_Y;
        }


        if (INT_Array_RootMap[INT_X + 1][INT_Y] == 0) {
            BOOL_CheckRouteDirection[INT_Integer + 1][3] = false;
        }

        if(BOOL_Log){
            std::cout<<"Integer = "<<INT_Integer<<" - Direction = 1 right"<<std::endl;
        }

        return INT_Array_RootMap[INT_X + 1][INT_Y];

    } else if (BOOL_CheckRouteDirection[INT_Integer][2]) {

        BOOL_CheckRouteDirection[INT_Integer][2] = false;

        if(INT_Array_RootMap[INT_X][INT_Y + 1]==0){
            *INT_Xout = INT_X;
            *INT_Yout = INT_Y + 2;
        }


        if (INT_Array_RootMap[INT_X][INT_Y + 1] == 0) {
            BOOL_CheckRouteDirection[INT_Integer + 1][0] = false;
        }

        if(BOOL_Log){
            std::cout<<"Integer = "<<INT_Integer<<" - Direction = 2 down"<<std::endl;
        }

        return INT_Array_RootMap[INT_X][INT_Y + 1];


    } else if (BOOL_CheckRouteDirection[INT_Integer][3]) {

        BOOL_CheckRouteDirection[INT_Integer][3] = false;

        if(INT_Array_RootMap[INT_X - 1][INT_Y]==0){
            *INT_Xout = INT_X - 2;
            *INT_Yout = INT_Y;
        }

        if (INT_Array_RootMap[INT_X - 1][INT_Y] == 0) {
            BOOL_CheckRouteDirection[INT_Integer + 1][1] = false;
        }

        if(BOOL_Log){
            std::cout<<"Integer = "<<INT_Integer<<" - Direction = 3 left"<<std::endl;
        }

        return INT_Array_RootMap[INT_X - 1][INT_Y];

    } else {
        std::cout << "Integer = " << INT_Integer << " -> {" << BOOL_CheckRouteDirection[INT_Integer][0] << ","
                  << BOOL_CheckRouteDirection[INT_Integer][1] << "," << BOOL_CheckRouteDirection[INT_Integer][2] << ","
                  << BOOL_CheckRouteDirection[INT_Integer][3] << "}" << std::endl;
        return 666;
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

//------------------------------

int INT_NumberOfPossibleRoute(int INT_MaxDistance){
    int INT_Return = 1;
    for(int i0=0;i0<INT_MaxDistance;i0++){
        INT_Return=INT_Return*3;
    }
    return INT_Return;
}

int INT_FindPossiblePathPointToPoint(int INT_Start_X, int INT_Start_Y, int INT_Dest_X, int INT_Dest_Y, int INT_MaxDistance, int INT_MinDistance, int ***INT_ArrayResultOut, int **INT_Array_RootMap) {

    int INT_CurrentX, INT_CurrentY, INT_CurrentDistance;
    int INT_Xout, INT_Yout;
    int INT_Weight;
    int INT_NumberOfPossibleRoute;
    int INT_Buff00 = 0;

    bool **BOOL_CheckRouteDirection = new bool *[INT_MaxDistance+1];
    for (int i0 = 0; i0 < INT_MaxDistance+1; i0++) {
        BOOL_CheckRouteDirection[i0] = new bool[4];
    }

    //------------------------------
    //Initialize
    for (int i1 = 0; i1 < INT_MaxDistance+1; i1++) {
        for (int i2 = 0; i2 < 4; i2++) {
            BOOL_CheckRouteDirection[i1][i2] = true;
        }
    }
    INT_CurrentX = INT_Start_X;
    INT_CurrentY = INT_Start_Y;

    INT_CurrentDistance = 0;
    INT_NumberOfPossibleRoute=0;

    //------------------------------

    std::cout<<"Start = {"<<INT_Start_X/2<<","<<INT_Start_Y/2<<"}, Dest = {"<<INT_Dest_X/2<<","<<INT_Dest_Y/2<<"}"<<std::endl;
    while (true) {

        INT_ArrayResultOut[INT_NumberOfPossibleRoute][INT_CurrentDistance][0]=INT_CurrentX;
        INT_ArrayResultOut[INT_NumberOfPossibleRoute][INT_CurrentDistance][1]=INT_CurrentY;

        //Current X,Y Record

        for(int i0=0;i0<INT_NumberOfPossibleRoute+1;i0++){
            std::cout<<"#Possible Route = "<<i0<<", ";
            for(int i1=0;i1<INT_MaxDistance;i1++){
                std::cout<<i1<<"->{"<<INT_ArrayResultOut[i0][i1][0]/2<<","<<INT_ArrayResultOut[i0][i1][1]/2<<"} ";
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;

        //Console out of Record


        if ((INT_CurrentX == INT_Dest_X && INT_CurrentY == INT_Dest_Y)&&INT_CurrentDistance>=INT_MinDistance) {

            //Current = Destination && Over the min distance


            for(int i0=0;i0<INT_CurrentDistance;i0++){

                INT_ArrayResultOut[INT_NumberOfPossibleRoute+1][i0][0]=INT_ArrayResultOut[INT_NumberOfPossibleRoute][i0][0];
                INT_ArrayResultOut[INT_NumberOfPossibleRoute+1][i0][1]=INT_ArrayResultOut[INT_NumberOfPossibleRoute][i0][1];
            }
            //Copy

            std::cout<<"Attached!!"<<std::endl;
            std::cout<<"------------------------------"<<std::endl;
            std::cout<<"PossibleRoute = "<<INT_NumberOfPossibleRoute<<", Current = "<<INT_CurrentDistance<<", Current+Rest/Max = "<<INT_Distance(INT_CurrentX,INT_CurrentY,INT_Dest_X,INT_Dest_Y)+INT_CurrentDistance<<"/"<<INT_MaxDistance<<", INT_Weight = "<<INT_Weight<<std::endl;
            std::cout<<"Current {X,Y} = {"<<INT_CurrentX/2<<","<<INT_CurrentY/2<<"}, Rest Distance = "<<INT_Distance(INT_CurrentX,INT_CurrentY,INT_Dest_X,INT_Dest_Y)<<std::endl;
            std::cout<<"------------------------------"<<std::endl;
            std::cout<<std::endl;

            INT_CurrentX=INT_ArrayResultOut[INT_NumberOfPossibleRoute][INT_CurrentDistance-1][0];
            INT_CurrentY=INT_ArrayResultOut[INT_NumberOfPossibleRoute][INT_CurrentDistance-1][1];
            //Back to one step before

            std::cout<<"Current {X,Y} = {"<<INT_CurrentX/2<<","<<INT_CurrentY/2<<"}"<<std::endl;

            BOOL_CheckRouteDirection[INT_CurrentDistance-1][0] = false;
            BOOL_CheckRouteDirection[INT_CurrentDistance-1][1] = false;
            BOOL_CheckRouteDirection[INT_CurrentDistance-1][2] = false;
            BOOL_CheckRouteDirection[INT_CurrentDistance-1][3] = false;

            //Set boundary condition for find other route

            INT_NumberOfPossibleRoute++;
            INT_CurrentDistance--;
            // Add Number of possible route, one step back for cal other route

        }

        //------------------------------

        if(!BOOL_CheckRouteDirection[0][0]&&!BOOL_CheckRouteDirection[0][1]&&!BOOL_CheckRouteDirection[0][2]&&!BOOL_CheckRouteDirection[0][3]){
            //No more way to find route case
            break;
        }

        //------------------------------



        INT_Weight = INT_OneStepRoute(INT_CurrentDistance,INT_CurrentX,INT_CurrentY,&INT_Xout,&INT_Yout,INT_Array_RootMap,BOOL_CheckRouteDirection,true);
        //Found route function



        if(INT_Weight==666||(INT_Distance(INT_Xout,INT_Yout,INT_Dest_X,INT_Dest_Y)+INT_CurrentDistance>=INT_MaxDistance && (INT_Xout != INT_Dest_X && INT_Yout != INT_Dest_Y))){
            //Boundary all fail, Distance is over than max distance

            if(INT_CurrentDistance==0){
                std::cout<<"Wrong Starting Point"<<std::endl;
                return 0;
            }
            //Distance = zero case

            if(INT_Weight==666){
                INT_CurrentDistance--;
                for(int i0 = INT_CurrentDistance+1; i0<INT_MaxDistance;i0++){
                    INT_ArrayResultOut[INT_NumberOfPossibleRoute][i0][0]=0;
                    INT_ArrayResultOut[INT_NumberOfPossibleRoute][i0][1]=0;

                }
            }

            std::cout<<"Corner!!"<<std::endl;
            std::cout<<"------------------------------"<<std::endl;
            std::cout<<"PossibleRoute = "<<INT_NumberOfPossibleRoute<<", Current = "<<INT_CurrentDistance<<", Current+Rest/Max = "<<INT_Distance(INT_Xout,INT_Yout,INT_Dest_X,INT_Dest_Y)+INT_CurrentDistance<<"/"<<INT_MaxDistance<<", INT_Weight = "<<INT_Weight<<std::endl;
            std::cout<<"Out {X,Y} = {"<<INT_Xout/2<<","<<INT_Yout/2<<"}, Rest Distance = "<<INT_Distance(INT_Xout,INT_Xout,INT_Dest_X,INT_Dest_Y)<<std::endl;
            std::cout<<"------------------------------"<<std::endl;

            INT_CurrentX=INT_ArrayResultOut[INT_NumberOfPossibleRoute][INT_CurrentDistance][0];
            INT_CurrentY=INT_ArrayResultOut[INT_NumberOfPossibleRoute][INT_CurrentDistance][1];

            std::cout<<"Current {X,Y} = {"<<INT_CurrentX/2<<","<<INT_CurrentY/2<<"}, Boundary(up,right,down,left = {"<<INT_Array_RootMap[INT_CurrentX][INT_CurrentY-1]<<","<<INT_Array_RootMap[INT_CurrentX+1][INT_CurrentY]<<","<<INT_Array_RootMap[INT_CurrentX][INT_CurrentY+1]<<","<<INT_Array_RootMap[INT_CurrentX-1][INT_CurrentY]<<"}"<<std::endl;

            std::cout<<"After Set CurrentXY"<<std::endl;

            BOOL_CheckRouteDirection[INT_CurrentDistance+1][0]=true;
            BOOL_CheckRouteDirection[INT_CurrentDistance+1][1]=true;
            BOOL_CheckRouteDirection[INT_CurrentDistance+1][2]=true;
            BOOL_CheckRouteDirection[INT_CurrentDistance+1][3]=true;
            //Reset Boundary condition

        }
        else if(INT_Weight==0){
            INT_CurrentDistance++;

            INT_CurrentX=INT_Xout;
            INT_CurrentY=INT_Yout;

        }
        std::cout<<"PossibleRoute = "<<INT_NumberOfPossibleRoute<<", Current = "<<INT_CurrentDistance<<", Current+Rest/Max = "<<INT_Distance(INT_Xout,INT_Yout,INT_Dest_X,INT_Dest_Y)+INT_CurrentDistance<<"/"<<INT_MaxDistance<<", INT_Weight = "<<INT_Weight<<std::endl;


        std::cout<<"Current {X,Y} = {"<<INT_CurrentX/2<<","<<INT_CurrentY/2<<"}, Boundary(up,right,down,left = {"<<INT_Array_RootMap[INT_CurrentX][INT_CurrentY-1]<<","<<INT_Array_RootMap[INT_CurrentX+1][INT_CurrentY]<<","<<INT_Array_RootMap[INT_CurrentX][INT_CurrentY+1]<<","<<INT_Array_RootMap[INT_CurrentX-1][INT_CurrentY]<<"}"<<std::endl;

        std::cout<<std::endl;

        if(INT_Buff00>500){

            std::cout<<"Emergency Breaking"<<std::endl;
            break;
        }

        INT_Buff00++;

    }


    for (int i0 = 0; i0 < INT_MaxDistance+1; i0++) {
        delete[] BOOL_CheckRouteDirection[i0];
    }
    delete[] BOOL_CheckRouteDirection;

    return INT_NumberOfPossibleRoute;
}

bool BOOL_FindIsolatedCellRecursive(int INT_X, int INT_Y, int INT_ComingDirection, int **INT_Array_RootMap){

    int INT_Next_X, INT_Next_Y;
    int INT_Counter = 0;
    if(11<INT_X&&INT_X<17&&11<INT_Y&&INT_Y<17){
        std::cout<<"Not Isolated!!"<<std::endl;
        INT_Array_RootMap[28][28]=99999;
        return false;
    }
    if(INT_Array_RootMap[28][28]>=99999){
        return false;
    }

    if((INT_Array_RootMap[INT_X][INT_Y-1]==99||INT_ComingDirection==0)&&
            (INT_Array_RootMap[INT_X+1][INT_Y]==99||INT_ComingDirection==1)&&
                    (INT_Array_RootMap[INT_X][INT_Y+1]==99||INT_ComingDirection==2)&&
                            (INT_Array_RootMap[INT_X-1][INT_Y]==99||INT_ComingDirection==3)){
        //Isolated
        std::cout<<"Isolated!! (X,Y) = ("<<INT_X/2<<","<<INT_Y/2<<")"<<std::endl;
        return true;
    }

    std::cout<<"(X,Y) = ("<<INT_X/2<<","<<INT_Y/2<<"), "<<INT_Counter<<", "<<INT_Array_RootMap[27][27]<<std::endl;

    if(INT_X<14&&INT_Y<14){

        //Right
        if(INT_Array_RootMap[INT_X+1][INT_Y]!=99&&INT_ComingDirection!=3){
            INT_Next_X=INT_X+2;
            INT_Next_Y=INT_Y;
            if(!BOOL_FindIsolatedCellRecursive(INT_Next_X,INT_Next_Y,1,INT_Array_RootMap)){
                INT_Counter++;
            }
        }

        //Down
        if(INT_Array_RootMap[INT_X][INT_Y+1]!=99&&INT_ComingDirection!=0){
            INT_Next_X=INT_X;
            INT_Next_Y=INT_Y+2;
            if(!BOOL_FindIsolatedCellRecursive(INT_Next_X,INT_Next_Y,2,INT_Array_RootMap)){
                INT_Counter++;
            }
        }

        //Up
        if(INT_Array_RootMap[INT_X][INT_Y-1]!=99&&INT_ComingDirection!=2){
            INT_Next_X=INT_X;
            INT_Next_Y=INT_Y-2;
            if(!BOOL_FindIsolatedCellRecursive(INT_Next_X,INT_Next_Y,0,INT_Array_RootMap)){
                INT_Counter++;
            }
        }

        //Left
        if(INT_Array_RootMap[INT_X-1][INT_Y]!=99&&INT_ComingDirection!=1){
            INT_Next_X=INT_X-2;
            INT_Next_Y=INT_Y;
            if(!BOOL_FindIsolatedCellRecursive(INT_Next_X,INT_Next_Y,3,INT_Array_RootMap)){
                INT_Counter++;
            }
        }
    }


    if(INT_X>14&&INT_Y<14){

        //Left
        if(INT_Array_RootMap[INT_X-1][INT_Y]!=99&&INT_ComingDirection!=1){
            INT_Next_X=INT_X-2;
            INT_Next_Y=INT_Y;
            if(!BOOL_FindIsolatedCellRecursive(INT_Next_X,INT_Next_Y,3,INT_Array_RootMap)){
                INT_Counter++;
            }
        }

        //Down
        if(INT_Array_RootMap[INT_X][INT_Y+1]!=99&&INT_ComingDirection!=0){
            INT_Next_X=INT_X;
            INT_Next_Y=INT_Y+2;
            if(!BOOL_FindIsolatedCellRecursive(INT_Next_X,INT_Next_Y,2,INT_Array_RootMap)){
                INT_Counter++;
            }
        }

        //Up
        if(INT_Array_RootMap[INT_X][INT_Y-1]!=99&&INT_ComingDirection!=2){
            INT_Next_X=INT_X;
            INT_Next_Y=INT_Y-2;
            if(!BOOL_FindIsolatedCellRecursive(INT_Next_X,INT_Next_Y,0,INT_Array_RootMap)){
                INT_Counter++;
            }
        }

        //Right
        if(INT_Array_RootMap[INT_X+1][INT_Y]!=99&&INT_ComingDirection!=3){
            INT_Next_X=INT_X+2;
            INT_Next_Y=INT_Y;
            if(!BOOL_FindIsolatedCellRecursive(INT_Next_X,INT_Next_Y,1,INT_Array_RootMap)){
                INT_Counter++;
            }
        }
    }


    if(INT_X>14&&INT_Y>14){

        //Left
        if(INT_Array_RootMap[INT_X-1][INT_Y]!=99&&INT_ComingDirection!=1){
            INT_Next_X=INT_X-2;
            INT_Next_Y=INT_Y;
            if(!BOOL_FindIsolatedCellRecursive(INT_Next_X,INT_Next_Y,3,INT_Array_RootMap)){
                INT_Counter++;
            }
        }

        //Up
        if(INT_Array_RootMap[INT_X][INT_Y-1]!=99&&INT_ComingDirection!=2){
            INT_Next_X=INT_X;
            INT_Next_Y=INT_Y-2;
            if(!BOOL_FindIsolatedCellRecursive(INT_Next_X,INT_Next_Y,0,INT_Array_RootMap)){
                INT_Counter++;
            }
        }

        //Right
        if(INT_Array_RootMap[INT_X+1][INT_Y]!=99&&INT_ComingDirection!=3){
            INT_Next_X=INT_X+2;
            INT_Next_Y=INT_Y;
            if(!BOOL_FindIsolatedCellRecursive(INT_Next_X,INT_Next_Y,1,INT_Array_RootMap)){
                INT_Counter++;
            }
        }

        //Down
        if(INT_Array_RootMap[INT_X][INT_Y+1]!=99&&INT_ComingDirection!=0){
            INT_Next_X=INT_X;
            INT_Next_Y=INT_Y+2;
            if(!BOOL_FindIsolatedCellRecursive(INT_Next_X,INT_Next_Y,2,INT_Array_RootMap)){
                INT_Counter++;
            }
        }




    }
    if(INT_X<14&&INT_Y>14){
        //Right
        if(INT_Array_RootMap[INT_X+1][INT_Y]!=99&&INT_ComingDirection!=3){
            INT_Next_X=INT_X+2;
            INT_Next_Y=INT_Y;
            if(!BOOL_FindIsolatedCellRecursive(INT_Next_X,INT_Next_Y,1,INT_Array_RootMap)){
                INT_Counter++;
            }
        }

        //Up
        if(INT_Array_RootMap[INT_X][INT_Y-1]!=99&&INT_ComingDirection!=2){
            INT_Next_X=INT_X;
            INT_Next_Y=INT_Y-2;
            if(!BOOL_FindIsolatedCellRecursive(INT_Next_X,INT_Next_Y,0,INT_Array_RootMap)){
                INT_Counter++;
            }
        }

        //Down
        if(INT_Array_RootMap[INT_X][INT_Y+1]!=99&&INT_ComingDirection!=0){
            INT_Next_X=INT_X;
            INT_Next_Y=INT_Y+2;
            if(!BOOL_FindIsolatedCellRecursive(INT_Next_X,INT_Next_Y,2,INT_Array_RootMap)){
                INT_Counter++;
            }
        }

        //Left
        if(INT_Array_RootMap[INT_X-1][INT_Y]!=99&&INT_ComingDirection!=1){
            INT_Next_X=INT_X-2;
            INT_Next_Y=INT_Y;
            if(!BOOL_FindIsolatedCellRecursive(INT_Next_X,INT_Next_Y,3,INT_Array_RootMap)){
                INT_Counter++;
            }
        }
    }

    //Direction 0 - Up, 1 - Right, 2 - Down, 3 - Left


    if(INT_Counter==0){
        return true;
    }else{
        return false;
    }
}
void VOID_FindIsolatedCell(int INT_StartX, int INT_StartY, int **INT_Array_RootMap){

    int** INT_Array_RootMap_Buff = new int*[29]; //wall-root-wall = 14 * 2 + 1
    for(int i0=0;i0<29;i0++){
        INT_Array_RootMap_Buff[i0] = new int[29];
    }

    for(int i0=0;i0<29;i0++){
        for(int i1=0;i1<29;i1++){
            INT_Array_RootMap_Buff[i0][i1]=INT_Array_RootMap[i0][i1];
        }
    }





    for(int i0=0;i0<29;i0++){
        delete[] INT_Array_RootMap_Buff[i0];
    }
    delete[] INT_Array_RootMap_Buff;
}

void VOID_IsolatedUnkownCells(int **INT_ArrayResultOut, int INT_MapSize, int **INT_Array_RootMap){

    int INT_StartX, INT_StartY;
    int INT_EndX, INT_EndY;
    int INT_DirectionX, INT_DirectionY;

    int INT_CurrentX, INT_CurrentY;

    if(INT_MapSize==12){
        INT_StartX=3;
        INT_StartY=3;
        INT_EndX=25;
        INT_EndY=25;
    }
    else{
        INT_StartX=1;
        INT_StartY=1;
        INT_EndX=27;
        INT_EndY=27;
    }

    for(int i0=INT_StartX;i0<INT_EndX+1;i0=i0+2){
        for(int i1=INT_StartY;i1<INT_EndY+1;i1=i1+2){

            if(INT_Array_RootMap[i0][i1]==99){

                VOID_FindIsolatedCell(i0,i1,INT_Array_RootMap);

            }

        }
    }
}

