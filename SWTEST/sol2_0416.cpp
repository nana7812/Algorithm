#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int map[500][500];

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

int sx[4][10] = {{-1,1,-2,2,0,-1,1,-1,1,0},
                 {-1,-1,0,0,2,0,0,1,1,1},
                 {-1,1,-2,2,0,-1,1,-1,1,0},
                 {1,1,0,0,-2,0,0,-1,-1,-1},
                };
int sy[4][10] = {{1,1,0,0,-2,0,0,-1,-1,-1},
                 {-1,1,-2,2,0,-1,1,-1,1,0},
                 {-1,-1,0,0,2,0,0,1,1,1},
                 {-1,1,-2,2,0,-1,1,-1,1,0},
                };

int per[] = {1,1,2,2,5,7,7,10,10};

int spread(int x, int y, int dir){
    int out = 0;
    int perTotal = 0;
    int nx, ny, sand;
    for(int i = 0; i <9; i++){
        //날린 모래 양
        sand = (map[x][y] * per[i]) / 100;
        perTotal += sand;
        nx = x + sx[dir][i];
        ny = y + sy[dir][i];
        if(0 > nx || nx >= N || 0 > ny || ny >= N){
            out += sand;
        }else{
            map[nx][ny] += sand;
        }
    }
    //a만 다시 확인
    map[x][y] -= perTotal;
    nx = x + sx[dir][9]; ny = y + sy[dir][9];
    if(0 > nx || nx >= N || 0 > ny || ny >= N){
        out += map[x][y];
    }else{
        map[nx][ny] += map[x][y];
    }

    map[x][y] = 0; //모래 다 날림

    return out;
}

int main() {
    int answer = 0;
    cin>> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>map[i][j];
        }
    }

    int x = N/2; int y = N/2; int dir = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < i; k++){
                if(x == 0 && y == 0){
                    cout<<answer<<"\n";
                    return 0;
                }
                x += dx[dir]; y += dy[dir];
                if(map[x][y] > 0){
                    answer += spread(x,y,dir);
                }
            }
            dir = (dir+1)%4;
        }
    }


    return 0;
}
