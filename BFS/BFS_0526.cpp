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
int d[101][101];
bool ch[101][101];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void bfs(){
    queue<pair<int,int>> q;
    q.push({0,0});
    d[0][0] = 0;
    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        for(int i = 0;  i < 4; i++){
            int nx = qx+ dx[i];
            int ny = qy + dy[i];
            if(0 >nx || nx >= N || 0 > ny || ny >= M) continue;


           if(d[nx][ny] > d[qx][qy] + m[nx][ny]){
               d[nx][ny] = d[qx][qy] + m[nx][ny];
               q.push({nx,ny});
           }

        }
    }
    return;
}
int main() {

    cin>> M>> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%1d", &m[i][j]);
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            d[i][j] = 987654321;
        }
    }

     bfs();
    cout<<d[N-1][M-1];

    return 0;
}
