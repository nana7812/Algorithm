#include <iostream>
#include <vector>

using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

struct Horse{
    int x;
    int y;
    int dir;
};

int N, K;
int color[13][13];
vector<int> map[13][13];
vector<Horse> horse;

int changeDir(int d){
    if(d == 0) return 1;
    if(d == 1) return 0;
    if(d == 2) return 3;
    if(d == 3) return 2;
}


int findIdx(int num, int x, int y){
    for(int i = 0; i < map[x][y].size(); i++){
        if(map[x][y][i] == num){
            return i;
        }
    }
}

void move(int num, int x, int y, int nx, int ny, int c){
    if(c == 0){
        int idx = findIdx(num,x,y);
        int cnt = 0;
        for(int k = idx; k < map[x][y].size(); k++){
            map[nx][ny].push_back(map[x][y][k]);
            horse[map[x][y][k]].x = nx;
            horse[map[x][y][k]].y = ny;
            cnt++;
        }
        while(cnt--){
            map[x][y].pop_back();
        }

    }else if(c ==  1){
        int idx = findIdx(num,x,y);
        int cnt = 0;
        for(int k = map[x][y].size()-1; k >= idx; k--){
            map[nx][ny].push_back(map[x][y][k]);
            horse[map[x][y][k]].x = nx;
            horse[map[x][y][k]].y = ny;
            cnt++;
        }
        while(cnt--){
            map[x][y].pop_back();
        }

    }else if(c == 2){
        horse[num].dir = changeDir(horse[num].dir);
        int nnx = x + dx[horse[num].dir];
        int nny = y + dy[horse[num].dir];
        if(0 <= nnx && nnx < N && 0 <= nny && nny < N){
            if(color[nnx][nny] != 2){
                move(num,x,y,nnx,nny,color[nnx][nny]);
            }
        }

    }
}

bool check(){
    for(int k = 0; k < K; k++){
        int x = horse[k].x;
        int y = horse[k].y;
        if(map[x][y].size() >= 4){
            return true;
        }
    }
    return false;
}


int main() {

    cin>> N >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>color[i][j];
        }
    }
    for(int i = 0; i < K; i++){
        int x,y,d;
        cin>>x>>y>>d;
        horse.push_back({x-1,y-1,d-1});
        map[x-1][y-1].push_back(i);
    }

    int turn = 0;
    while(true){
        turn++;
        if(turn > 1000){
            turn = -1;
            break;
        }

        bool end = false;
        for(int i = 0; i < K; i++){
            int x = horse[i].x;
            int y = horse[i].y;
            int nx = x + dx[horse[i].dir];
            int ny = y + dy[horse[i].dir];
            if(0 <= nx && nx < N && 0 <= ny && ny < N){
                move(i,x,y,nx,ny,color[nx][ny]);
            }else{
                move(i,x,y,nx,ny,2);
            }

            if(map[horse[i].x][horse[i].y].size() >= 4){
                end = true;
                break;
            }
        }

        if(end) break;

    }

    cout<<turn<<"\n";

    return 0;
}