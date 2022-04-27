#include <iostream>
#include <vector>
using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

int N, K;
int answer;
int map[15][15];
vector<int> horse[15][15];
struct Horse{
    int r;
    int c;
    int dir;
};
vector<Horse> h;

int chageDir(int d){
    if(d == 0) return 1;
    if(d == 1) return 0;
    if(d == 2) return 3;
    if(d == 3) return 2;
}

void go(int x, int y,int nx, int ny, int num, int color){
    if(color == 0){
        for(int i = 0; i < horse[x][y].size(); i++){
            int k = horse[x][y][i];
            if(k == num){
                int cnt = 0;
                for(int j = i; j < horse[x][y].size(); j++){
                    int l = horse[x][y][j];
                    horse[nx][ny].push_back(l);
                    h[l].r = nx; h[l].c = ny;
                    cnt++;
                }
                while(cnt--){
                    horse[x][y].pop_back();
                }
                break;
            }
        }
    }else if(color == 1){
        int cnt = 0;
        for(int i = horse[x][y].size()-1; i >= 0; i--){
            int k = horse[x][y][i];
            horse[nx][ny].push_back(k);
            h[k].r = nx; h[k].c = ny;
            cnt++;
            if(k == num){
                while(cnt--){
                    horse[x][y].pop_back();
                }
                break;
            }
        }
    }else if(color == 2){
        h[num].dir = chageDir(h[num].dir);
        int nnx = x+ dx[h[num].dir];
        int nny = y + dy[h[num].dir];
        if(0 <= nnx && nnx < N && 0 <= nny && nny < N){
            if(map[nnx][nny] != 2){
                go(x,y,nnx,nny,num,map[nnx][nny]);
            }
        }
    }

}

int main() {

    cin >> N>> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>map[i][j];
        }
    }

    for(int i = 0; i < K; i++){
       int r,c,d;
       cin >> r>> c>> d;
       h.push_back({r-1,c-1,d-1});
       horse[r-1][c-1].push_back(i);
    }

    int time = 0;
    while(true){
        time++;
        if(time > 1000){
            time = -1;
            break;
        }

        bool end = false;
        for(int i = 0; i < h.size(); i++){
            int x = h[i].r; int y = h[i].c;
            int nx = x + dx[h[i].dir];
            int ny = y + dy[h[i].dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) {
                go(x,y,nx,ny,i,2);
            }else{
                go(x,y,nx,ny,i,map[nx][ny]);
            }

            if(horse[h[i].r][h[i].c].size() >= 4){
                end = true;
                break;
            }

        }

        if(end) break;
    }

    cout<<time<<"\n";
    return 0;
}
