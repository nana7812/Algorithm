#include <iostream>
#include <vector>
using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int N, M;
int answer;
vector<vector<int>> map(10,vector<int>(10));
vector<pair<int,pair<int,int>>> camera;
vector<int> d(9);

void cctv(vector<vector<int>> & v, int x, int y, int dir){
    int num = v[x][y];
    int nx, ny;
    while(true){
        nx = x + dx[dir];
        ny = y + dy[dir];
        if(0 > nx || nx >= N || 0 > ny || ny >= M) break;
        if(v[nx][ny] == 6) break;
        v[nx][ny] = num;
        x = nx;
        y = ny;
    }
}

void on(){
    vector<vector<int>> v(map);
    for(int i = 0; i < camera.size(); i++){
        int num = camera[i].first;
        int x = camera[i].second.first;
        int y = camera[i].second.second;
        int dir = d[i];
        if(num == 1){
            cctv(v,x,y,dir);
        }else if(num == 2){
            cctv(v,x,y,dir);
            cctv(v,x,y,(dir+2)%4);
        }else if(num == 3){
            cctv(v,x,y,dir);
            cctv(v,x,y,(dir+1)%4);
        }else if(num == 4){
            cctv(v,x,y,dir);
            cctv(v,x,y,(dir+1)%4);
            cctv(v,x,y,(dir+2)%4);
        }else if(num == 5){
            cctv(v,x,y,dir);
            cctv(v,x,y,(dir+1)%4);
            cctv(v,x,y,(dir+2)%4);
            cctv(v,x,y,(dir+3)%4);
        }
    }

    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(v[i][j] == 0) cnt++;
        }
    }
    if(answer == -1 || answer > cnt){
        answer = cnt;
    }

}


void makeCom(int cnt){ //카메라 마다 방향 정하기!!!!!!!!
    if(cnt >= camera.size()){
        //카메라 회전??
        on();
        return;
    }
    for(int i = 0; i < 4; i++){
        d[cnt] = i;
        makeCom(cnt+1);
    }

}

int main() {

    cin>> N >> M;
    answer = -1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
            if(1 <= map[i][j] && map[i][j] <= 5){
                camera.push_back({map[i][j],{i,j}});
            }
        }
    }

    makeCom(0);
    cout<<answer<<"\n";

    return 0;
}