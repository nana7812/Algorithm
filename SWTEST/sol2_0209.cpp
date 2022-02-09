#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N,M;
int v[15][15][15][15];
char a[15][15];
int rX,rY,bX,bY;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};


bool rFirst(int rx, int ry, int bx, int by, int dir){
    if(dir == 0){
        if(ry == by && rx < bx) return true;
    }
    if(dir == 1){
        if(ry == by && rx > bx) return true;
    }
    if(dir == 2){
        if(rx == bx && ry < by) return true;
    }
    if(dir == 3){
        if(rx == bx && ry > by) return true;
    }
    return false;
}

pair<int,int> move(int x, int y,int cx,int cy, int dir){
    while(true){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(0 > nx || nx >= N || 0 > ny || ny >= M ){
            return make_pair(x,y);
        }
        if(a[nx][ny] == 'O'){
            return make_pair(nx,ny);
        }else if(a[nx][ny] == '#' || nx == cx && ny == cy){
            return make_pair(x,y);
        }else if(a[nx][ny] == '.'){
            x = nx;
            y = ny;
        }
    }
    return make_pair(x,y);
}

int main(){
    int answer = -1;
    memset(v,-1,sizeof(v));
    //입력
    cin>>N>> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>a[i][j];
            if(a[i][j] == 'B'){
                bX = i;
                bY = j;
                a[i][j] = '.';
            }else if(a[i][j] == 'R'){
                rX = i;
                rY = j;
                a[i][j] = '.';
            }
        }
    }

    queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push({{rX,rY},{bX,bY}});
    v[rX][rY][bX][bY] = 0;
    bool hole = false;
    while(!q.empty()){
        int qrx = q.front().first.first;
        int qry = q.front().first.second;
        int qbx = q.front().second.first;
        int qby = q.front().second.second;
        q.pop();
        for(int i = 0; i < 4; i++){
            if(rFirst(qrx,qry,qbx,qby,i)){ //빨간색 먼저 움직이기
                auto nR = move(qrx,qry,qbx,qby,i);
                auto nB = move(qbx,qby,nR.first,nR.second,i);
                if(a[nB.first][nB.second] == 'O') continue;
                if(a[nR.first][nR.second] == 'O'){
                    answer = v[qrx][qry][qbx][qby] +1;
                    hole = true;
                    break;
                }
                if(v[nR.first][nR.second][nB.first][nB.second] == -1 && v[qrx][qry][qbx][qby] +1 < 10){
                    v[nR.first][nR.second][nB.first][nB.second] = v[qrx][qry][qbx][qby] +1;
                    q.push({{nR.first,nR.second},{nB.first,nB.second}});
                }
            }else{ //파란색 먼저 움직이기
                auto nB = move(qbx,qby,qrx,qry,i);
                if(a[nB.first][nB.second] == 'O') continue;
                auto nR = move(qrx,qry,nB.first,nB.second,i);
                if(a[nR.first][nR.second] == 'O'){
                    hole = true;
                    answer = v[qrx][qry][qbx][qby] +1;
                    break;
                }
                if(v[nR.first][nR.second][nB.first][nB.second] == -1 && v[qrx][qry][qbx][qby] +1 < 10){
                    v[nR.first][nR.second][nB.first][nB.second] = v[qrx][qry][qbx][qby] +1;
                    q.push({{nR.first,nR.second},{nB.first,nB.second}});
                }
            }
        }
        if(hole) break;
    }
    cout<<answer<<"\n";
}