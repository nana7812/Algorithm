#include <iostream>
#include <stdlib.h>
#include <map>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <cstring>
#include <stack>
#include <sstream>

using namespace std;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
char a[251][251];
bool check[251][251];
int R,C;

int o = 0; int v = 0;
void bfs(int x, int y){
    int to = 0; int tv = 0;
    queue<pair<int,int>> q;
    q.push({x,y});
    check[x][y] = true;
    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        if(a[qx][qy] == 'v'){
            tv++;
        }else if(a[qx][qy] == 'o'){
            to++;
        }
        for(int k = 0; k < 4; k++){
            int nx = qx+ dx[k];
            int ny = qy + dy[k];
            if(0<=nx && nx < R && 0 <= ny && ny <C){
                if(check[nx][ny] == false && a[nx][ny] != '#'){
                    q.push({nx,ny});
                    check[nx][ny] = true;
                }
            }
        }
    }
    if(to > tv){
        o += to;
    }else{
        v += tv;
    }

}

int main() {
    cin>> R>>C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin>>a[i][j];
        }
    }

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(check[i][j] == false){
                bfs(i,j);
            }
        }
    }

    cout<<o<<" "<<v;

    return 0;
}