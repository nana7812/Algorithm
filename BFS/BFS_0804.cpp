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

using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int a[1001][1001];
int d[1001][1001][11];
int  N, M,K;

void bfs(int x, int y){
    queue<pair<pair<int,int>,int>> q;
    q.push({{0,0},0});
    d[0][0][0] = 1;
    while(!q.empty()){
        int qx = q.front().first.first;
        int qy = q.front().first.second;
        int qk = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = qx+ dx[i];
            int ny = qy + dy[i];
            if(0> nx || nx >= N || 0 > ny || ny >= M ) continue;
            if(a[nx][ny] == 0 && d[nx][ny][qk] == 0){
                d[nx][ny][qk] = d[qx][qy][qk] + 1;
                q.push({{nx,ny},qk});
            }else if(qk +1 <= K && a[nx][ny] == 1  && d[nx][ny][qk+1] == 0){
                d[nx][ny][qk+1] = d[qx][qy][qk] +1;
                q.push({{nx,ny},qk+1});
            }
        }
    }
}

int main() {
    cin>> N>> M >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            char t ;
            cin>> t;
            a[i][j] = t-'0';
        }
    }

    bfs(0,0);

    int ans = -1;
    for(int i = 0; i <= K; i++){
        if(d[N-1][M-1][i] == 0) continue;
        if(ans == -1){
            ans = d[N-1][M-1][i];
        }
        if(ans > d[N-1][M-1][i]){
            ans = d[N-1][M-1][i];
        }
    }

    cout<<ans<<"\n";
    return 0;
}