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

int dx[] = {0,0,1,-1,-2,-1,1,2,2,1,-1,-2};
int dy[] = {1,-1,0,0,1,2,2,1,-1,-2,-2,-1};
int c[] = {0,0,0,0,1,1,1,1,1,1,1,1};
int d[201][201][31];
int a[201][201];
int k,w,h;

void bfs(){
    memset(d,-1,sizeof(d));
    queue<pair<pair<int,int>,int>> q;
    q.push({{0,0},0});
    d[0][0][0] = 0;
    while(!q.empty()){
        int qx = q.front().first.first;
        int qy = q.front().first.second;
        int dk = q.front().second;
        q.pop();
        for(int i = 0; i <12; i++){
            int nx = qx+ dx[i];
            int ny = qy + dy[i];
            int nc = dk + c[i];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(a[nx][ny] == 1) continue;
            if(nc <= k){
                if(d[nx][ny][nc] == -1){
                    q.push({{nx,ny},nc});
                    d[nx][ny][nc] = d[qx][qy][dk] + 1;
                }
            }
        }
    }
}

int main() {

    cin>> k;
    cin>> w>> h;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin>>a[i][j];
        }
    }

    bfs();

    int ans = -1;
    for(int i = 0; i <= k; i++){
        if(d[h-1][w-1][i] == -1) continue;
        if(ans == -1 || d[h-1][w-1][i] < ans){
            ans = d[h-1][w-1][i];
        }
    }
    cout<<ans<<"\n";

    return 0;
}