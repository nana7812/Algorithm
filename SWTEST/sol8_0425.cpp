#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int N, M;
int map[55][55];


int main() {

    cin>> N>> M;
    int x,y,d;
    cin>>x>>y>>d;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>map[i][j];
        }
    }

    int answer = 0;
    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y},d});
    while(!q.empty()){
        int qx = q.front().first.first;
        int qy = q.front().first.second;
        int qd = q.front().second;
        if(map[qx][qy] == 0){
            answer++;
            map[qx][qy] = 2;
        }
        q.pop(); bool flag = false;
        for(int i = 0; i < 4; i++){
            qd = (qd + 3) % 4;
            int nx = qx + dx[qd];
            int ny = qy + dy[qd];
            if(map[nx][ny] == 0){
                q.push({{nx,ny},qd});
                flag = true;
                break;
            }
        }

        if(!flag) {
            if (map[qx - dx[qd]][qy - dy[qd]] == 1) {
                break;
            } else {
                q.push({{qx - dx[qd], qy - dy[qd]}, qd});
            }
        }

    }

    cout<<answer<<"\n";


    return 0;
}