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
int N;
char a[101][101];
bool check[101][101];

//여기를 a[x][y] a[nx][ny] p <- 이렇게 3개 매개변수로 하는게 좋으려나..?
bool go(int x, int y, int nx, int ny,int p){
    if(a[x][y] == a[nx][ny]){
        return true;
    }
    if(p == 1){
        if(a[x][y] == 'R' && a[nx][ny] == 'G')
            return true;
        if(a[x][y] == 'G' && a[nx][ny] == 'R')
            return true;
    }
    return false;
}


void BFS(int x,int y, int p){
    queue<pair<int,int>> q;
    q.push({x,y});
    check[x][y] = true;
    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = qx+ dx[i];
            int ny = qy + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(check[nx][ny]) continue;
            if(go(x,y,nx,ny,p)){
                q.push({nx,ny});
                check[nx][ny] = true;
            }
        }
    }
}

int main(){
    cin>> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>a[i][j];
        }
    }

    int p[2]= {0,0};
    for(int k = 0; k < 2; k++) {
        memset(check,false,sizeof(check));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if(check[i][j] == false){
                    BFS(i,j,k);
                    p[k]++;
                }
            }
        }
    }
    cout<<p[0]<<" "<<p[1]<<" ";
    return 0;
}
