//
// Created by DongHoon Kim on 08/10/2018.
//


void VOID_NumberToArray_14(int INT_Input, int *Type, int *INT_X, int *INT_Y) {

    *Type=(INT_Input%100);

    *INT_Y=2*((INT_Input%10000-*Type)/100)-1;

    *INT_X=2*(INT_Input/10000)-1;
}

void VOID_Center_Location_14(int Center_INDEX, int *INT_X, int *INT_Y) {
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


int INT_MinDistanceByType_14(int Root_Type){
    int Buff_Num;

    Buff_Num=Root_Type/10;
    switch(Buff_Num){
        case 4:
            Buff_Num=0;
            break;
        case 5:
            Buff_Num=4;
            break;
        case 6:
            Buff_Num=5;
            break;
        case 7:
            Buff_Num=5;
            break;
        default:
            break;
    }
    return Buff_Num;
}
int INT_MaxDistanceByType_14(int Root_Type){
    int Buff_Num;

    Buff_Num=Root_Type/10;

    switch(Buff_Num){
        case 4:
            Buff_Num=3;
            break;
        case 5:
            Buff_Num=4;
            break;
        case 6:
            Buff_Num=9;
            break;
        case 7:
            Buff_Num=10;
            break;
        default:
            break;
    }
    return Buff_Num;
}