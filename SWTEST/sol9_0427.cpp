#include <iostream>
using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

int ndx[4][10] = {{-1,1,-2,2,0,-1,1,-1,1,0},
                  {-1,-1,0,0,2,0,0,1,1,1},
                  {-1,1,-2,2,0,-1,1,-1,1,0},
                  {1,1,0,0,-2,0,0,-1,-1,-1}};
int ndy[4][10] = {{1,1,0,0,-2,0,0,-1,-1,-1},
                  {-1,1,-2,2,0,-1,1,-1,1,0},
                  {-1,-1,0,0,2,0,0,1,1,1},
                  {-1,1,-2,2,0,-1,1,-1,1,0}};
int per[] = {1,1,2,2,5,7,7,10,10};

int N;
int map[510][510];

int main() {

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>map[i][j];
        }
    }

    int answer = 0;
    int x = N/2, y = N/2, dir = 0;
    bool flag = false;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < i; k++){
                x += dx[dir];
                y += dy[dir];
                //
                int res = map[x][y];
                for(int d = 0; d < 9; d++){
                    int spread = (map[x][y] * per[d]) / 100;
                    int nx = x + ndx[dir][d];
                    int ny = y + ndy[dir][d];
                    if(nx < 0 || ny < 0 || nx >= N || ny >= N){
                        answer += spread;
                    }else{
                        map[nx][ny] += spread;
                    }
                    res -= spread;
                }
                //a
                int nx = x + ndx[dir][9];
                int ny = y + ndy[dir][9];
                if(nx < 0 || ny < 0 || nx >= N || ny >= N){
                    answer += res;
                }else{
                    map[nx][ny] += res;
                }
                map[x][y] = 0;
                //
                if(x == 0 && y == 0){
                    flag = true;
                    break;
                }
            }
            dir = (dir+1)%4;
            if(flag) break;
        }
        if(flag) break;
    }


    cout<<answer<<"\n";

    return 0;
}
