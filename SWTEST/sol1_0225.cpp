#include <iostream>
#include <algorithm>
#include <deque>
#include <cstring>
//
using namespace std;

int N, K, L,dir;
bool apple[105][105];
bool snake[105][105];
char change[10005];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int main(){
    memset(change,'X',sizeof(change));
    cin>> N;
    cin>> K;
    for(int i = 0; i < K; i++){
        int x,y;
        cin>> x>> y;
        x--;y--;
        apple[x][y] = true;
    }
    cin>> L;
    for(int i = 0; i < L; i++){
        int t; char d;
        cin>> t>> d;
        change[t] = d;
    }
    dir = 0;
    deque<pair<int,int>> snakeQ;
    snakeQ.push_front({0,0});
    snake[0][0] = true;
    int time = 0;
    while(true){
        time++;
        int nx = snakeQ.front().first + dx[dir];
        int ny = snakeQ.front().second + dy[dir];
        if(0 > nx || nx >= N || 0 > ny || ny >= N) break;
        if(snake[nx][ny]) break;
        snakeQ.push_front({nx,ny});
        snake[nx][ny] = true;
        if(apple[nx][ny]){
            apple[nx][ny] = false;
        }else{
            snake[snakeQ.back().first][snakeQ.back().second] = false;
            snakeQ.pop_back();
        }
       // cout<<time<<" "<<nx<<" "<<ny << " "<<len<<"\n";
        if(change[time] == 'D'){
            dir = (dir + 1) % 4;
        }else if(change[time] == 'L'){
            dir = (dir + 3) % 4;
        }

    }

    cout<<time<<"\n";

    return 0;
}