#include <iostream>
#include <vector>
using namespace std;


int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,-1,-1,-1,0,1,1,1};


int answer = 0;
struct Fish{
    int r;
    int c;
    int dir;
    bool live;
};

void go(vector<vector<int>> v, Fish *fish, int sx, int sy, int sd, int eat){

    vector<vector<int>> vv = v;
    Fish nfish[17];
    for(int i = 1; i <= 16; i++){
        nfish[i] = fish[i];
    }

    //먹기
    if(vv[sx][sy] > 0){
        int n = vv[sx][sy];
        eat += n;
        if(eat > answer) answer = eat; //
        vv[sx][sy] = 0;
        sd = nfish[n].dir;
        nfish[n].live = false;
    }

    //물고기 이동
    for(int i = 1; i <= 16; i++){
        if(!nfish[i].live) continue;
        int x = nfish[i].r;
        int y = nfish[i].c;
        int dir = nfish[i].dir;
        for(int d = 0; d < 8; d++){
            int nx = x + dx[(dir+d)%8];
            int ny = y + dy[(dir+d)%8];
            if(0> nx || nx >= 4 || 0 > ny || ny >= 4) continue;
            if(nx == sx && ny == sy) continue;
            nfish[i].dir = (dir+d)%8;
            if(vv[nx][ny] == 0){ //빈칸
                vv[x][y] = 0;
                vv[nx][ny] = i;
                nfish[i].r = nx;
                nfish[i].c = ny;
            }else{ //물고기 있음
                int temp = vv[nx][ny];
                vv[nx][ny] = i;
                nfish[i].r = nx;
                nfish[i].c = ny;
                vv[x][y] = temp;
                nfish[temp].r = x;
                nfish[temp].c = y;
            }
            break;
        }
    }
    
    //상어이동
    while(0 <= sx+ dx[sd] && sx+ dx[sd] < 4 && 0 <= sy+ dy[sd] && sy+ dy[sd] < 4){
        sx += dx[sd];
        sy += dy[sd];
        if(vv[sx][sy] > 0){
            go(vv,nfish,sx,sy,sd,eat);
        }
    }

}

int main() {

    vector<vector<int>> map(4,vector<int>(4,0));
    Fish fish[17];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int a, b;
            cin>> a>> b;
            fish[a].r = i;
            fish[a].c = j;
            fish[a].dir = b-1;
            fish[a].live = true;
            map[i][j] = a;
        }
    }

    int sx,sy,sd;
    sx = sy = sd = 0;
    go(map,fish,sx,sy,sd,0);
    cout<<answer<<"\n";

    return 0;
}