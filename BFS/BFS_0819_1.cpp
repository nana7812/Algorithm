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
int a[51][51];
int N,L,R;

bool bfs(){
    vector<vector<bool>> c(N,vector<bool>(N,false));
    bool ok = false;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(c[i][j] == true) continue;
            queue<pair<int,int>> q;
            q.push({i,j});
            c[i][j] = true;
            stack<pair<int,int>> unit;
            unit.push({i,j});
            int sum = a[i][j];
            while(!q.empty()){
                int qx = q.front().first;
                int qy = q.front().second;
                q.pop();
                for(int k = 0; k < 4; k++){
                    int nx = qx+ dx[k];
                    int ny = qy + dy[k];
                    if(0>nx || nx >= N || 0 > ny || ny >= N ) continue;
                    if(c[nx][ny] == true) continue;
                    int diff = abs(a[qx][qy] - a[nx][ny]);
                    if(L <= diff && diff <= R){
                        ok = true;
                        q.push({nx,ny});
                        c[nx][ny] = true;
                        unit.push({nx,ny});
                        sum += a[nx][ny];
                    }
                }
            }
            int div = sum/unit.size();
            while(!unit.empty()){
                auto p = unit.top();
                a[p.first][p.second] = div;
                unit.pop();
            }
        }
    }
    return ok;
}


int main(){
    cin>> N>>L >> R;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>a[i][j];
        }
    }
    int answer =0;
    while (true){
        if(bfs()){
            answer++;
        }else{
            break;
        }
    }
    cout<<answer;
    return 0;
}