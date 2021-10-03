#include <iostream>
#define MAX 510
using namespace std;

int N;
int a[MAX][MAX];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int xdx[4][10] = {{-1,1,-1,1,-1,1,-2,2,0,0},
                  {-1,1,-1,1,-1,1,-2,2,0,0},
                  {0,0,1,1,2,2,1,1,3,2},
                  {0,0,-1,-1,-2,-2,-1,-1,-3,-2},
                  };
int ydy[4][10] = {{0,0,1,1,2,2,1,1,3,2},
                  {0,0,-1,-1,-2,-2,-1,-1,-3,-2},
                  {-1,1,-1,1,-1,1,-2,2,0,0},
                  {-1,1,-1,1,-1,1,-2,2,0,0},
                  };
int percent[] = {1,1,7,7,10,10,2,2,5};
int answer = 0;

void spread(int x, int y, int dir){
    int xx = x + dx[dir];
    int yy = y + dy[dir];
    if(a[xx][yy] == 0) return;

    int sand = a[xx][yy];
    int temp = sand;
    for(int i = 0; i < 9; i++){
        int nx = x + xdx[dir][i];
        int ny = y + ydy[dir][i];
        int p = percent[i];
        int plus = (temp * p) / 100 ;

        if(nx < 1 || ny < 1 || nx > N || ny > N) answer += plus;
        else a[nx][ny] += plus;

        sand -= plus;
    }
    int nx = x + xdx[dir][9];
    int ny = y + ydy[dir][9];

    if(nx < 1 || ny < 1 || nx > N || ny > N) answer += sand;
    else a[nx][ny] += sand;
    a[xx][yy] = 0;
}
int changeDir(int dir){
    if(dir == 0) return 3;
    if(dir == 1) return 2;
    if(dir == 2) return 0;
    if(dir == 3) return 1;
}
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin>>a[i][j];
        }
    }

    int x = (N+1)/2;
    int y = (N+1)/2;
    int dir = 1;
    int moveCnt = 1;

    while(true){
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < moveCnt; j++){
                spread(x,y,dir);
                x += dx[dir];
                y += dy[dir];
            }
            dir = changeDir(dir);
        }
        moveCnt++;
        if(moveCnt == N){
            for(int j = 0; j < moveCnt; j++){
                spread(x,y,dir);
                x += dx[dir];
                y += dy[dir];
            }
            break;
        }
    }
    cout<<answer<<"\n";
    return 0;
}