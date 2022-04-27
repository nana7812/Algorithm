#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int N, M;
int map[55][55];
vector<pair<int,int>> v;
int answer;

int check(string virus){
    int d[N][N];
    memset(d,-1,sizeof(d));
    queue<pair<int,int>> q;
    for(int i = 0; i < virus.length(); i++){
        int idx = virus[i] - '0';
        q.push({v[idx].first,v[idx].second});
        d[v[idx].first][v[idx].second] = 0;
    }
    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(d[nx][ny] != -1 || map[nx][ny] == 1) continue;
            q.push({nx,ny});
            d[nx][ny] = d[qx][qy] + 1;
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] == 0) {
                if(d[i][j] == -1) return -1;
                if(d[i][j] > ans) ans = d[i][j];
            }
        }
    }
    return ans;
}

void select(int cnt, int idx, string virus){
    if(cnt >= M){
        int ans = check(virus);
        if(ans != -1){
            if(answer == -1 || answer > ans){
                answer = ans;
            }
        }
        return;
    }
    for(int i = idx; i < v.size(); i++){
        char c = i + '0';
        select(cnt+1,i+1,virus+c);
    }
}


int main() {

    cin>> N>> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>map[i][j];
            if(map[i][j] == 2){
                v.push_back({i,j});
            }
        }
    }

    answer = -1;
    select(0,0,"");
    cout<<answer<<"\n";

    return 0;
}