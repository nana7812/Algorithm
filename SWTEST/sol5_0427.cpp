#include <iostream>
#include <vector>
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int N, M, K;
pair<int,int> smell[25][25]; //번호,시간
int map[25][25];

struct Shark{
    int x;
    int y;
    int d;
    int p[4][4];
    bool live = true;
};
Shark s[410];

int main() {
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>map[i][j];
            if(map[i][j] > 0){
                s[map[i][j]].x = i;
                s[map[i][j]].y = j;
                smell[i][j].first = map[i][j];
                smell[i][j].second = K;
            }
        }
    }
    for(int i = 1; i <= M; i++){
        cin>> s[i].d;
        s[i].d--;
    }

    for(int i = 1; i <= M; i++){
        for(int j = 0; j < 4; j++){
            for(int l = 0; l < 4; l++){
                cin>>s[i].p[j][l];
                s[i].p[j][l]--;
            }
        }
    }


    int time = 1;
    while(true){
        //상어이동
        int temp[25][25];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                temp[i][j] = 0; //????
            }
        }
        //
        for(int i = 1; i <= M; i++){
            if(!s[i].live) continue;
            int x = s[i].x;
            int y = s[i].y;
            int dir = s[i].d;
            int r = -1,c = -1; int rr = -1,cc = -1;
            int nd; int nnd;
            for(int d = 0; d < 4; d++){
                int ndir = s[i].p[dir][d];
                int nx = x + dx[ndir];
                int ny = y + dy[ndir];
                if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                if(smell[nx][ny].second < time){ //?
                    if(r == -1 && c == -1){
                        r = nx; c = ny;
                        nd = ndir;
                        break;
                    }
                }else{
                    if(smell[nx][ny].first == i){
                        if(rr == -1 && cc == -1){
                            rr = nx; cc = ny;
                            nnd = ndir;
                        }
                    }
                }
            }

            if(r == -1 && c == -1){
                r = rr;
                c = cc;
                nd = nnd;
            }

            //새로운 위치에 도달가능?
            if(temp[r][c] == 0){
                temp[r][c] = i;
                s[i].x = r;
                s[i].y = c;
                s[i].d = nd;
            }else if(temp[r][c] < i){
                s[i].live = false;
            }else if(temp[r][c] > i){
                s[temp[r][c]].live = false;
                temp[r][c] = i;
                s[i].x = r;
                s[i].y = c;
                s[i].d = nd;
            }
        }


        //냄새
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(temp[i][j] > 0){
                    smell[i][j].first = temp[i][j];
                    smell[i][j].second = time+K;
                }
            }

        }



        //중단 확인
        bool flag = true;
        for(int i = 2; i <=M; i++){
            if(s[i].live){
                flag = false;
                break;
            }
        }


        if(flag) break;

        time++;
        if(time > 1000){
            time = -1;
            break;
        }

    }

    cout<<time<<"\n";

    return 0;
}
