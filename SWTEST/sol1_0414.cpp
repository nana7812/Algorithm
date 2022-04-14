#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Shark{
    int x;
    int y;
    int dir;
    bool live;
    int p[4][4];
};

int N,M,K;
int num[21][21];
pair<int,int> smell[21][21];
Shark shark[401];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};



int main() {
    int answer = -1;
    cin>> N>> M>> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>num[i][j];
            if(num[i][j] >= 1){
                shark[num[i][j]].x = i;
                shark[num[i][j]].y = j;
                shark[num[i][j]].live = true;

                smell[i][j].first = num[i][j];
                smell[i][j].second = K;
            }
        }
    }
    for(int i = 1; i <= M; i++){
        cin>>shark[i].dir;
        shark[i].dir--;
    }

    for(int i = 1; i <= M; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                cin>>shark[i].p[j][k];
                shark[i].p[j][k]--;
            }
        }
    }
    
    int time = 1;
    while(true){
        vector<int> move[N][N];
        int temp[N][N];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                temp[i][j] = num[i][j];
            }
        }

        for(int i = 1; i <= M; i++){
            if(!shark[i].live) continue;
            int dir = shark[i].dir;
            int nx, ny, ndir;
            bool check = false;
            for(int k = 0; k < 4; k++){
                ndir = shark[i].p[dir][k];
                nx = shark[i].x + dx[ndir];
                ny = shark[i].y + dy[ndir];
                if(0 > nx || nx >= N || 0 > ny || ny >= N ) continue;
                if(num[nx][ny] == 0 && smell[nx][ny].second < time){
                    check = true;
                    break;
                }
            }
        
            if(!check){
                for(int k = 0; k < 4; k++){
                    ndir = shark[i].p[dir][k];
                    nx = shark[i].x + dx[ndir];
                    ny = shark[i].y + dy[ndir];
                    if(0 > nx || nx >= N || 0 > ny || ny >= N ) continue;
                    if(smell[nx][ny].first == i){
                        check = true;
                        break;
                    }
                }
            }

            //이동
            if(check){
                temp[shark[i].x][shark[i].y] = 0;
                shark[i].x = nx;
                shark[i].y = ny;
                shark[i].dir = ndir;
                move[nx][ny].push_back(i);
              
            }
        }

        for(int i = 0; i < N; i++){
            for(int j= 0; j < N; j++){
                if(move[i][j].size() <= 1) continue; //?
                sort(move[i][j].begin(),move[i][j].end());
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(move[i][j].size() >= 1){
                    int n = move[i][j][0];
                    temp[shark[n].x][shark[n].y] = n;
                    smell[shark[n].x][shark[n].y].first = n;
                    smell[shark[n].x][shark[n].y].second = time + K;

                    for(int k = 1; k < move[i][j].size(); k++){
                        shark[move[i][j][k]].live = false;
                    }
                }

            }
        }

        bool end = true;
        for(int i = 2; i <= M; i++){
            if(shark[i].live){
                end = false;
                break;
            }
        }
        if(end){
            answer = time;
            break;
        }

        time++;
        if(time > 1000){
            break;
        }

     
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                num[i][j] = temp[i][j];
            }
        }

    }

   cout<<answer<<"\n";

    return 0;
}