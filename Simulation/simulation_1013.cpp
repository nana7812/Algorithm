#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int N,M;
int answer;
int c[14][14][14][14];
char a[14][14];
int rx,ry,bx,by;

void initialize(){
    memset(c,-1,sizeof(c));
    answer = -1;
}

void input(){
    cin>> N>> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>a[i][j];
            if(a[i][j] == 'R'){
                rx = i;
                ry = j;
                a[i][j] = '.';
            }else if(a[i][j] == 'B'){
                bx = i;
                by = j;
                a[i][j] = '.';
            }
        }
    }
}

bool firstmove(int rx, int ry, int bx, int by, int dir){
    if(dir == 0 && rx == bx && ry > by) return true;
    if(dir == 1 && rx == bx && ry < by) return true;
    if(dir == 2 && ry == by && rx > bx) return true;
    if(dir == 3 && ry == by && rx < bx) return true;
    return false;
}

pair<int,int> move(int x, int y, int cx, int cy, int dir){
    while(true){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || nx >= N || ny < 0 || ny >= M){
            return make_pair(x,y);
        }
	//만약 red가 먼저 이동 할 경우 red가 홀에 들어간 후 blue도 이동시 홀인데 red 때문에 못 들어가는 경우를 방지하기위해 
	//red위치 확인전에 홀인지 부터 확인해야함
        if(a[nx][ny] == 'O'){ 
            return make_pair(nx,ny);
        }
        if(a[nx][ny] == '#' || nx == cx && ny == cy){
            return make_pair(x,y);
        }
        if(a[nx][ny] == '.'){
            x = nx;
            y = ny;
        }
    }
    return make_pair(x,y);
}

void solution(){
    queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push({{rx,ry},{bx,by}});
    c[rx][ry][bx][by] = 0;
    bool hole = false;
    while(!q.empty()){
        int qrx = q.front().first.first;
        int qry = q.front().first.second;
        int qbx = q.front().second.first;
        int qby = q.front().second.second;
        q.pop();
        bool blueFirst;
        for(int i = 0; i < 4; i++){
            blueFirst = firstmove(qrx,qry,qbx,qby,i);
            if(blueFirst){
                auto blue = move(qbx,qby,qrx,qry,i);
                if(a[blue.first][blue.second] == 'O'){
                    continue;
                }
                auto red = move(qrx,qry,blue.first,blue.second,i);
                if(a[red.first][red.second] == 'O'){
                    answer = c[qrx][qry][qbx][qby] +1;
                    hole = true;
                    break;
                }
                if(c[red.first][red.second][blue.first][blue.second] == -1){
                    if(c[qrx][qry][qbx][qby] +1 < 10){
                        c[red.first][red.second][blue.first][blue.second] = c[qrx][qry][qbx][qby] +1;
                        q.push({{red.first,red.second},{blue.first,blue.second}});
                    }
                }
            }else{
                bool redHole = false; bool blueHole = false;
                auto red = move(qrx,qry,qbx,qby,i);
                if(a[red.first][red.second] == 'O'){
                    redHole = true;
                }
                auto blue = move(qbx,qby,red.first,red.second,i);
                if(a[blue.first][blue.second] == 'O'){
                    blueHole = true;
                }
                if(blueHole) continue;
                if(redHole){
                    answer = c[qrx][qry][qbx][qby] +1;
                    hole = true;
                    break;
                }
                if(c[red.first][red.second][blue.first][blue.second] == -1){
                    if(c[qrx][qry][qbx][qby] +1 < 10){
                        c[red.first][red.second][blue.first][blue.second] = c[qrx][qry][qbx][qby] +1;
                        q.push({{red.first,red.second},{blue.first,blue.second}});
                    }
                }
            }
        }
        if(hole){
            cout<<answer<<"\n";
            return;
        }
    }
    cout<<answer<<"\n";
}

int main(){

   Int T;
    cin>> T;
    while(T—){
    initialize();
    input();
    solution();
    }
    return 0;
}