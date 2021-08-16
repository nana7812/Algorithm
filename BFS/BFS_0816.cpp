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
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int R,C;
char a[1501][1501];
bool wCheck[1501][1501];
bool sCheck[1501][1501];
int main() {
    cin>> R>>C;
    int L1x,L1y, L2x,L2y;
    L1x = L1y = L2x = L2y = -1;
    queue<pair<int,int>> swan,nswan,water,nwater;
    for(int i = 0; i <R; i++){
        for(int j = 0; j < C; j++){
            cin >>a[i][j];
             if(a[i][j] == 'L'){
                if(L1x == -1){
                L1x = i;
                L1y = j;
                }else{
                    L2x = i;
                    L2y = j;
                }
               a[i][j] = '.';
            }
            if(a[i][j] == '.'){
                water.push({i,j});
                wCheck[i][j] = true;
            }
         
        }
    }

    int time = 0;
    swan.push({L1x,L1y});
    sCheck[L1x][L1y] = true;
    while(true) {
        while (!water.empty()) {
            int qx = water.front().first;
            int qy = water.front().second;
            water.pop();
            a[qx][qy] = '.';
            for (int k = 0; k < 4; k++) {
                int nx = qx + dx[k];
                int ny = qy + dy[k];
                if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if (wCheck[nx][ny] == false) {
                    if(a[nx][ny] == '.'){ //백조자리 때문
                        water.push({nx,ny});
                        wCheck[nx][ny] = true;
                    }else{
                        nwater.push({nx, ny});
                        wCheck[nx][ny] = true;
                    }
                }
            }
        }
        while (!swan.empty()) {
            int Lx = swan.front().first;
            int Ly = swan.front().second;
            swan.pop();
            for (int k = 0; k < 4; k++) {
                int nx = Lx + dx[k];
                int ny = Ly + dy[k];
                if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if (sCheck[nx][ny] == false) {
                    if(a[nx][ny] == '.') {
                        swan.push({nx,ny});
                        sCheck[nx][ny] = true;
                    }else{
                        nswan.push({nx, ny});
                        sCheck[nx][ny] = true;
                    }
                }
            }
        }
        if(sCheck[L2x][L2y]){
            cout<<time<<"\n";
            break;
        }
        water = nwater;
        swan = nswan;
        nwater = queue<pair<int,int>>();
        nswan = queue<pair<int,int>>();
        time++;
    }
    return 0;
}