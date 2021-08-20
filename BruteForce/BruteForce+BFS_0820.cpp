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
int N, M;
int answer = -1;

void BFS(vector<vector<int>> &a){
    queue<pair<int,int>> q;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(a[i][j] == 2){
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            if(0>nx || nx >= N || 0 > ny || ny >= M) continue;
            if(a[nx][ny] == 0){
                a[nx][ny] = 2;
                q.push({nx,ny});
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(a[i][j] == 0){
                cnt++;
            }
        }
    }
    if(cnt > answer) answer = cnt;

}

void makeWall(vector<vector<int>> a,int x, int y,int cnt){
     a[x][y] = 1;
    if(cnt >= 2){
        BFS(a);
        return;
    }
 
    for(int i = x; i < N; i++){
        for(int j = 0;  j < M; j++){
            if(i == x && j <y) continue;
            if(a[i][j] == 0){
                makeWall(a,i,j,cnt+1);
            }
        }
    }
}


int main(){
    cin>> N>>M;
    vector<vector<int>> a(N,vector<int>(M));
    for(int i = 0; i < N; i++){
        for(int j =0; j < M; j++){
            cin>>a[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j =0; j < M; j++){
            if(a[i][j] == 0){
                makeWall(a,i,j,0);
            }
        }
    }

    cout<<answer<<"\n";
    return 0;
}