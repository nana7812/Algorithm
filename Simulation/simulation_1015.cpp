#include<iostream>
using namespace std;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int a[55][55];
int N,M;
int x,y,dir;

int main(){
    int T;
    cin>>T;
    while(T--){
        cin>> N>> M;
        cin>>x>>y>>dir;
        //x--;y--;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin>>a[i][j];
            }
        }
        while(true){
            //1번
            if(a[x][y] == 0){
                a[x][y] = 2;
            }
            //왼쪽방향
            int nx = x + dx[(dir+3)%4];
            int ny = y + dy[(dir+3)%4];
            //2-a
            if(a[nx][ny] == 0){
                a[nx][ny] =2;
                x = nx;
                y = ny;
                dir = (dir+3)%4;
                continue;
            }else{
                if(a[x-1][y] != 0 && a[x+1][y] != 0 && a[x][y-1] != 0 && a[x][y+1] != 0){
                    //3-d
                    if(a[x-dx[dir]][y-dy[dir]] == 1){
                        break;
                    }else{
                        //3-c
                        x -= dx[dir];
                        y -= dy[dir];
                        continue;
                    }
                }
                //2-b
                dir = (dir+3)%4;
            }
        }
        int answer = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(a[i][j] ==2){
                    answer++;
                }
            }
        }
        cout<<answer<<"\n";
    }
    return 0;
}