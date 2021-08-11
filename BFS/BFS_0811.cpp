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
string a[51][51];
int d[51][51];
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
int n,m;

string change(int num){
    string str = "0000";
    int cnt = 0;
    while(num != 0){
        str[cnt] = (num%2) + '0';
        num =num/2;
        cnt++;
    }
    return str;
}

int bfs(int x, int y,int n){
    queue<pair<int,int>> q;
    q.push({x,y});
    d[x][y] = n;
    int sum = 1;
    while (!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            string s = a[qx][qy];
            if(s[i] == '0'){
                int nx = qx + dx[i];
                int ny = qy + dy[i];
                if(d[nx][ny] == -1){
                    d[nx][ny] = n;
                    q.push({nx,ny});
                    sum++;
                }
            }
        }
    }
    return sum;
}

int main() {
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int num;
            cin>>num;
            string s = change(num);
            a[i][j] = s;
        }
    }

    memset(d,-1,sizeof(d));
    int total = 0; int size = 0;
    vector<int> room(n*m);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(d[i][j] == -1){
                total++;
                room[total]=bfs(i,j,total);
                if(room[total] > size) size = room[total];
            }
        }
    }

    cout<<total<<"\n"<<size<<"\n";
    int widen = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < 4; k++){
                string s = a[i][j];
                if(s[k] == '1'){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                    if(d[i][j] == d[nx][ny])continue;
                    if(widen < room[d[i][j]] + room[d[nx][ny]])
                        widen = room[d[i][j]] + room[d[nx][ny]];
                }
            }
        }
    }
    cout<<widen<<"\n";
    return 0;
}