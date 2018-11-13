//
// Created by DongHoon Kim on 29/10/2018.
//

bool BOOL_VOID_FindIsolatedCellRecursive(int INT_X, int INT_Y, int INT_Direction, int **INT_Array_RootMap){

    std::cout<<"(X,Y) = ("<<INT_X/2<<","<<INT_Y/2<<")"<<std::endl;
    if(INT_Direction==-1){
        BOOL_VOID_FindIsolatedCellRecursive(1,1,0,INT_Array_RootMap);
        BOOL_VOID_FindIsolatedCellRecursive(1,1,1,INT_Array_RootMap);
        BOOL_VOID_FindIsolatedCellRecursive(1,1,2,INT_Array_RootMap);
        BOOL_VOID_FindIsolatedCellRecursive(1,1,3,INT_Array_RootMap);
    }
    //Direction 0 - Up, 1 - Right, 2 - Down, 3 - Left
    if(INT_Direction==0&&INT_Array_RootMap[INT_X][INT_Y-1]!=99){//UP
        INT_Array_RootMap[INT_X][INT_Y-1]=INT_Array_RootMap[INT_X][INT_Y+1];
        if(!BOOL_VOID_FindIsolatedCellRecursive(INT_X,INT_Y-2,0,INT_Array_RootMap)){
            return false;
        }
        if(!BOOL_VOID_FindIsolatedCellRecursive(INT_X,INT_Y-2,1,INT_Array_RootMap)){
            return false;
        }
        //if(!BOOL_VOID_FindIsolatedCellRecursive(INT_X,INT_Y-2,2,INT_Array_RootMap)){
        //    return false;
        //}
        if(!BOOL_VOID_FindIsolatedCellRecursive(INT_X,INT_Y-2,3,INT_Array_RootMap)){
            return false;
        }
    }

    if(INT_Direction==1&&INT_Array_RootMap[INT_X+1][INT_Y]!=99){//Right
        INT_Array_RootMap[INT_X+1][INT_Y]=INT_Array_RootMap[INT_X-1][INT_Y];
        if(!BOOL_VOID_FindIsolatedCellRecursive(INT_X+2,INT_Y,0,INT_Array_RootMap)){
            return false;
        }
        if(!BOOL_VOID_FindIsolatedCellRecursive(INT_X+2,INT_Y,1,INT_Array_RootMap)){
            return false;
        }
        if(!BOOL_VOID_FindIsolatedCellRecursive(INT_X+2,INT_Y,2,INT_Array_RootMap)){
            return false;
        }
        //if(!BOOL_VOID_FindIsolatedCellRecursive(INT_X+2,INT_Y,3,INT_Array_RootMap)){
        //    return false;
        //}
    }

    if(INT_Direction==2&&INT_Array_RootMap[INT_X][INT_Y+1]!=99){//Down
        INT_Array_RootMap[INT_X][INT_Y+1]=INT_Array_RootMap[INT_X][INT_Y-1];
        //if(!BOOL_VOID_FindIsolatedCellRecursive(INT_X,INT_Y+2,0,INT_Array_RootMap)){
        //    return false;
        //}
        if(!BOOL_VOID_FindIsolatedCellRecursive(INT_X,INT_Y+2,1,INT_Array_RootMap)){
            return false;
        }
        if(!BOOL_VOID_FindIsolatedCellRecursive(INT_X,INT_Y+2,2,INT_Array_RootMap)){
            return false;
        }
        if(!BOOL_VOID_FindIsolatedCellRecursive(INT_X,INT_Y+2,3,INT_Array_RootMap)){
            return false;
        }
    }

    if(INT_Direction==3&&INT_Array_RootMap[INT_X-1][INT_Y]!=99){//Left
        INT_Array_RootMap[INT_X-1][INT_Y]=INT_Array_RootMap[INT_X+1][INT_Y];
        if(!BOOL_VOID_FindIsolatedCellRecursive(INT_X-2,INT_Y,0,INT_Array_RootMap)){
            return false;
        }
        //if(!BOOL_VOID_FindIsolatedCellRecursive(INT_X-2,INT_Y,1,INT_Array_RootMap)){
        //    return false;
        //}
        if(!BOOL_VOID_FindIsolatedCellRecursive(INT_X-2,INT_Y,2,INT_Array_RootMap)){
            return false;
        }
        if(!BOOL_VOID_FindIsolatedCellRecursive(INT_X-2,INT_Y,3,INT_Array_RootMap)){
            return false;
        }
    }

    if(INT_Array_RootMap[INT_X][INT_Y-1]==99&&INT_Array_RootMap[INT_X+1][INT_Y]==99&&INT_Array_RootMap[INT_X][INT_Y+1]==99&&INT_Array_RootMap[INT_X-1][INT_Y]==99){
        //Isolated
        std::cout<<"Isolated!! (X,Y) = ("<<INT_X/2<<","<<INT_Y/2<<")"<<std::endl;
        return true;
    }
    if(11<INT_X&&INT_X<17&&11<INT_Y&&INT_Y<17){
        std::cout<<"Not Isolated!!"<<std::endl;
        return false;
    }
}
