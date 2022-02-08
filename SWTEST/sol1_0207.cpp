#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include<sstream>
#include <map>
#include <list>

using namespace std;

int T, N, M,K;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int a[25][25];
int dice[6] = {6,1,4,3,2,5};

void rollDice(int dir){
    if(dir == 0){
        int temp = dice[0];
        dice[0] = dice[3];
        dice[3] = dice[1];
        dice[1] = dice[2];
        dice[2] = temp;
    }else if(dir == 1){
        int temp = dice[0];
        dice[0] = dice[5];
        dice[5] = dice[1];
        dice[1] = dice[4];
        dice[4] = temp;
    }else if (dir == 2){
        int temp = dice[0];
        dice[0] = dice[2];
        dice[2] = dice[1];
        dice[1] = dice[3];
        dice[3] = temp;
    }else{
      int temp = dice[0];
      dice[0] = dice[4];
      dice[4] = dice[1];
      dice[1] = dice[5];
      dice[5] = temp;
    }
}


int score(int x, int y){
    vector<vector<bool>> c(N,vector<bool>(M,false));
    int count = 1;
    c[x][y] = true;
    int val = a[x][y];
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = qx+ dx[i];
            int ny = qy + dy[i];
            if(0> nx || nx >= N || 0 > ny || ny >= M) continue;
            if(c[nx][ny]) continue;
            if(val == a[nx][ny]){
                q.push({nx,ny});
                c[nx][ny] = true;
                count++;
            }
        }
    }

    return a[x][y] * count;
}

int main(){
  cin>> T;
  while(T--){
      cin>>N>> M>>K;
      for(int i = 0; i < N; i++){
          for(int j = 0; j <M; j++){
              cin>>a[i][j];
          }
      }
      int answer = 0; //점수
      int x = 0; int y = 0; int dir = 0;//주사위(0,0)위치 ,초기 방향 - 동쪽 0
      while(K--){
          //(1)주사위 이동
          int nx = x + dx[dir];
          int ny = y + dy[dir];
          //이동하는 위치가 범위를 넘어가는 지 확인
          if(0> nx || nx >= N || 0 > ny || ny >= M){
              dir = (dir+2)%4;
              nx = x + dx[dir];
              ny = y + dy[dir];
          }
          //주사위 이동 위치 확정
          rollDice(dir);
          x = nx; y = ny;
          //cout<<x<<" "<<y<<": ";

          //(2)점수를 획득;
          answer += score(x,y);
          //cout<<"\n";

          //(3)주사위 방향 선택
          if(dice[0] > a[x][y]){
             dir = (dir + 1)%4;
          }else if(dice[0] < a[x][y]){
              dir = (dir + 3) % 4;
          }
      }
     cout<<answer<<" ";
  }

}