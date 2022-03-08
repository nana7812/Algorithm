#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int N, M;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int answer = 0;

void spreadVirus(vector<vector<int>> &map){
    queue<pair<int,int>> q;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 2){
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
            if(0 > nx || 0 > ny || nx >= N || ny >= M) continue;
            if(map[nx][ny] == 0){
                q.push({nx,ny});
                map[nx][ny] = 2;
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 0) cnt++;
        }
    }
    if(cnt > answer) answer = cnt;
}

void makeWall(vector<vector<int>> map,int x, int y , int cnt){
    map[x][y] = 1;
    if(cnt == 3){
        spreadVirus(map);
        return;
    }
    for(int i = x; i < N; i++){
        for(int j = 0; j < M; j++){
            if(i == x && j < y) continue;
            if(map[i][j] == 0){
                makeWall(map,i,j,cnt+1);
            }
        }
    }
}

int main(){
    cin>> N>> M;
    vector<vector<int>> map(N,vector<int>(M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>map[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 0){
                makeWall(map,i,j,1);
            }
        }
    }

    cout<<answer<<"\n";
    return 0;
}