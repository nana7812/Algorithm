#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

int N,M;
int cnt[11][11][11][11];
char map[11][11];
int rx,ry,bx,by;

struct Pos{
    int rx;
    int ry;
    int bx;
    int by;
};

bool rFirst(int rx, int ry, int bx, int by, int dir){
    if(dir == 0){
        return ry == by && rx < bx;
    }else if(dir == 1){
        return ry == by && rx > bx;
    }else if(dir == 2){
        return rx == bx && ry > by;
    }else if(dir == 3){
        return rx == bx && ry < by;
    }
    return false;
}

pair<int,int> move(int x, int y,int cx, int cy, int dir){
    while(true){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(map[nx][ny] == 'O') {
            return make_pair(nx, ny);
        }else if(map[nx][ny] == '#' || nx == cx && ny == cy) {
            return make_pair(x, y);
        }else if(map[nx][ny] == '.'){
            x = nx;
            y = ny;
        }
    }
}

bool checkHole(int x, int y){
    if(map[x][y] == 'O'){
        return true;
    }
    return false;
}

int main() {
    memset(cnt,-1,sizeof(cnt));
    cin>> N>> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>map[i][j];
            if(map[i][j] == 'R'){
                rx = i; ry = j;
                map[i][j] = '.';
            }else if(map[i][j] == 'B'){
                bx = i; by = j;
                map[i][j] = '.';
            }
        }
    }

    int answer = -1;
    queue<Pos> q;
    q.push({rx,ry,bx,by});
    cnt[rx][ry][bx][by] = 0;
    bool hole = false;
    while(!q.empty()){
        int qrx = q.front().rx;
        int qry = q.front().ry;
        int qbx = q.front().bx;
        int qby = q.front().by;
        q.pop();
        for(int i = 0; i < 4; i++){
            bool rhole = false, bhole = false;
            if(rFirst(qrx,qry,qbx,qby,i)){ //빨간색 먼저
                pair<int,int> rPos = move(qrx,qry,qbx,qby,i);
                pair<int,int> bPos = move(qbx,qby,rPos.first,rPos.second,i);
                rhole = checkHole(rPos.first,rPos.second);
                bhole = checkHole(bPos.first,bPos.second);
                if(bhole) continue;
                if(rhole){
                    answer = cnt[qrx][qry][qbx][qby] + 1;
                    hole = true;
                    break;
                }
                if(cnt[rPos.first][rPos.second][bPos.first][bPos.second] == -1 && cnt[qrx][qry][qbx][qby] + 1 < 10){
                    q.push({rPos.first,rPos.second,bPos.first,bPos.second});
                    cnt[rPos.first][rPos.second][bPos.first][bPos.second] = cnt[qrx][qry][qbx][qby] + 1;
                }
            }else{
                pair<int,int> bPos = move(qbx,qby,qrx,qry,i);
                bhole = checkHole(bPos.first,bPos.second);
                if(bhole) continue;
                pair<int,int> rPos = move(qrx,qry,bPos.first,bPos.second,i);
                rhole = checkHole(rPos.first,rPos.second);
                if(rhole){
                    answer = cnt[qrx][qry][qbx][qby] + 1;
                    hole = true;
                    break;
                }
                if(cnt[rPos.first][rPos.second][bPos.first][bPos.second] == -1 && cnt[qrx][qry][qbx][qby] + 1 < 10){
                    q.push({rPos.first,rPos.second,bPos.first,bPos.second});
                    cnt[rPos.first][rPos.second][bPos.first][bPos.second] = cnt[qrx][qry][qbx][qby] + 1;
                }
            }
        }

        if(hole) break;
    }

    cout<<answer<<"\n";


    return 0;


}