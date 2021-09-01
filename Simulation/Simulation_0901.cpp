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


int dx[] = {0,0,0,-1,1};
int dy[] = {0,1,-1,0,0};
struct Chess{
    int x;
    int y;
    int dir;
};
int N,K;
int color[13][13];
Chess chess[11];
vector<int> m[13][13];
int changeDir(int num){
    int n = chess[num].dir;
    if(n == 1) return 2;
    else if(n == 2) return 1;
    else if(n == 3) return 4;
    else if(n == 4) return 3;
}

int FindDel(int x, int y, int chessNum){
    int cnt = 0;
    for(int i = m[x][y].size() -1 ; i >= 0; i--){
        if(m[x][y][i] == chessNum) break;
        cnt++;
    }
    return cnt +1;
}
void move(int x, int y,int nx, int ny, int chessNum,int pos,int c){
    if(c== 0){
        int del =0;
        for(int i = pos; i < m[x][y].size(); i++){
            m[nx][ny].push_back(m[x][y][i]);
            int temp = m[x][y][i];
            chess[temp].x = nx;
            chess[temp].y = ny;
            del++;
        }
        while(del--){
            m[x][y].pop_back();
        }
    }else if(c== 1){
        int del = 0;
        for(int i = m[x][y].size() -1; i >= pos; i--){
            m[nx][ny].push_back(m[x][y][i]);
            int temp = m[x][y][i];
            chess[temp].x = nx;
            chess[temp].y = ny;
            del++;
        }
        while(del--){
            m[x][y].pop_back();
        }
    }else if(c == 2 ){
        int nD = changeDir(chessNum);
        chess[chessNum].dir = nD;
        int nnx = x + dx[nD];
        int nny = y + dy[nD];
        if(nnx >= 0 && nny >= 0 && nnx < N && nny < N){
            if(color[nnx][nny] != 2){
                move(x,y,nnx,nny,chessNum,pos,color[nnx][nny]);
            }
        }
    }
}
int FindPos(int x, int y, int idx){
    for(int j = 0; j < m[x][y].size(); j++){
        if(m[x][y][j] == idx){
            return j;
        }
    }
}
bool check() {
    for (int j = 0; j < K; j++) {
        int x = chess[j].x;
        int y = chess[j].y;
        if (m[x][y].size() >= 4) {
            return true;
        }
    }
    return false;
}
    int main() {
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> color[i][j];
            }
        }
        for (int i = 0; i < K; i++) {
            int x, y,d;
            cin >> x >> y >> d;
            x--;
            y--;
            chess[i] = {x, y, d};
            m[x][y].push_back(i);
        }
        bool flag = false;
        int turn = 0;
        while (true) {
            if (turn > 1000) break;
            for (int i = 0; i < K; i++) {
                int x = chess[i].x;
                int y = chess[i].y;
                int d = chess[i].dir;
                //m[x][y] 몇번째 위
                int pos = FindPos(x, y, i);
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    move(x, y, nx, ny, i, pos, color[nx][ny]);
                } else {
                    move(x, y, nx, ny, i, pos, 2);
                }
                if (check() == true){
                    flag = true;
                    break;
                }
            }
            if (flag) break;
            turn++;
        }
        if (flag) {
            cout << turn+1 << "\n";
        } else {
            cout << -1 << "\n";
        }
        return 0;
    }