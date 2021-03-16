#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace  std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int N, L,R;
int a[51][51];
bool v[51][51];


int main() {

   cin>> N>>L>>R;
   for(int i = 0; i <N; i++){
       for(int j = 0; j < N; j++){
           cin>>a[i][j];
       }
   }



   while(/*종료 상황이 아니라면*/){
       queue<pair<int,int>> q;
       int g = 0; //그룹 사이즈 _pair 해야 그룹 사이즈뿐만 아니라 끝나고 값 나눠서 채워넣기 할 수 있음!!_바꾸
    for(int i = 0; i <N; i++){
        for(int j = 0; j <N; j++){
            if(v[i][j] == true) continue;
            int s = a[i][j];
            q.push(make_pair(i,j));
            v[i][j] = true;
            g++;
            while(!q.empty()){
                int qx = q.front().first;
                int qy = q.front().second;
                q.pop();
                int qv = a[qx][qy];
                for(int i = 0; i < 4; i++){
                    int nx = qx + dx[i];
                    int ny = qx +dy[i];
                    if(0<= nx && nx < N && 0<= ny && ny < N){
                        if(v[nx][ny] == false && L <= (qv-a[nx][ny]) && (qv-a[nx][ny]) <= R){
                            q.push(make_pair(nx,ny));
                            v[nx][ny] = true;
                            s += a[nx][ny];
                            g++;
                        }
                    }
                }
            }
  

    return 0;
}
