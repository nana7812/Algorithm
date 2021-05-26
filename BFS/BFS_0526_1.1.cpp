#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace  std;

int M,N;
int m[101][101];
bool ch[101][101];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int bfs(int a, int b){
    priority_queue<pair<int,pair<int,int>>> pq;
    pq.push(make_pair(0,make_pair(0,0)));
    ch[a][b] = true;
    while(!pq.empty()){
        int v = -pq.top().first;
        int pqx = pq.top().second.first;
        int pqy = pq.top().second.second;

        if(pqx == N-1 && pqy == M-1){
            return v;
        }
        pq.pop();

        for(int k = 0; k < 4; k++){
            int nx = pqx + dx[k];
            int ny = pqy + dy[k];

            if(0 > nx || nx >= N || 0 > ny || ny >= M) continue;
            if(ch[nx][ny] == true) continue;

            ch[nx][ny] = true;

            if(m[nx][ny] == 1){
                pq.push(make_pair(-(v+1),make_pair(nx,ny)));
            }else{
                pq.push(make_pair(-v,make_pair(nx,ny)));
            }
        }

    }
}
int main() {

    cin>> M>> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%1d", &m[i][j]);
        }
    }

    int ans = bfs(0,0);
    cout<<ans;

    return 0;
}