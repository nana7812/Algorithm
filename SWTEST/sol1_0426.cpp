#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int N, M;
int answer;
int map[55][55];
vector<pair<int,int>> chicken;

void bfs(){
    queue<pair<int,int>> q;
    int c[N][N];
    memset(c,-1,sizeof(c));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] == 2){
                q.push({i,j});
                c[i][j] = 0;
            }
        }
    }

    int cnt = 0; int visit = 0;
    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            if(0 > nx || nx >= N || 0 > ny || ny >= N) continue;
            if(c[nx][ny] != -1) continue;
            if(map[nx][ny] == 1) {
                cnt += c[qx][qy] + 1;
                if (answer != -1 && cnt > answer) return;
            }
            q.push({nx,ny});
            c[nx][ny] = c[qx][qy] + 1;

        }
    }


    if(answer == -1 || answer > cnt){
        answer = cnt;
    }
}


void dfs(int cnt,int idx){
    if(cnt >= M){
        bfs();
        return;
    }

    for(int i = idx; i < chicken.size(); i++){
        map[chicken[i].first][chicken[i].second] = 2;
        dfs(cnt+1,i+1);
        map[chicken[i].first][chicken[i].second] = 0;
    }
}

int main() {

    cin >> N>> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>map[i][j];
            if(map[i][j] == 2){
                chicken.push_back({i,j});
                map[i][j] = 0;
            }
        }
    }

    answer = -1;
    dfs(0,0);

    cout<<answer<<"\n";

    return 0;
}
