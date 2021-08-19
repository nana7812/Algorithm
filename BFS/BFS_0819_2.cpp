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
int a[21][21];
bool check[21][21];
vector<pair<int,pair<int,int>>> fish;
int babyX, babyY;
int babySize = 2;
int eat = 0;

void BFS(int x, int y){
    fish.clear();
    memset(check,false,sizeof(check));
    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y},0});
    check[x][y] = true;
    while (!q.empty()){
        int qx = q.front().first.first;
        int qy = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        for(int k = 0; k < 4; k++){
            int nx = qx+ dx[k];
            int ny = qy +dy[k];
            if(0> nx|| nx >= N || 0 > ny || ny >= N) continue;
            if(check[nx][ny] == true) continue;
            if(babySize >= a[nx][ny]){
                if(a[nx][ny] > 0 && babySize > a[nx][ny]){
                        fish.push_back({cnt + 1, {nx, ny}});
                }
                q.push({{nx,ny},cnt+1});
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
            if(a[i][j] == 9){
                babyX = i;
                babyY = j;
                a[i][j] = 0;
            }
        }
    }

    int answer = 0;
    while(true) {
        BFS(babyX, babyY);
        if (fish.empty()) break;
        else{
            sort(fish.begin(),fish.end());
            eat++;
            answer += fish[0].first;
            a[fish[0].second.first][fish[0].second.second] = 0;
            babyX = fish[0].second.first;
            babyY = fish[0].second.second;
            if(eat == babySize){
                babySize++;
                eat = 0; //물고기 먹어서 ...
            }
        }
    }
    cout<<answer<<"\n";
    return 0;
}