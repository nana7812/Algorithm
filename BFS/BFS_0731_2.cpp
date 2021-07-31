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

int n;
int a[501][501][2];
int d[501][501];
int t[501][501];
bool check[501][501];
pair<int,int> from[501][501];

int dx0[] = {-1,-1,0,0,1,1};
int dy0[] = {-1,0,-1,1,-1,0};
int dx1[] = {-1,-1,0,0,1,1};
int dy1[] = {0,1,-1,1,0,1};

bool ok(int x, int y){
    if(x<0 || x >=n) return false;
    if(x%2 == 0){
        return y >=0 && y <n;
    }else{
        return y >= 0 && y < n-1;
    }
}

bool go(int x, int y, int nx, int ny){
    if(x == nx){
        if(y < ny){
            return a[x][y][1] == a[nx][ny][0];
        }else{
            return a[x][y][0] == a[nx][ny][1];
        }
    }else{
        if(x %2 == 0){
            if(y == ny){
                return a[x][y][1] == a[nx][ny][0];
            }else{
                return a[x][y][0] == a[nx][ny][1];
            }
        }else{
            if(y == ny){
                return a[x][y][0] == a[nx][ny][1];
            }else{
                return a[x][y][1] == a[nx][ny][0];
            }
        }
    }
}

int main() {
    cin>> n;
    int temp = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            temp++;
            t[i][j] = temp;
            cin>>a[i][j][0];
            cin>>a[i][j][1];
        }
        if(i%2 == 0){
            temp++;
            t[i][n-1] = temp;
            cin>>a[i][n-1][0];
            cin>>a[i][n-1][1];
        }
    }
    queue<pair<int,int>> q;
    q.push({0,0});
    d[0][0] = 1;
    check[0][0] = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k = 0; k < 6; k++){
            int nx, ny;
            if(x%2 == 0){
                nx = x + dx0[k];
                ny = y + dy0[k];
            }else{
                nx = x + dx1[k];
                ny = y + dy1[k];
            }
            if(ok(nx,ny) == false) continue;
            if(go(x,y,nx,ny) == false) continue;
            if(check[nx][ny] == true) continue;
            q.push({nx,ny});
            check[nx][ny] = true;
            d[nx][ny] = d[x][y] +1;
            from[nx][ny] = make_pair(x,y);
        }
    }

    int x = n-1;
    int y = n-1;
    while(check[x][y] == false){
        y -= 1;
        if(y <0){
            x -= 1;
            y = n-1;
            if(x%2 == 1){
                y -= 1;
            }
        }
    }

    cout<<d[x][y]<<"\n";
    stack<pair<int,int>> s;
    while(!(x==0 && y == 0)){
        s.push({x,y});
        auto p = from[x][y];
        x = p.first;
        y = p.second;

    }
    s.push({x,y});

    while(!s.empty()){
        cout<<t[s.top().first][s.top().second]<<" ";
        s.pop();
    }
  cout<<"\n";


    return 0;
}