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

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int N, M;
vector<vector<int>> a(9,vector<int>(9));
vector<pair<int,pair<int,int>>> cctv;
int dir[9];
int answer = -1;

void check(vector<vector<int>> &b,int x, int y, int dir){
    int i = x;
    int j = y;
    while(0 <= i && i < N && 0 <= j && j < M){
        if(a[i][j] == 6) break;
        b[i][j] = a[x][y];
        i += dx[dir];
        j += dy[dir];
    }
}

void onCCTV(){
    vector<vector<int>> b(a);
    for(int i = 0; i < cctv.size(); i++){
        int what = cctv[i].first;
        int x = cctv[i].second.first;
        int y = cctv[i].second.second;
        if(what == 1){
            check(b,x,y,dir[i]);
        }else if(what == 2){
            check(b,x,y,dir[i]);
            check(b,x,y,(dir[i]+2)%4);
        }else if(what == 3){
            check(b,x,y,dir[i]);
            check(b,x,y,(dir[i]+1)%4);
        }else if(what == 4){
            check(b,x,y,dir[i]);
            check(b,x,y,(dir[i]+1)%4);
            check(b,x,y,(dir[i]+2)%4);
        }else if(what == 5){
            check(b,x,y,dir[i]);
            check(b,x,y,(dir[i]+1)%4);
            check(b,x,y,(dir[i]+2)%4);
            check(b,x,y,(dir[i]+3)%4);
        }
    }
    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(b[i][j] == 0){
                cnt+=1;
            }
        }
    }
    if(answer == -1 || answer> cnt){
        answer = cnt;
    }
}

void makeDir(int index){
    if(index >= cctv.size()){
        onCCTV();
        return;
    }
    for(int i = 0; i < 4; i++){
       dir[index] = i;
       makeDir(index+1);
    }
}

int main(){
    cin>> N>> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>a[i][j];
            if(a[i][j] >=1 && a[i][j] <=5){
                cctv.push_back({a[i][j],{i,j}});
            }
        }
    }
    makeDir(0);

    cout<<answer<<"\n";
    return 0;
}