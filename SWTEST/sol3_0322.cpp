#include <vector>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int N,L,R;
int a[51][51];
int temp[51][51];
int v[51][51];

int bfs(int num, int x, int y){
    v[x][y] = num;
    queue<pair<int,int>> q;
    q.push({x,y});
    int neighbor = 1; int total = a[x][y];
    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            if(0 > nx || nx >= N || 0 > ny || ny >= N) continue;
            if(v[nx][ny] == num) continue;
            int diff = abs(a[qx][qy] - a[nx][ny]);
            if(L <= diff && diff <= R){
                v[nx][ny] = num;
                neighbor++;
                total += a[nx][ny];
                q.push({nx,ny});
            }
        }
    }

    int divide = total/neighbor;
    if(neighbor > 1){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(v[i][j] == num){
                    temp[i][j] = divide;
                }
            }
        }
    }
    return neighbor;
}

int main() {
    cin>> N>> L>> R;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>a[i][j];
        }
    }

    int day = 0;
    while(true){
        memset(v,0,sizeof (v));
        memcpy(temp,a,sizeof(a));
        int num = 1; bool flag = false;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(v[i][j] == 0){
                    if(bfs(num,i,j) > 1){
                        flag = true;
                    }
                    num++;
                }
            }
        }
        if(!flag) break;
        memcpy(a,temp,sizeof(temp));

        day++;
    }

    cout<<day<<"\n";
    return 0;
}