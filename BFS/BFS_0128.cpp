#include <iostream>
#include <algorithm>
#include <queue>
using  namespace  std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int m, n;
int tomato[1001][1001];
int day[1001][1001];
queue<pair<int, int>> q;

void bfs(){
    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        for(int k =0; k < 4; k++){
            int nx = qx + dx[k];
            int ny = qy + dy[k];
            if(0<=nx && nx < n && 0 <= ny && ny < m){
                if(tomato[nx][ny] == 0 & day[nx][ny] == -1){
                    q.push(make_pair(nx,ny));
                    day[nx][ny] = day[qx][qy] + 1;
                }
            }
        }
    }
}

int main(){

    cin>> m>> n;
    for(int i =0; i <n; i++){
        for(int j = 0; j < m; j++){
            cin>>tomato[i][j];
            day[i][j] = -1;
            if(tomato[i][j] == 1){
                day[i][j] = 0;
                q.push(make_pair(i,j));
            }
        }
    }

    bfs();

    int ans = 0; bool no= false;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(ans < day[i][j]){
                ans = day[i][j];
            }
            if(tomato[i][j] == 0 && day[i][j] == -1){
               no = true;
            }
        }
    }

    if(no == false){
        cout<<ans;
    }else{
        cout<<-1;
    }
    return 0;
}