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

int N,M;
int a[51][51];
int d[51][51];
vector<pair<int,int>> chicken;
vector<string> selectChicken;

void select(int total,int cnt,string s,int num){
    if(cnt >= M){
        selectChicken.push_back(s);
        return;
    }
    for(int i = num; i < total; i++){
        char a = i +'0';
        select(total,cnt+1,s+a,i+1);
    }
}

int main() {
    cin>> N>> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>a[i][j];
            if(a[i][j] == 2){
                chicken.push_back({i,j});
            }
        }
    }

    select(chicken.size(),0,"",0);


    int ans = -1;
    for(int i = 0; i <selectChicken.size(); i++){
        memset(d,-1,sizeof (d));
        int tempAns = 0;
        queue<pair<int,int>> q;
        string s = selectChicken[i];
        for(auto t: s){
            int it = t - '0';
            q.push({chicken[it].first,chicken[it].second});
            d[chicken[it].first][chicken[it].second] = 0;
        }
        while(!q.empty()){
            int qx = q.front().first;
            int qy = q.front().second;
            q.pop();
            if(a[qx][qy] == 1){
                tempAns += d[qx][qy];
            }
            for(int k = 0; k < 4; k++){
                int nx = qx + dx[k];
                int ny = qy + dy[k];
                if(0>nx || nx >= N || 0 > ny || ny >= N) continue;
                if(d[nx][ny] == -1){
                    q.push({nx,ny});
                    d[nx][ny] = d[qx][qy] + 1;
                }
            }
        }
        if(ans == -1 || tempAns < ans ) ans = tempAns;
    }
    cout<<ans;
    return 0;
}