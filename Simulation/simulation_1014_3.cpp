#include<iostream>
#include<vector>
using namespace std;

int N,M,x,y,K;
int map[25][25];
int dice[6];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

int main(){
    int T;
    cin>>T;
    while(T--){
        //input
        cin>> N>>M>>x>>y>>K;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin>>map[i][j];
            }
        }
        //주사위 0
        for(int i = 0; i < 6; i++){
            dice[i] = 0;
        }
        //실행
        vector<int> answer;
        while(K--){
            int cmd;
            cin>>cmd;
            int nx, ny;
            if(cmd == 1){
                nx = x + dx[0];
                ny = y + dy[0];
                if(nx < 0 || nx >= N || ny < 0 || ny >= M ) continue;
                int temp = dice[0];
                dice[0] = dice[3];
                dice[3] = dice[5];
                dice[5] = dice[2];
                dice[2] = temp;
            }else if(cmd == 2){
                nx = x + dx[1];
                ny = y + dy[1];
                if(nx < 0 || nx >= N || ny < 0 || ny >= M ) continue;
                int temp = dice[0];
                dice[0] = dice[2];
                dice[2] = dice[5];
                dice[5] = dice[3];
                dice[3] = temp;
            }else if(cmd == 3){
                nx = x + dx[2];
                ny = y + dy[2];
                if(nx < 0 || nx >= N || ny < 0 || ny >= M ) continue;
                int temp = dice[0];
                dice[0] = dice[1];
                dice[1] = dice[5];
                dice[5] = dice[4];
                dice[4] = temp;
            }else if(cmd == 4){
                nx = x + dx[3];
                ny = y + dy[3];
                if(nx < 0 || nx >= N || ny < 0 || ny >= M ) continue;
                int temp = dice[0];
                dice[0] = dice[4];
                dice[4] = dice[5];
                dice[5] = dice[1];
                dice[1] = temp;
            }
            if(map[nx][ny] == 0){
                map[nx][ny] = dice[5];
            }else{
                dice[5] = map[nx][ny];
                map[nx][ny] = 0;
            }
            x = nx;
            y = ny;
            cout<<dice[0]<<"\n";
        }
    }
    return 0;
}