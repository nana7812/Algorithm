#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int w[51][51];
char m[51][51];
int v[51][51];

int main(){
    int R,C;
    cin>> R>>C;

    queue<pair<int,int>> wq;
    int x; int y;
    for(int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> m[i][j];
            w[i][j] = -1;
            if (m[i][j] == '*') {
                wq.push({i, j});
                w[i][j] = 0;
            } else if (m[i][j] == 'S') {
                x = i;
                y = j;
            }
        }
    }
    while(!wq.empty()){
        int qx = wq.front().first;
        int qy = wq.front().second;
        wq.pop();
        for(int i = 0; i < 4; i++){
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            if(0 > nx || nx >= R || 0 > ny || ny >= C ) continue;
            if(m[nx][ny] == '.' && w[nx][ny] == -1){
                w[nx][ny] = w[qx][qy] + 1;
                wq.push({nx,ny});
            }
        }
    }

    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y},0});
    v[x][y] = true;
    int answer = 0;
    while(!q.empty()){
        int qx = q.front().first.first;
        int qy = q.front().first.second;
        int qc = q.front().second;
        q.pop();
        if(m[qx][qy] == 'D'){
            answer = qc;
            break;
        }
        for(int i = 0; i < 4; i++){
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            if(0 > nx || nx >= R || 0 > ny || ny >= C ) continue;
            if(v[nx][ny]) continue;
            if(m[nx][ny] == 'D'){
                q.push({{nx,ny},qc+1});
                v[nx][ny] = true;
            }else if(m[nx][ny] == '.' ){
                if(w[nx][ny] >= 0 && w[nx][ny] <= qc+1) continue;
                q.push({{nx,ny},qc+1});
                v[nx][ny] = true;
            }
        }
    }

    if(answer > 0){
        cout<<answer<<"\n";
    }else{
        cout<<"KAKTUS"<<"\n";
    }


    return 0;
}