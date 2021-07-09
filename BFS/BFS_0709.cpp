#include <iostream>
#include <stdlib.h>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <cstring>
#include <stack>

using namespace  std;

int dx[] = {-1,1,0,0};
int dy[] ={0,0,-1,1};
int w,h;
char a[100][100];
int mirror[100][100];
bool check[100][100];
pair<int,int> s,e;

int BFS(int x, int y){
    queue<pair<pair<int,int>,pair<int,int>>> q;
    for(int i = 0; i < 4; i++){
        q.push({{x,y},{i,0}});
    }
    check[x][y] = true;
    while(!q.empty()){
        int qx = q.front().first.first;
        int qy = q.front().first.second;
        int dir = q.front().second.first;
        int mir = q.front().second.second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            int nmir = mir;

            if(nx < 0 || ny < 0 || nx >=h || ny >=w) continue;
            if(a[nx][ny] == '*') continue;
            if(dir != i) nmir = nmir + 1;
            if(mirror[nx][ny] >= nmir){
                mirror[nx][ny] = nmir;
                q.push({{nx,ny},{i,nmir}});
            }
        }
    }
    return mirror[e.first][e.second];
}

int main() {
    int t = 0;
    cin>> w>> h;
    for(int i = 0; i < h; i++){
        for(int j = 0 ; j < w; j++){
            cin>> a[i][j];
            if(a[i][j] == 'C') {
                if (t == 0) {
                    s.first = i;
                    s.second = j;
                    t++;
                } else {
                    e.first = i;
                    e.second = j;
                }
            }
            mirror[i][j] = 987654321;
        }
    }

    int ans = BFS(s.first,s.second);
    cout<<ans;


    return 0;
}