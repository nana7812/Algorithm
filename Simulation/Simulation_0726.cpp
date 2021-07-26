#include <iostream>
#include <stdlib.h>
//#include <map>
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

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int a[20][20];
int dice[7] = {0,0,0,0,0,0,0};
int N,M,x,y,K;

int main() {
    cin>> N>> M>>x>>y>>K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>a[i][j];
        }
    }
    while(K--){
        int k;
        cin>>k;
        int nx = x + dx[k-1];
        int ny = y + dy[k-1];

        if(0> nx  || nx >= N || 0 > ny  || ny >= M) continue;

        if(k == 1){
            int temp = dice[1];
            dice[1] = dice[4];
            dice[4] = dice[6];
            dice[6] = dice[3];
            dice[3] = temp;
        }else if(k == 2){
            int temp = dice[1];
            dice[1] = dice[3];
            dice[3] = dice[6];
            dice[6] = dice[4];
            dice[4] = temp;
        }else if(k == 3){
            int temp = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[6];
            dice[6] = dice[2];
            dice[2] = temp;
        }else if(k == 4){
            int temp = dice[1];
            dice[1] = dice[2];
            dice[2] = dice[6];
            dice[6] = dice[5];
            dice[5] = temp;
        }
         x= nx;
         y = ny;
         if(a[x][y] == 0){
             a[x][y] = dice[6];
         }else{
             dice[6] = a[x][y];
             a[x][y] = 0;
         }

         cout<<dice[1]<<"  ";
    }

    return 0;
}