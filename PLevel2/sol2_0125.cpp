#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int dx[] = {0,0,1,-1,};
int dy[] = {1,-1,0,0};
bool c[501][501][4];
vector<string> map;

int changeDir(char c,int dir){
    if(c == 'L'){
        if(dir == 0) return 3;
        if(dir == 1) return 2;
        if(dir == 2) return 0;
        if(dir == 3) return 1;
    }else{
        if(dir == 0) return 2;
        if(dir == 1) return 3;
        if(dir == 2) return 1;
        if(dir == 3) return 0;
    }
}

int bfs(int x, int y ,int d,int l){
    int num= 0;
    c[x][y][d] = true;
    queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push({{x,y},{d,l}});
    while(!q.empty()){
        num++;
        int qx = q.front().first.first;
        int qy = q.front().first.second;
        int qd = q.front().second.first;
        int ql = q.front().second.second;
        q.pop();
        if(map[qx][qy] !='S')  qd = changeDir(map[qx][qy],qd);
        int nx = qx + dx[qd];
        int ny = qy + dy[qd];
        if(nx == N) nx = 0;
        if(ny == M) ny = 0;
        if(nx < 0) nx = N-1;
        if(ny < 0) ny = M-1;
         if(x == nx && ny == y && qd ==d ){
             return ql+1;
         }
        if(c[nx][ny][qd]) continue;
        q.push({{nx,ny},{qd,ql+1}});
        c[nx][ny][qd] = true;
    }
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    map = grid;
    N = grid.size(); M = grid[0].size();
    for(int i = 0; i < N; i++){
        for(int j =0; j < M; j++){
            for(int k = 0; k < 4; k++){
                if(c[i][j][k]) continue;
                int len = bfs(i,j,k,0);
                if(len > 0) answer.push_back(len);
            }
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}