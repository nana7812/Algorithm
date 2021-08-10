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

int N;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
char a[101][101];
bool c[101][101];

void bfs(int x, int y , int k){
    queue<pair<int,int>> q;
    q.push({x,y});
    c[x][y] = true;
    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        if(a[qx][qy] == 'B') k = 0;
        for(int i = 0; i < 4; i++){
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            if(0 > nx || nx >= N || 0 > ny || ny >=N) continue;
            if(k == 0){
                if(c[nx][ny] == false && a[nx][ny] == a[qx][qy]){
                    c[nx][ny] = true;
                    q.push({nx,ny});
                }
            }else {
                if(c[nx][ny] == false && a[nx][ny] !='B'){
                    c[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
        }
    }
}
int main() {
    cin>> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>a[i][j];
        }
    }

    int cnt; 
    for(int k = 0; k < 2; k++) {
        cnt = 0;
        memset(c,false,sizeof(c));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (c[i][j] == false) {
                    bfs(i,j,k);
                    cnt++;
                }
            }
        }
        cout<<cnt<<" ";
    }
    return 0;
}