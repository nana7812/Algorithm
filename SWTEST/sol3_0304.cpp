#include <iostream>

using namespace std;

int N,M,x,y,K,dir;
int map[25][25];
int dx[] = {0,0,0,-1,1};
int dy[] = {0,1,-1,0,0};
int dice[7] = {0,0,0,0,0,0,0};

void rotateDice(int dir){
    int temp = dice[1];
    if(dir == 1){
        dice[1] = dice[4];
        dice[4] = dice[6];
        dice[6] = dice[3];
        dice[3] = temp;
    }else if(dir == 2){
        dice[1] = dice[3];
        dice[3] = dice[6];
        dice[6] = dice[4];
        dice[4] = temp;
    }else if(dir == 3){
        dice[1] = dice[5];
        dice[5] = dice[6];
        dice[6] = dice[2];
        dice[2] = temp;
    }else{
        dice[1] = dice[2];
        dice[2] = dice[6];
        dice[6] = dice[5];
        dice[5] = temp;
    }
}

int main(){
    cin>> N>> M>> x>> y>> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }
    while(K--){
        cin>>dir;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(0<= nx && nx < N && 0 <= ny && ny < M){
            rotateDice(dir);
            if(map[nx][ny] == 0){
                map[nx][ny] = dice[6];
            }else{
                dice[6] = map[nx][ny];
                map[nx][ny] = 0;
            }
            cout<<dice[1]<<"\n";
            x = nx; y = ny;
        }
    }

    return 0;
}