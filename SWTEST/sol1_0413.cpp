#include <iostream>
#include <vector>

using namespace std;


int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,-1,-1,-1,0,1,1,1};

struct Fish{
    int x;
    int y;
    int dir;
    bool live;
};

int answer = 0;


void simul(vector<vector<int>> map,Fish *f, int sx, int sy, int sum){

    Fish fish[17];
    for(int i = 1; i <= 16; i++){
        fish[i] = f[i];
    }

    sum += map[sx][sy];
    if(sum > answer) answer = sum;
    int sd = fish[map[sx][sy]].dir;
    fish[map[sx][sy]].live = false;
    map[sx][sy] = 0;

    for(int i = 1; i <= 16; i++){
        if(!fish[i].live) continue;
        int x = fish[i].x;
        int y = fish[i].y;
        int dir = fish[i].dir;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        while((0> nx || nx >= 4 || 0 > ny || ny >= 4)||(nx == sx && ny == sy)){
            dir++;
            nx = x + dx[dir%8];
            ny = y + dy[dir%8];
        }

        fish[i].dir = dir%8;

        if(map[nx][ny] == 0){ //빈칸
            map[x][y] = 0;
            map[nx][ny] = i;
            fish[i].x = nx;
            fish[i].y = ny;
        }else{ //물고기 있음
            int temp = map[nx][ny];
            map[nx][ny] = i;
            fish[i].x = nx;
            fish[i].y = ny;
            map[x][y] = temp;
            fish[temp].x = x;
            fish[temp].y = y;
        }

    }

    while(0 <= sx+dx[sd] && sx + dx[sd] < 4 && 0 <= sy+dy[sd] && sy + dy[sd] < 4){
         sx += dx[sd];
         sy += dy[sd];
         if(map[sx][sy] > 0){
             simul(map,fish,sx,sy,sum);
         }
    }


}



int main() {

    int sx, sy;
    vector<vector<int>> map(4,vector<int>(4,0));
    Fish fish[17];

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int a,b;
            cin>> a>> b;
            fish[a].x = i; fish[a].y = j; fish[a].dir = b-1; fish[a].live = true;
            map[i][j] = a;
        }
    }

    sx = sy = 0;
    simul(map,fish,sx,sy,0);

    cout<<answer<<"\n";

    return 0;
}