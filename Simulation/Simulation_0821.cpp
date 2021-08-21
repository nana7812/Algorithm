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
#include <array>
using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int R,C,T;
int a[51][51];
int e1,e2;
queue<pair<pair<int,int>,int>> q;


void spread(){
    while(!q.empty()){
            int qx = q.front().first.first;
            int qy = q.front().first.second;
            int dust = q.front().second;
            q.pop();
            int cnt = 0; int v = dust/5;
            for(int i = 0; i < 4; i++){
                int nx = qx + dx[i];
                int ny = qy + dy[i];
                if(nx <0 || nx >= R || ny < 0 || ny >= C) continue;
                if(a[nx][ny] == -1) continue;
                a[nx][ny] += v;
                cnt++;
            }
            a[qx][qy] -= v*cnt;
        }
}

void on(){
    //위쪽(반시계)
        int temp1 = a[e1][C-1];
        for(int i = C-1; i >=2; i--){
           a[e1][i] = a[e1][i-1];
        }
        a[e1][1] = 0;

        int temp2 = a[0][C-1];
        for(int i = 0; i <= e1-1; i++){
            a[i][C-1] = a[i+1][C-1];
        }
        a[e1-1][C-1] = temp1;

       int temp3 = a[0][0];
       for(int i = 0; i <C-2; i++){
           a[0][i] = a[0][i+1];
       }
       a[0][C-2] = temp2;

       for(int i = e1-1; i > 1; i--){
           a[i][0] = a[i-1][0];
       }
       a[1][0] = temp3;
        //시계(아래쪽)
        temp1 = a[e2][C-1];
        for(int i = C-1; i >=2; i--){
            a[e2][i] = a[e2][i-1];
        }
        a[e2][1] = 0;
        temp2 = a[R-1][C-1];
        for(int i = R-1; i >=e2+2; i--){
            a[i][C-1] = a[i-1][C-1];
        }
        a[e2+1][C-1] = temp1;
        temp3 = a[R-1][0];
        for(int i = 0; i <C-2; i++){
            a[R-1][i] = a[R-1][i+1];
        }
        a[R-1][C-2] =temp2;
        for(int i = e2+1; i <R-2 ; i++){
            a[i][0] = a[i+1][0];
        }
        a[R-2][0] = temp3;
}

int main(){
    //입력
    cin>> R>>C>>T;
    e1 = -1; e2 = -1;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin>>a[i][j];
            if(a[i][j] == -1){
                if(e1 == -1){
                    e1 = i;
                }else{
                    e2 = i;
                }
            }else if(a[i][j] != 0){
                q.push({{i,j},a[i][j]});
            }
        }
    }

    while(T--){
        //미세먼지 확산
        spread();
        
        //공기청정기 가동
         on();
        
        //다음T에서 확산될 미세먼지 push
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(a[i][j] == 0 || a[i][j] == -1) continue;
                q.push({{i,j},a[i][j]});
            }
        }

    }

    //정답계산
    int answer = 0;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(a[i][j] == 0 || a[i][j] == -1) continue;
            answer += a[i][j];
        }
    }
    cout<<answer<<"\n";
    return 0;
}