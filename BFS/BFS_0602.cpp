#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace  std;

int R,C;
int startX,startY,endX,endY;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
char m[51][51];
int wDay[51][51];
int c[51][51];
queue<pair<int,int>> waterQ;

void water(){
    while (!waterQ.empty()){
        int qx = waterQ.front().first;
        int qy = waterQ.front().second;
        waterQ.pop();
        for(int i = 0; i < 4; i++){
            int nx = qx + dx[i];
            int ny = qy + dy[i];

            if(0 > nx || nx >= R || 0 > ny || ny >= C) continue;

            if(wDay[nx][ny] == 0 && m[nx][ny] == '.'){
                waterQ.push({nx,ny});
                wDay[nx][ny] = wDay[qx][qy] + 1;
            }
        }
    }

}


void bfs(){
    queue<pair<int,int>> q;
    q.push({startX,startY});
    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = qx + dx[i];
            int ny = qy + dy[i];

            if(0 > nx || nx >= R || 0 > ny || ny >= C) continue;
            if(c[nx][ny] == 0 && (m[nx][ny] == '.'|| m[nx][ny] == 'D')){
                if(wDay[nx][ny] == 0){
                    c[nx][ny] = c[qx][qy] + 1;
                    q.push(make_pair(nx,ny));
                }else{
                    if(wDay[nx][ny] > c[qx][qy] + 1){
                        c[nx][ny] = c[qx][qy] + 1;
                        q.push(make_pair(nx,ny));
                    }
                }
            }
        }
    }
}

int main() {

  cin >> R>>C;
  for(int i = 0; i < R; i++){
      for(int j = 0; j < C; j++){
         cin>>m[i][j];
          if(m[i][j] == 'D'){
              endX = i;
              endY = j;
          }
          else if(m[i][j] == 'S'){
              startX = i;
              startY = j;
          }
          else if(m[i][j] == '*'){
              waterQ.push({i,j});
          }
      }
  }

  water();
  bfs();



  if(c[endX][endY] != 0){
      cout<<c[endX][endY]<<"\n";
  }else{
      cout<<"KAKTUS"<<"\n";
  }


  return 0;
}