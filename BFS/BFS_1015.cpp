#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int N,M,answer;

void BFS(vector<vector<int>> v){
    queue<pair<int,int>> q;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(v[i][j] == 2){
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        for(int k = 0; k < 4; k++){
            int nx = qx + dx[k];
            int ny = qy + dy[k];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(v[nx][ny] == 0 ){
                v[nx][ny] = 2;
                q.push({nx,ny});
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(v[i][j] == 0){
                cnt++;
            }
        }
    }
    answer = max(answer,cnt);
}

void makeWall(vector<vector<int>> v, int x, int y, int cnt){
    v[x][y] = 1;
    if(cnt >= 2){
        BFS(v);
        return;
    }
    for(int i = x; i < N; i++){
        for(int j = 0; j < M; j++){
            if(i == x && j < y) continue;
            if(v[i][j] == 0){
                makeWall(v,i,j,cnt+1);
            }
        }
    }

}

int main(){
    int T;
    cin>>T;
    while(T--){
        //초기화
        answer = 0;
        //입력
        cin>> N>> M;
        vector<vector<int>> a(N,vector<int>(M));
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin>>a[i][j];
            }
        }
        //벽 만들기 시작 점
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(a[i][j] == 0){
                    makeWall(a,i,j,0);
                }
            }
        }
        cout<<answer<<"\n";
    }

    return 0;
}