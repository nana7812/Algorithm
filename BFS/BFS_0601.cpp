#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace  std;

int N,M;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int m[1001][1001];
bool v[1001][1001][2];
//[0] = 노벽 [1] = 벽

int bfs(){
    queue<pair<pair<int, int>,pair<int, int>>> q;
    q.push({{0,0},{0,1}});
    v[0][0][0] = true;
    while(!q.empty()){
        int qx = q.front().first.first;
        int qy = q.front().first.second;
        int wall = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();

        if(qx == N-1 && qy == M-1) return cnt;

        for(int i = 0; i < 4; i++){
            int nx = qx + dx[i];
            int ny = qy + dy[i];

            if(0 > nx || nx >= N || 0 > ny || ny >= M) continue;

            if(m[nx][ny] == 1 && wall == 0){
                q.push({{nx,ny},{wall+1,cnt+1}});
                v[nx][ny][wall+1] = true;
            }
            if(m[nx][ny] == 0 && v[nx][ny][wall] == false){
                q.push({{nx,ny},{wall,cnt+1}});
                v[nx][ny][wall] = true;
            }
        }
    }
    return -1;
}

int main() {

  cin>> N>> M;
  for(int i = 0; i < N; i++){
      string temp; cin>>temp;
      for(int j = 0; j < M; j++){
          m[i][j] = temp[j] - '0';
      }
  }

  int ans = bfs();
  cout<<ans;

  return 0;
}