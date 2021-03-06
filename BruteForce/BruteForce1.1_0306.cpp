#include <iostream>

using  namespace  std;

int N;
int yut[10];
int result[10];
int mar[5][2];
int score[31] = {0,5,10,15,20,
                 50,30,35,40,45,
                 100,55,60,65,70,
                 75,80,85,90,95,500,1000,
                 275,250,300,150,175,150,
                 125,350,400};

int moving[31][6];
int table[11][6] ={
        {5,22,23,24,25,26},
        {10,27,28,24,29,30},
        {22,23,24,25,26,15},
        {23,24,25,26,15,16},
        {24,29,30,20,21,21},
        {25,26,15,16,17,18},
        {26,15,16,17,18,19},
        {27,28,24,29,30,20},
        {28,24,29,30,20,21},
        {29,30,20,21,21,21},
        {30,20,21,21,21,21},
        };


int main() {
    //********//
    for(int i = 0; i <11; i++){
        for(int j = 0; j < 6; j++){
            moving[table[i][0]][j] = table[i][j];
        }
    }

    cin>> N;
    for(int i = 0; i < N; i++){
        cin>> yut[i];
    }
    for(int i = 0; i < N; i++){
        cin>>result[i];
    }
    int ans = 0;
    //위치 초기
    for(int i = 1; i <=4; i++){
        mar[i][0] = 0;
    }
    //실행
    for(int i = 0; i < N; i++){
        //특수위치 확인
        mar[result[i]][1] = 0;
        for(int j = 0; j <11; j++) {
            if (mar[result[i]][0] == table[j][0]) {
                mar[result[i]][1] = 1;
                break;
            }
        }

        if(mar[result[i]][1] == 1){
            mar[result[i]][0] = moving[mar[result[i]][0]][yut[i]];
        }else{
            mar[result[i]][0]  += yut[i];
        }
        for(int j = 1; j <= 4; j++){
            if(result[i] == j) continue;
            if(mar[result[i]][0] == mar[j][0]){
                ans = -1;
               break;
            }
        }
        if(ans == -1) break;
    }

    //계
    if(ans == -1){
        cout<<ans;
    }else{
        for(int i = 1 ; i <= 4; i++){
          ans += score[mar[i][0]];
        };
        cout<<ans;
    }

}#include <iostream>

using  namespace  std;

int N;
int yut[10];
int result[10];
int mar[5][2];
int score[31] = {0,5,10,15,20,
                 50,30,35,40,45,
                 100,55,60,65,70,
                 75,80,85,90,95,500,1000,
                 275,250,300,150,175,150,
                 125,350,400};

int moving[31][6];
int table[11][6] ={
        {5,22,23,24,25,26},
        {10,27,28,24,29,30},
        {22,23,24,25,26,15},
        {23,24,25,26,15,16},
        {24,29,30,20,21,21},
        {25,26,15,16,17,18},
        {26,15,16,17,18,19},
        {27,28,24,29,30,20},
        {28,24,29,30,20,21},
        {29,30,20,21,21,21},
        {30,20,21,21,21,21},
        };


int main() {
    //********//
    for(int i = 0; i <11; i++){
        for(int j = 0; j < 6; j++){
            moving[table[i][0]][j] = table[i][j];
        }
    }

    cin>> N;
    for(int i = 0; i < N; i++){
        cin>> yut[i];
    }
    for(int i = 0; i < N; i++){
        cin>>result[i];
    }
    int ans = 0;
    //위치 초기
    for(int i = 1; i <=4; i++){
        mar[i][0] = 0;
    }
    //실행
    for(int i = 0; i < N; i++){
        //특수위치 확인
        mar[result[i]][1] = 0;
        for(int j = 0; j <11; j++) {
            if (mar[result[i]][0] == table[j][0]) {
                mar[result[i]][1] = 1;
                break;
            }
        }

        if(mar[result[i]][1] == 1){
            mar[result[i]][0] = moving[mar[result[i]][0]][yut[i]];
        }else{
            mar[result[i]][0]  += yut[i];
        }
        for(int j = 1; j <= 4; j++){
            if(result[i] == j) continue;
            if(mar[result[i]][0] == mar[j][0]){
                ans = -1;
               break;
            }
        }
        if(ans == -1) break;
    }

    //계산
    if(ans == -1){
        cout<<ans;
    }else{
        for(int i = 1 ; i <= 4; i++){
          ans += score[mar[i][0]];
        };
        cout<<ans;
    }

}