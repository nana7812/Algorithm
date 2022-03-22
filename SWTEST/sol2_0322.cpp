#include <vector>
#include <queue>
#include <iostream>
#include <cstring>

using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int N, M;
int city[51][51];
int answer;
vector<pair<int,int>> chicken;

int cal(){
    int d[N][N];
    memset(d,-1,sizeof(d));
    queue<pair<int,int>> q;
    for(int i = 0; i < N; i++){
        for(int j= 0; j < N; j++){
            if(city[i][j] == 2){
                q.push({i,j});
                d[i][j] = 0;
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
            if(0 > nx || nx >= N || 0 > ny || ny >= N ) continue;
            if(d[nx][ny] != -1) continue;
            q.push({nx,ny});
            d[nx][ny] = d[qx][qy] + 1;
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(city[i][j] == 1){
                ans += d[i][j];
            }
        }
    }
    return ans;
}


void choose(int idx, int cnt){
    if(cnt >= M){
        if(answer == -1 || answer > cal()){
            answer = cal();
        }
        return;
    }

    for(int i = idx; i < chicken.size(); i++){
        city[chicken[i].first][chicken[i].second] = 2;
        choose(i+1,cnt+1);
        city[chicken[i].first][chicken[i].second] = 0;
    }
}

int main() {
    cin>> N>> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>city[i][j];
            if(city[i][j] == 2){
                chicken.push_back({i,j});
                city[i][j] = 0;
            }
        }
    }

    answer = -1;
    choose(0,0);
    cout<<answer<<" ";

    return 0;
}