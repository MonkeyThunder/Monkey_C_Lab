#include <iostream>

class Root_Map_14{

private:
    int Map_Array_14[29][29];//14+15(Wall)
    int Buff_Map_Array_14[29][29];
    int Root_Path_Array_14[50][50][2];

public:
    void Map_Initialize();
    void Path_Initialize();
    void Set_Flower();
    void CopyArrayToBuff();

    void NumberToArray_14(int INT_Input);
    void NumberToArray_14(int INT_Input, int *Type, int *INT_X, int *INT_Y);

    void Center_Location(int Center_INDEX, int *INT_X, int *INT_Y);
    int Distance(int Start_X, int Start_Y, int Dest_X, int Dest_Y);
    int MinDistanceByType(int Root_Type);
    int MaxDistanceByType(int Root_Type);
    void RootTypeToSetWall(int Type, int INT_X, int INT_Y);

    int AStarAlgorithm(int Path_Index,int Min_Distance, int Start_X, int Start_Y, int Dest_X, int Dest_Y);

    void FindRoute(int INT_Input);

    int Checking_Data(int INT_X, int INT_Y);
    void Print_Data();
    void Buff_Print_Data();
};

void RootTypexy(int ForE, int Type, int *INT_X, int *INT_Y);

int main() {


    int Test_Num_01=50464;
    int Test_Num_02=60499;

    Root_Map_14 FirstSession;

    FirstSession.Map_Initialize();
    FirstSession.Path_Initialize();

    FirstSession.Set_Flower();

    FirstSession.NumberToArray_14(Test_Num_01);
    FirstSession.NumberToArray_14(Test_Num_02);
    FirstSession.NumberToArray_14(30499);
    FirstSession.NumberToArray_14(40599);

    //FirstSession.Print_Data();

    int Test_Type, Test_INDEX, Test_X01, Test_X02, Test_Y01, Test_Y02;
    FirstSession.NumberToArray_14(Test_Num_01,&Test_Type,&Test_X01,&Test_Y01);
    FirstSession.Center_Location(15,&Test_X02,&Test_Y02);

    FirstSession.FindRoute(Test_Num_01);

    FirstSession.Buff_Print_Data();

    //FirstSession.NumberToArray_14(Test_Num_02,&Test_Type,&Test_X,&Test_Y);

    //std::cout<< Test_Type << " " << Test_X << " " << Test_Y;

    return 0;
}

void Root_Map_14::Map_Initialize() {
    for(int i0=0;i0<29;i0++){
        for(int i1=0;i1<29;i1++){
            Map_Array_14[i1][i0]=0;
        }
    }

    for(int i0=0;i0<15;i0++){
        for(int i1=0;i1<15;i1++){
            Map_Array_14[2*i0][2*i1+1]=1;
            Map_Array_14[2*i0+1][2*i1]=1;
        }
        Map_Array_14[2*i0+1][0]=99;
        Map_Array_14[2*i0+1][28]=99;
        Map_Array_14[0][2*i0+1]=99;
        Map_Array_14[28][2*i0+1]=99;
    }
}
void Root_Map_14::Path_Initialize(){
    for(int i0=0;i0<50;i0++){
        for(int i1=0;i1<50;i1++){
            Root_Path_Array_14[i0][i1][0]=-1;
            Root_Path_Array_14[i0][i1][1]=-1;
        }
    }

}
void Root_Map_14::Set_Flower() {
    for(int i0=10;i0<19;i0++){
        for(int i1=10;i1<19;i1++){
            Map_Array_14[i0][i1]=97;
        }
    }
}
void Root_Map_14::CopyArrayToBuff(){
    for(int i0=0;i0<29;i0++){
        for(int i1=0;i1<29;i1++){
            Buff_Map_Array_14[i0][i1]=Map_Array_14[i0][i1];
        }
    }
}

void Root_Map_14::NumberToArray_14(int INT_Input) {
    int Buff_Num_X, Buff_Num_Y, Buff_Num_Type;

    Buff_Num_Type=(INT_Input%100);

    Buff_Num_Y=2*((INT_Input%10000-Buff_Num_Type)/100)-1;

    Buff_Num_X=2*(INT_Input/10000)-1;

    Map_Array_14[Buff_Num_X][Buff_Num_Y]=Buff_Num_Type;

    RootTypeToSetWall(Buff_Num_Type,Buff_Num_X,Buff_Num_Y);

    //std::cout<< Buff_Num_X << ", " << Buff_Num_Y << " = " << Buff_Num_Type <<std::endl;
}
void Root_Map_14::NumberToArray_14(int INT_Input, int *Type, int *INT_X, int *INT_Y) {

    *Type=(INT_Input%100);

    *INT_Y=2*((INT_Input%10000-*Type)/100)-1;

    *INT_X=2*(INT_Input/10000)-1;
}

void Root_Map_14::Center_Location(int Center_INDEX, int *INT_X, int *INT_Y) {
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
int Root_Map_14::Distance(int Start_X, int Start_Y, int Dest_X, int Dest_Y) {
    return abs(Start_X-Dest_X)/2+abs(Start_Y-Dest_Y)/2;
}
int Root_Map_14::MinDistanceByType(int Root_Type){
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
int Root_Map_14::MaxDistanceByType(int Root_Type){
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
void Root_Map_14::RootTypeToSetWall(int Type, int INT_X, int INT_Y){
    int Buff_Num;

    Buff_Num=Type%10;

    if(Type<70){
        switch (Buff_Num){
            case 1:
                if(INT_X<27){
                    Map_Array_14[INT_X+1][INT_Y]=99;
                }
                if(INT_X>0){
                    Map_Array_14[INT_X-1][INT_Y]=99;
                }
                break;
            case 2:
                if(INT_Y<27){
                    Map_Array_14[INT_X][INT_Y+1]=99;
                }
                if(INT_Y>0){
                    Map_Array_14[INT_X][INT_Y-1]=99;
                }
                break;
            case 3:
                if(INT_X>0){
                    Map_Array_14[INT_X-1][INT_Y]=99;
                }
                if(INT_Y<27){
                    Map_Array_14[INT_X][INT_Y+1]=99;
                }
                break;
            case 4:
                if(INT_X>0){
                    Map_Array_14[INT_X-1][INT_Y]=99;
                }
                if(INT_Y>0){
                    Map_Array_14[INT_X][INT_Y-1]=99;
                }
                break;
            case 5:
                if(INT_X<27){
                    Map_Array_14[INT_X+1][INT_Y]=99;
                }
                if(INT_Y>0){
                    Map_Array_14[INT_X][INT_Y-1]=99;
                }
                break;
            case 6:
                if(INT_X<27){
                    Map_Array_14[INT_X+1][INT_Y]=99;
                }
                if(INT_Y<27){
                    Map_Array_14[INT_X][INT_Y+1]=99;
                }
                break;
            default:
                break;
        }
    }
    else if(Type>70){
        switch (Buff_Num){
            case 1:
                    Map_Array_14[INT_X+1][INT_Y]=99;
                    Map_Array_14[INT_X-1][INT_Y]=99;
                    Map_Array_14[INT_X][INT_Y+1]=99;
                break;
            case 2:
                    Map_Array_14[INT_X-1][INT_Y]=99;
                    Map_Array_14[INT_X][INT_Y-1]=99;
                    Map_Array_14[INT_X][INT_Y+1]=99;
                break;
            case 3:
                    Map_Array_14[INT_X+1][INT_Y]=99;
                    Map_Array_14[INT_X-1][INT_Y]=99;
                    Map_Array_14[INT_X][INT_Y+1]=99;
                break;
            case 4:
                    Map_Array_14[INT_X+1][INT_Y]=99;
                    Map_Array_14[INT_X][INT_Y-1]=99;
                    Map_Array_14[INT_X][INT_Y+1]=99;
                break;
            case 8:
                    Map_Array_14[INT_X-1][INT_Y]=99;
                    Map_Array_14[INT_X+1][INT_Y]=99;
                    Map_Array_14[INT_X][INT_Y-1]=99;
                    Map_Array_14[INT_X][INT_Y+1]=99;
                break;
            case 9:
                    Map_Array_14[INT_X-1][INT_Y]=99;
                    Map_Array_14[INT_X+1][INT_Y]=99;
                    Map_Array_14[INT_X][INT_Y-1]=99;
                    Map_Array_14[INT_X][INT_Y+1]=99;
                break;
            default:
                break;
        }
    }
}

int Root_Map_14::AStarAlgorithm(int Path_Index, int Min_Distance, int Start_X, int Start_Y, int Dest_X, int Dest_Y){
    int Current_X, Current_Y, Buff_INT01, Buff_INT02;
    int Buff_Num01, Buff_Num01_1, Buff_Num02, Buff_Num03, Weight[4];
    int Node_Array[29][29][5];//0-Depth(From Start), 1-Distance, 2-0+1, 3-Before_X, 4-Before_Y
    int CloseNode[29][29][5];

    for(int i0=0;i0<29;i0++){
        for(int i1=0;i1<29;i1++){
            for(int i2=0;i2<5;i2++){
                Node_Array[i0][i1][i2]=9999;
            }
        }
    }
    for(int i0=0;i0<29;i0++){
        for(int i1=0;i1<29;i1++){
            for(int i2=0;i2<5;i2++){
                CloseNode[i0][i1][i2]=9999;
            }
        }
    }

    Current_X=Start_X; Current_Y=Start_Y;
    Buff_INT01=0;
    Buff_INT02=0;

    CopyArrayToBuff();

    Node_Array[Start_X][Start_Y][0]=0;
    Node_Array[Start_X][Start_Y][1]=Distance(Start_X,Start_Y,Dest_X,Dest_Y);
    Node_Array[Start_X][Start_Y][2]=Node_Array[Start_X][Start_Y][0]+Node_Array[Start_X][Start_Y][1];
    Node_Array[Start_X][Start_Y][3]=Current_X;
    Node_Array[Start_X][Start_Y][4]=Current_Y;

    for(int i0=0;i0<4;i0++){
        CloseNode[Start_X][Start_Y][i0]=Node_Array[Start_X][Start_Y][i0];
    }
    for(int i0=0;i0<4;i0++){
        Node_Array[Start_X][Start_Y][i0]=1000;
    }
    //std::cout<<"Start= ("<<Current_X/2<<","<<Current_Y/2<<")"<<std::endl;

    Buff_Num01=CloseNode[Start_X][Start_Y][0]; Buff_Num02=Current_X; Buff_Num03=Current_Y;
    Buff_INT02=0;

    while(true){

        if(Current_X==Dest_X&&Current_Y==Dest_Y&&Buff_Num01>=Min_Distance){
            break;
        }
        if(Buff_INT02>1000){
            break;
        }
        if(Current_Y>2) {
            Buff_INT01=Distance(Current_X, Current_Y - 2, Dest_X, Dest_Y);
            Node_Array[Current_X][Current_Y - 2][0] = Buff_Num01 + Buff_Map_Array_14[Current_X][Current_Y - 1];
            Node_Array[Current_X][Current_Y - 2][1] = Buff_INT01;
            Node_Array[Current_X][Current_Y - 2][2] =
                    Node_Array[Current_X][Current_Y - 2][0] + Node_Array[Current_X][Current_Y - 2][1];
            Node_Array[Current_X][Current_Y - 2][3] = Buff_Num02;
            Node_Array[Current_X][Current_Y - 2][4] = Buff_Num03;
        }
        if(Current_X<27) {
            Buff_INT01=Distance(Current_X + 2, Current_Y, Dest_X, Dest_Y);
            Node_Array[Current_X + 2][Current_Y][0] = Buff_Num01 + Buff_Map_Array_14[Current_X + 1][Current_Y];
            Node_Array[Current_X + 2][Current_Y][1] = Buff_INT01;
            Node_Array[Current_X + 2][Current_Y][2] =
                    Node_Array[Current_X + 2][Current_Y][0] + Node_Array[Current_X + 2][Current_Y][1];
            Node_Array[Current_X + 2][Current_Y][3] = Buff_Num02;
            Node_Array[Current_X + 2][Current_Y][4] = Buff_Num03;
        }
        if(Current_Y<27) {
            Buff_INT01=Distance(Current_X, Current_Y + 2, Dest_X, Dest_Y);
            Node_Array[Current_X][Current_Y + 2][0] = Buff_Num01 + Buff_Map_Array_14[Current_X][Current_Y + 1];
            Node_Array[Current_X][Current_Y + 2][1] = Buff_INT01;
            Node_Array[Current_X][Current_Y + 2][2] =
                    Node_Array[Current_X][Current_Y + 2][0] + Node_Array[Current_X][Current_Y + 2][1];
            Node_Array[Current_X][Current_Y + 2][3] = Buff_Num02;
            Node_Array[Current_X][Current_Y + 2][4] = Buff_Num03;
        }
        if(Current_X>2) {
            Buff_INT01=Distance(Current_X - 2, Current_Y, Dest_X, Dest_Y);
            Node_Array[Current_X - 2][Current_Y][0] = Buff_Num01 + Buff_Map_Array_14[Current_X - 1][Current_Y];
            Node_Array[Current_X - 2][Current_Y][1] = Buff_INT01;
            Node_Array[Current_X - 2][Current_Y][2] =
                    Node_Array[Current_X - 2][Current_Y][0] + Node_Array[Current_X - 2][Current_Y][1];
            Node_Array[Current_X - 2][Current_Y][3] = Buff_Num02;
            Node_Array[Current_X - 2][Current_Y][4] = Buff_Num03;
        }


        Buff_Num01=9999999;

        //Find Min Weight Path
        for(int i0=0;i0<14;i0++){
            for(int i1=0;i1<14;i1++){
                if (Node_Array[2 * i0 + 1][2 * i1 + 1][2] < Buff_Num01) {
                    Buff_Num01 = Node_Array[2 * i0 + 1][2 * i1 + 1][2];
                    Buff_Num02 = 2 * i0 + 1;
                    Buff_Num03 = 2 * i1 + 1;
                }
            }
        }

        // Copy Node_Array to CloseNode, initialize Node_Array
        for (int i0 = 0; i0 < 6; i0++) {
            CloseNode[Buff_Num02][Buff_Num03][i0] = Node_Array[Buff_Num02][Buff_Num03][i0];
            Node_Array[Buff_Num02][Buff_Num03][i0] = 1000;
        }


        // Blocking Path which is already passed
        if(abs(Current_X-Buff_Num02)>=1||abs(Current_Y-Buff_Num03)>=1) {
            Current_X = CloseNode[Buff_Num02][Buff_Num03][3];
            Current_Y = CloseNode[Buff_Num02][Buff_Num03][4];
        }
            if(Current_X==Buff_Num02){
                if(Current_Y>Buff_Num03){
                    Buff_Map_Array_14[Current_X][Current_Y-abs(Current_Y-Buff_Num03)/2]=90;
                }
                else{
                    Buff_Map_Array_14[Current_X][Current_Y+abs(Current_Y-Buff_Num03)/2]=80;
                }
            }
            if(Current_Y==Buff_Num03){
                if(Current_X>Buff_Num02){
                    Buff_Map_Array_14[Current_X-abs(Current_X-Buff_Num02)/2][Current_Y]=90;
                }
                else{
                    Buff_Map_Array_14[Current_X+abs(Current_X-Buff_Num02)/2][Current_Y]=90;
                }
            }


        //Pass data for next loop
        Buff_Num01=CloseNode[Buff_Num02][Buff_Num03][0];
        Current_X=Buff_Num02;
        Current_Y=Buff_Num03;

        //Break Integer
        Buff_INT02++;

        //std::cout<<"("<<Current_X/2<<","<<Current_Y/2<<")=> Weight="<<CloseNode[Buff_Num02][Buff_Num03][2]<<", Distance="<<Distance(Current_X , Current_Y, Dest_X, Dest_Y)<<", From ("<<CloseNode[Buff_Num02][Buff_Num03][3]/2<<","<<CloseNode[Buff_Num02][Buff_Num03][4]/2<<")"<<std::endl;
    }

    //std::cout<<"Start = (" <<Start_X/2<<","<<Start_Y/2<<"), Dest = ("<<Dest_X/2<<", "<<Dest_Y/2<<"), Min="<<Min_Distance<<", Max"<<Max_Distance<<std::endl;

    //Recording Area

    Buff_INT01=1;

    Current_X=Dest_X;
    Current_Y=Dest_Y;
    Root_Path_Array_14[Path_Index][0][0]=Dest_X;
    Root_Path_Array_14[Path_Index][0][1]=Dest_Y;

    while(true){

        //std::cout<<"("<<Current_X/2<<","<<Current_Y/2<<")"<<"<-";
        Root_Path_Array_14[Path_Index][Buff_INT01][0]=CloseNode[Current_X][Current_Y][3];
        Root_Path_Array_14[Path_Index][Buff_INT01][1] =CloseNode[Current_X][Current_Y][4];
        Current_X=Root_Path_Array_14[Path_Index][Buff_INT01][0];
        Current_Y=Root_Path_Array_14[Path_Index][Buff_INT01][1];
        Buff_INT01++;
        if(Current_X==Start_X&&Current_Y==Start_Y){
            break;
        }
        if(Buff_INT01>20){
            break;
        }
    }
    //std::cout<<"("<<Current_X/2<<","<<Current_Y/2<<")"<<std::endl;
    //std::cout<<Buff_INT01<<std::endl;

    return Buff_INT01;
}

void Root_Map_14::FindRoute(int INT_Input){
    int Buff_Num_0;
    int Buff_Num_Type, Buff_Num_X, Buff_Num_Y;
    int Buff_Num_X01, Buff_Num_X02, Buff_Num_Y01, Buff_Num_Y02;
    int Buff_Num_DX01, Buff_Num_DX02, Buff_Num_DY01, Buff_Num_DY02;
    int Buff_Path_Distance;


    NumberToArray_14(INT_Input,&Buff_Num_Type,&Buff_Num_X,&Buff_Num_Y);

    std::cout<<INT_Input<<" "<<Buff_Num_Type<<" "<<Buff_Num_X<<" "<<Buff_Num_Y<<" "<<MinDistanceByType(Buff_Num_Type)<<" "<<MaxDistanceByType(Buff_Num_Type)<<std::endl;

    Buff_Num_X01=Buff_Num_X; Buff_Num_X02=Buff_Num_X;
    Buff_Num_Y01=Buff_Num_Y; Buff_Num_Y02=Buff_Num_Y;

    Buff_Num_0=0;
    Buff_Path_Distance=9999;

    if(Buff_Num_Type/10<7){
        RootTypexy(0,Buff_Num_Type,&Buff_Num_X01,&Buff_Num_Y01);

        for(int i0=0;i0<16;i0++){
            Center_Location(i0,&Buff_Num_DX01,&Buff_Num_DY01);

            if(Map_Array_14[Buff_Num_X01][Buff_Num_Y01]==0&&Distance(Buff_Num_X01,Buff_Num_Y01,Buff_Num_DX01,Buff_Num_DY01)<=MaxDistanceByType(Buff_Num_Type)){
                Buff_Path_Distance=AStarAlgorithm(Buff_Num_0,MinDistanceByType(Buff_Num_Type),Buff_Num_X01,Buff_Num_Y01,Buff_Num_DX01,Buff_Num_DY01);
                std::cout<<"i0="<<i0<<" Buff_Num = "<<Buff_Num_0<<" Distance = "<<Buff_Path_Distance<<std::endl;
                if(Buff_Path_Distance>=MinDistanceByType(Buff_Num_Type)&&Buff_Path_Distance<=MaxDistanceByType(Buff_Num_Type)){
                    Buff_Num_0++;
                }
                else{
                    for(int i1=0;i1<50;i1++){
                        Root_Path_Array_14[Buff_Num_0][i1][0]=-1;
                        Root_Path_Array_14[Buff_Num_0][i1][1]=-1;
                    }
                }
                Buff_Path_Distance=9999;
            }
        }
        std::cout<<"From ("<<Buff_Num_X01/2<<","<<Buff_Num_Y01/2<<"), Buff_0="<<Buff_Num_0<<std::endl;

        RootTypexy(1,Buff_Num_Type,&Buff_Num_X02,&Buff_Num_Y02);

        for(int i0=0;i0<16;i0++){
            Center_Location(i0,&Buff_Num_DX02,&Buff_Num_DY02);

            if(Map_Array_14[Buff_Num_X02][Buff_Num_Y02]==0&&Distance(Buff_Num_X01,Buff_Num_Y01,Buff_Num_DX02,Buff_Num_DY02)<=MaxDistanceByType(Buff_Num_Type)){
                Buff_Path_Distance=AStarAlgorithm(Buff_Num_0,MinDistanceByType(Buff_Num_Type),Buff_Num_X02,Buff_Num_Y02,Buff_Num_DX02,Buff_Num_DY02);
                std::cout<<"Distance = "<<Buff_Path_Distance<<std::endl;
                if(Buff_Path_Distance>=MinDistanceByType(Buff_Num_Type)&&Buff_Path_Distance<=MaxDistanceByType(Buff_Num_Type)){
                    Buff_Num_0++;
                }
                else{
                    for(int i1=0;i1<50;i1++){
                        Root_Path_Array_14[Buff_Num_0][i1][0]=-1;
                        Root_Path_Array_14[Buff_Num_0][i1][1]=-1;
                    }
                }
                Buff_Path_Distance=9999;
            }
        }

        std::cout<<"From ("<<Buff_Num_X02/2<<","<<Buff_Num_Y02/2<<"), Buff_0="<<Buff_Num_0<<std::endl;

    }
    else if(Buff_Num_Type/10<8){
        RootTypexy(0,Buff_Num_Type,&Buff_Num_X01,&Buff_Num_Y01);

        for(int i0=0;i0<16;i0++){
            Center_Location(i0,&Buff_Num_DX01,&Buff_Num_DY01);

            if(Map_Array_14[Buff_Num_X01][Buff_Num_Y01]==0&&Distance(Buff_Num_X01,Buff_Num_Y01,Buff_Num_DX01,Buff_Num_DY01)<=MaxDistanceByType(Buff_Num_Type)){
                Buff_Path_Distance=AStarAlgorithm(Buff_Num_0,MinDistanceByType(Buff_Num_Type),Buff_Num_X01,Buff_Num_Y01,Buff_Num_DX01,Buff_Num_DY01);
                std::cout<<"Distance = "<<Buff_Path_Distance<<std::endl;
                if(Buff_Path_Distance>=MinDistanceByType(Buff_Num_Type)&&Buff_Path_Distance<=MaxDistanceByType(Buff_Num_Type)){
                    Buff_Num_0++;
                }
                else{
                    for(int i1=0;i1<50;i1++){
                        Root_Path_Array_14[Buff_Num_0][i1][0]=-1;
                        Root_Path_Array_14[Buff_Num_0][i1][1]=-1;
                    }
                }
                Buff_Path_Distance=9999;
            }
        }

        std::cout<<"From ("<<Buff_Num_X01/2<<","<<Buff_Num_Y01/2<<"), Buff_0="<<Buff_Num_0<<std::endl;
    }

    while(true){

        Buff_Num_0--;

        for(int i0=0;i0<5+MaxDistanceByType(Buff_Num_Type);i0++){
            std::cout<<"("<<Root_Path_Array_14[Buff_Num_0][i0][0]/2<<","<<Root_Path_Array_14[Buff_Num_0][i0][1]/2<<")"<<"<-";
        }
        std::cout<<std::endl;



        if(Buff_Num_0==0){
            break;
        }

    }
}

void RootTypexy(int ForE, int Type,int *INT_X, int *INT_Y) {
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

int Root_Map_14::Checking_Data(int INT_X, int INT_Y) {
    return Map_Array_14[INT_X][INT_Y];
}
void Root_Map_14::Print_Data() {
    std::cout.fill('0');
    for(int i0=0;i0<15;i0++){
        for(int i1=0;i1<14;i1++){
            if(Map_Array_14[2*i1+1][2*i0]==1){
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
            if(Map_Array_14[2*i1][2*i0+1]==1){
                std::cout << " = ";
            }
            else{
                std::cout << " | ";
            }
            if(i1==14){
                break;
            }
            std::cout.width(2);
            std::cout<<Map_Array_14[2*i1+1][2*i0+1];
        }
        std::cout<<std::endl;
        if(i0==13){
            //break;
        }

    }
}
void Root_Map_14::Buff_Print_Data() {
    std::cout.fill('0');
    for(int i0=0;i0<15;i0++){
        for(int i1=0;i1<14;i1++){
            if(Buff_Map_Array_14[2*i1+1][2*i0]==1){
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
            if(Buff_Map_Array_14[2*i1][2*i0+1]==1){
                std::cout << " = ";
            }
            else{
                std::cout << " | ";
            }
            if(i1==14){
                break;
            }
            std::cout.width(2);
            std::cout<<Buff_Map_Array_14[2*i1+1][2*i0+1];
        }
        std::cout<<std::endl;
        if(i0==13){
            //break;
        }

    }
}
