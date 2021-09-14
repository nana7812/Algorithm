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
#include <array>
using namespace std;

int dx[] = {0,-1,1,0,0};
int dy[] = {0,0,0,-1,1};

struct Shark{
    int x = 0;
    int y = 0;
    int dir = 0;
    bool live = false;
    int priority[5][5];
};

int N,M,K;
//상어번호, 냄새시간
int m[21][21]; //이동가능한지 여
pair<int,int> nextM[21][21];
Shark shark[401];


int main(){
    cin >> N>> M>> K;
    //map 입력받기
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>> m[i][j];
            if(m[i][j] != 0){
                shark[m[i][j]].x = i;
                shark[m[i][j]].y = j;
                shark[m[i][j]].live = true;

                nextM[i][j].first = m[i][j];
                nextM[i][j].second = K;
            }
        }
    }
    //상어 방향 입력받기
    for(int i = 1; i <= M; i++){
        cin>>shark[i].dir;
    }
    //방향 우선순위
    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= 4; j++){
            for(int k = 1; k <= 4; k++){
                cin>>shark[i].priority[j][k];
            }
        }
    }

    int time = 1;
    while(time <= 1000){
        //상어의 이동
        for(int i = 1; i <= M; i++){
            if(!shark[i].live) continue; //이미 죽은 상어는 패스

            bool ok = false; //냄새 안 나는 칸 있는지?
            int x = shark[i].x;
            int y = shark[i].y;
            int curDir = shark[i].dir;
            for(int j = 1;  j <= 4; j++){
                int nDir = shark[i].priority[curDir][j];
                int nx = x + dx[nDir];
                int ny = y + dy[nDir];
                if(nx < 0 || ny < 0 || nx >= N || ny >= N || nextM[nx][ny].first != 0) continue;
                ok = true;
                if(m[nx][ny] != 0){
                    if(m[nx][ny] < i){
                        shark[i].live = false;
                        m[x][y] = 0;
                    }else{
                        shark[m[nx][ny]].live = false;
                        m[x][y] = 0;
                        shark[i].x = nx;
                        shark[i].y = ny;
                        shark[i].dir = nDir;
                        m[nx][ny] = i;
                    }
                }else{
                    m[x][y] = 0;
                    shark[i].x = nx;
                    shark[i].y = ny;
                    shark[i].dir = nDir;
                    m[nx][ny] = i;
                }
                break; //조건중 하나 실행됐으니까 패스
            }

            if(!ok){
                for(int j = 1;  j <= 4; j++){
                    int nDir = shark[i].priority[curDir][j];
                    int nx = x + dx[nDir];
                    int ny = y + dy[nDir];
                    if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                    if(nextM[nx][ny].first == i){
                        m[x][y] = 0;
                        shark[i].x = nx;
                        shark[i].y = ny;
                        shark[i].dir = nDir;
                        m[nx][ny] = i;
                        break;
                    }
                }
            }
        }

        //냄새제게
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(nextM[i][j].first != 0){
                    nextM[i][j].second--;

                    if(nextM[i][j].second == 0){
                        nextM[i][j].first = 0;
                    }
                }
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(m[i][j] != 0){
                    nextM[i][j].first = m[i][j];
                    nextM[i][j].second = K;
                }
            }
        }

        bool only = true;
        for(int i = 2; i <= M; i++){
            if(shark[i].live == true){
                only = false;
                break;
            }
        }
        if(only){
            cout<<time<<"\n";
            return 0;
        }else{
            time++;
        }
    }
    cout<<-1<<"\n";

    return 0;
}