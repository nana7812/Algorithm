#include <iostream>

using namespace std;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int a[55][55];


int main() {
    int N, M;
    cin>> N>> M;
    int x, y,dir;
    cin>>x>>y>>dir;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>a[i][j];
        }
    }

    while(true){
        if(a[x][y] == 0){
            a[x][y] = 2;
        }
        if(a[x-1][y] != 0 && a[x+1][y] != 0 && a[x][y-1] != 0 && a[x][y+1] != 0){
            if(a[x-dx[dir]][y-dy[dir]] == 1) {
                break;
            }else{
                x -= dx[dir];
                y -= dy[dir];
            }
        }else{
            dir = (dir+3)%4;
            if(a[x+dx[dir]][y+dy[dir]] == 0){
                x += dx[dir];
                y += dy[dir];
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(a[i][j] == 2) {
                cnt += 1;
            }
        }
    }
    cout<<cnt;
    return 0;
}