#include <iostream>
#include <cstring>
#include <queue>
#include <math.h>
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int N, L, R;
int map[55][55];
bool c[55][55];


bool move(int x, int y){
    c[x][y] = true;
    vector<pair<int,int>> g;
    g.push_back({x,y});
    queue<pair<int,int>> q;
    q.push({x,y});
    int sum = map[x][y];
    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            int diff = abs(map[nx][ny] - map[qx][qy]);
            if(c[nx][ny]) continue;
            if(L <= diff && diff <= R){
                sum += map[nx][ny];
                c[nx][ny] = true;
                q.push({nx,ny});
                g.push_back({nx,ny});
            }
        }
    }

    if(g.size() == 1) return false;
    for(int i = 0; i < g.size(); i++){
        map[g[i].first][g[i].second] = sum/g.size();
    }

    return true;
}


int main() {

    cin>> N>> L>> R;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >>map[i][j];
        }
    }

    int day = 0;
    while(true){
        memset(c, false,sizeof(c));
        bool flag = false;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(c[i][j]) continue;
                if(move(i,j)){
                    flag = true;
                }
            }
        }

        if(!flag) break;
        day++;
    }

    cout<<day<<"\n";

    return 0;
}
