#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#include<math.h>
using namespace std;

int N,Q;
int a[101][101];
int temp[101][101];
bool check[101][101];
bool visit[101][101];
int dx[]= {-1,1,0,0};
int dy[] = {0,0,-1,1};

void rotate(int x, int y, int d){
    for(int i = 0; i < d; i++){
        for(int j = 0; j < d; j++){
            temp[x+ i][y+j] = a[x+d-1-j][y+i];
        }
    }
}

int bfs(int x, int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    int size = 1;
    visit[x][y] = true;
    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        for(int k = 0; k < 4; k++){
            int nx = qx+ dx[k];
            int ny = qy + dy[k];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(visit[nx][ny]) continue;
            if(a[nx][ny] >= 1){
                q.push({nx,ny});
                visit[nx][ny] = true;
                size++;
            }
        }
    }
    return size;
}

int main(){
    cin>>N>>Q;
    N = pow(2,N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>a[i][j];
        }
    }
    while(Q--){
        int L;
        cin>> L;
        //시계방향 회전
        memset(temp,0,sizeof(temp));
        memset(check,false,sizeof(check));
        int d = pow(2,L);
        for(int i = 0; i < N; i +=d){
            for(int j = 0; j < N; j +=d){
                rotate(i,j,d);
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(temp[i][j] == 0) continue;
                int cnt = 0;
                for(int k = 0; k < 4; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                    if(temp[nx][ny] > 0){
                        cnt++;
                    }
                }
                if(cnt < 3){
                    check[i][j] = true;
                }
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(check[i][j]){
                    temp[i][j]--;
                }
            }
        }
        memcpy(a,temp,sizeof(temp));
    }


    int sum = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(a[i][j] > 0){
                sum+=a[i][j];
            }
        }
    }
    int big = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(a[i][j] == 0) continue;
            if(!visit[i][j]){
                int size = bfs(i,j);
                if(size > big){
                    big = size;
                }
            }
        }
    }
    cout<<sum<<"\n";
    cout<<big<<"\n";

    return 0;
}