#include <iostream>
#include <stdlib.h>
#include <map>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <cstring>
#include <stack>
#include <sstream>
#include <array>
using namespace std;

struct Fish{
    int x = 0;
    int y = 0;
    int dir = 0;
    bool live = true;
};

int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,-1,-1,-1,0,1,1,1};

int result = 0;

void simulation(vector<vector<int>>& v,Fish* fish,int sharkX,int sharkY,int sum){
    vector<vector<int>> nv(4,vector<int>(4));
    Fish nfish[16];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            nv[i][j] = v[i][j];
        }
    }
    for(int i = 0; i < 16; i++){
        nfish[i] = fish[i];
    }
    //상어위치에 있는 물고기 eat
    int eat = nv[sharkX][sharkY];
    nv[sharkX][sharkY] = -1;
    //방향 흡수
    int sharkD = nfish[eat].dir;
    nfish[eat].live = false;

    sum += (eat+1);
    if(result < sum) result = sum;

    //물고기 이동
    for(int i = 0; i < 16; i++){
        if(nfish[i].live){
            int x = nfish[i].x;
            int y = nfish[i].y;
            int dir = nfish[i].dir;

            int nx = x + dx[dir];
            int ny = y + dy[dir];
            while(nx < 0 || nx > 3 || ny < 0 || ny > 3 || (nx == sharkX && ny == sharkY)){
                dir++;
                nx = x + dx[dir%8];
                ny = y + dy[dir%8];
            }

            //이동할위치에 물고기가 있다면
            if(nv[nx][ny] != -1){
                nfish[i].x = nx;
                nfish[i].y = ny;
                nfish[i].dir = dir%8;
                int swapFish = nv[nx][ny];
                nfish[swapFish].x = x;
                nfish[swapFish].y = y;
                nv[nx][ny] = i;
                nv[x][y] = swapFish;
            }else{
                nfish[i].x = nx;
                nfish[i].y = ny;
                nfish[i].dir = dir%8;
                nv[nx][ny] = i;
                nv[x][y] = -1;
            }
        }
    }
    //상어이동
    for(int i = 1; i< 4; i++){
        int dirX = dx[sharkD % 8] * i;
        int dirY = dy[sharkD % 8] * i;
        int nx = sharkX + dirX;
        int ny = sharkY + dirY;
        if(nx < 0 || nx > 3 || ny < 0 || ny > 3 ) break;
        if(nv[nx][ny] != -1){
            simulation(nv,nfish,nx,ny,sum);
        }
    }
}

int main(){
    vector<vector<int>> v(4,vector<int>(4));
    Fish fish[16];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int num, dir;
            cin>> num>> dir;
            num--;dir--;
            v[i][j] = num;
            fish[num].x = i;
            fish[num].y = j;
            fish[num].dir = dir;
        }
    }
    simulation(v,fish,0,0,0);
    cout<<result<<"\n";
    return 0;
}