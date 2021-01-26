#include <iostream>
#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using  namespace  std;
const int MAX = 101;
int num[MAX][MAX];
bool check[MAX][MAX];
int dx[4]={0,0,-1,1};
int dy[4] ={-1,1,0,0};
int n, m;

void bfs(int x, int y){
    queue<pair<int,int>> q;
    q.push(make_pair(x,y)); check[x][y] = true; num[x][y] = 1;
    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        for(int i = 0; i <4; i++){
            int nx = qx+dx[i];
            int ny = qy +dy[i];
            if(0<=nx && nx <n && 0 <=ny && ny <m ){
                if(num[nx][ny] == 1 && check[nx][ny] == false){
                    q.push(make_pair(nx,ny));
                    num[nx][ny] = num[qx][qy]+1;
                    check[nx][ny] = true;
                }
            }
        }
    }
}

int main(){
    cin>> n>> m;

    string temp;
    for(int i  = 0; i < n; i++){
        cin>> temp;
        for(int j = 0; j < m; j++){
            num[i][j]= temp[j]-'0';
        }
    }
    bfs(0,0);
    cout<<num[n-1][m-1];
    
    return 0;
}