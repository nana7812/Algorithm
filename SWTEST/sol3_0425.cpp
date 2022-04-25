#include <iostream>
#include <queue>

using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int N,K,L;
bool apple[105][105];
bool snake[105][105];
char t[10005];


int main() {

    cin>> N>> K;
    for(int i = 0; i < K; i++){
        int r,c;
        cin>>r>> c;
        apple[r-1][c-1] = true;
    }
    cin>>L;
    for(int i = 0; i < L; i++){
        int tt; char c;
        cin>> tt>> c;
        t[tt] = c;
    }

    int x = 0, y = 0, dir = 0; //?
    deque<pair<int,int>> q;
    q.push_back({0,0});
    snake[0][0] = true;
    int time = 1; //?
    while(true){
        int nx = q.front().first + dx[dir];
        int ny = q.front().second + dy[dir];
        if(nx < 0 || nx >= N || ny < 0 || ny >= N || snake[nx][ny]) break; //중단
        q.push_front({nx,ny});
        snake[nx][ny] = true;
        if(apple[nx][ny]){
            apple[nx][ny] = false;
        }else{
            snake[q.back().first][q.back().second] = false;
            q.pop_back();
        }

        if(t[time] == 'L'){
            dir = (dir + 3 ) % 4;
        }else if(t[time] == 'D'){
            dir = (dir + 1) % 4;
        }

        time++;
    }

    cout<<time<<"\n";

    return 0;

}
