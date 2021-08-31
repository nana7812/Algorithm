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


int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int a[11][11];
int d[11][11][2];
int N, M;
int result = 987654321;
struct state{
    int x;
    int y;
    int time;
    int install;
    bool installed;

};
queue<pair<int,int>> black;

void checkBlack(){
    while(!black.empty()){
        int x = black.front().first;
        int y = black.front().second;
        black.pop();
        int row = 0; int column = 0;
        for(int i = 0; i < 2; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx< 0 || nx >= N || ny <0 || ny >= N) continue;
            if(a[nx][ny] == 0 || a[nx][ny] == -1 || a[nx][ny] >= 2) row++;
        }
        for(int i = 2; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx< 0 || nx >= N || ny <0 || ny >= N) continue;
            if(a[nx][ny] == 0 || a[nx][ny] == -1 || a[nx][ny] >= 2) column++;
        }
        if(row >=1 && column >= 1) a[x][y] = -1;
    }
}

void BFS(){
    queue<state> q;
    q.push({0,0,0,0,false});
    d[0][0][0] = 0;
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int time = q.front().time;
        int install = q.front().install;
        bool installed = q.front().installed;
        q.pop();
        if(x == N-1 && y == N-1){
            result = min(result,time);
            continue;
        }
        for(int i = 0; i < 4; i++){
            int nx = x+ dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(a[nx][ny] == -1) continue;
            if(a[nx][ny] == 1){
                if(d[nx][ny][install] > time +1){
                    d[nx][ny][install] = time +1;
                    q.push({nx,ny,time+1,install,false});
                }
            }else if(a[nx][ny] == 0){
                if(install == true || installed == true) continue;
                int v = 0;
                if((time +1) % M != 0){
                    v = M - (time +1)% M;
                }
                if(d[nx][ny][1] > time +1){
                    d[nx][ny][1] = time +1;
                    q.push({nx,ny,time+v+1,1,true});
                }
            }else if(a[nx][ny] > 1){
                if(installed) continue;
                int v = 0;
                if((time +1) % a[nx][ny] != 0){
                    v = a[nx][ny] - (time+1) %a[nx][ny];
                }
                if(d[nx][ny][1] > time+1){
                    d[nx][ny][1] = time +1;
                    q.push({nx,ny,time+1+v,install,true});
                }
                
            }

        }
    }
}

int main() {
    cin>> N>> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>a[i][j];
            if(a[i][j] == 0){
                black.push({i,j});
            }
            d[i][j][0] = 987654321;
            d[i][j][1] = 987654321;
        }
    }

    checkBlack();
    BFS();
    cout<<result;
}