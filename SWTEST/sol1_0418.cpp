#include <iostream>
#include <queue>
#include <math.h>
#include <cstring>

using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};


int N,Q,L;
int a[65][65];
int temp[65][65];
bool check[65][65];
bool visit[65][65];
int ans1,ans2;

int bfs(int x, int y){
    int cnt = 1; 
    visit[x][y] = true;
    queue<pair<int,int>> q;
    q.push({x,y});

    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            if(0 > nx || nx >= N || 0 > ny || ny >= N) continue;
            if(visit[nx][ny] || a[nx][ny] == 0) continue;
            q.push({nx,ny});
            visit[nx][ny] = true;
            cnt++;
        }
    }
    return cnt;
}

void rotate(int r,int c){
    int l = pow(2,L);
    for(int i = 0; i <l; i++){
        for(int j = 0; j < l; j++){
            temp[r+i][c+j] = a[r+l-1-j][c+i];
        }
    }
}

int main() {

    //입력
    cin >> N>> Q;
    N = pow(2,N);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>a[i][j];
        }
    }

    while(Q--){
        memset(temp,0,sizeof(temp));
        memset(check,false,sizeof(check)); //얼음 줄일지 확인하는 bool
        cin>>L;

        //회전
        int l = pow(2,L);
        for(int i = 0; i < N; i+=l){
            for(int j = 0; j < N; j+=l){
                rotate(i,j);
            }
        }

        //얼음 줄일 칸 확인
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(temp[i][j] == 0) continue;
                int cnt = 0;
                for(int k = 0; k < 4; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(0 > nx || nx >= N || 0 > ny || ny >= N) continue;
                    if(temp[nx][ny] > 0)cnt++;
                }
                if(cnt < 3) check[i][j] = true;
            }
        }


        //얼음 줄이기
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(check[i][j]){
                    temp[i][j]--;
                }
            }
        }

        //원래 배열에 넣기
        memcpy(a,temp,sizeof(temp));

    }

    ans1 = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(a[i][j] == 0) continue;
            ans1 += a[i][j];
        }
    }
    
    ans2 = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(visit[i][j]|| a[i][j] == 0) continue;
            int size = bfs(i,j);
            if(size > ans2){
                ans2 = size;
            }
        }
    }
    cout<<ans1<<"\n";
    cout<<ans2<<"\n";



    return 0;
}