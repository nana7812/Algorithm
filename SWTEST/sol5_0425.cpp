#include <iostream>

using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

int N,M,x,y,K;
int map[25][25];
int dice[] = {0,0,0,0,0,0};

void up(){
    int temp = dice[0];
    dice[0] = dice[4];
    dice[4] = dice[5];
    dice[5] = dice[1];
    dice[1] = temp;
}

void down(){
    int temp = dice[0];
    dice[0] = dice[1];
    dice[1] = dice[5];
    dice[5] = dice[4];
    dice[4] = temp;
}

void right(){
    int temp = dice[0];
    dice[0] = dice[3];
    dice[3] = dice[5];
    dice[5] = dice[2];
    dice[2] = temp;
}

void left(){
    int temp = dice[0];
    dice[0] = dice[2];
    dice[2] = dice[5];
    dice[5] = dice[3];
    dice[3] = temp;
}

void rotate(int dir){
    if(dir == 0) right();
    else if(dir == 1) left();
    else if(dir == 2) up();
    else if(dir == 3) down();
}


int main() {

    cin >> N>> M>>x>>y>>K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>map[i][j];
        }
    }

    while(K--){
        int d;
        cin>>d;
        d--;
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(0 > nx || nx >= N || 0 > ny || ny >= M) continue;

        rotate(d);

        if(map[nx][ny] == 0) {
            map[nx][ny] = dice[5];
        }else{
            dice[5] = map[nx][ny];
            map[nx][ny] = 0;
        }

        cout<<dice[0]<<"\n";

        x = nx;
        y = ny;

    }


    return 0;

}