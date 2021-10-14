#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
typedef long long ll;

int N,K,L;
bool apple[105][105];
bool isSnake[105][105];
int t[10005];

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

void init(){
    memset(apple,false,sizeof(apple));
    memset(isSnake,false,sizeof(isSnake));
    memset(t,0,sizeof(t));
}
void input(){
    cin>> N;
    cin>> K;
    for(int i = 0; i < K; i++){
        int a,b;
        cin>>a>>b;
        apple[a][b] = true;
    }
    cin>> L;
    for(int i = 0; i < L; i++){
        int tt; char d;
        cin>>tt>>d;
        if(d == 'L'){
            t[tt] = 1;
        }else{
            t[tt] = 2;
        }
    }
}
int solution(){
    queue<pair<int,int>> snake;
    snake.push({1,1});
    isSnake[1][1] = true;
    int snakeDir = 0;
    int answerT = 0;
    while(true){
        answerT++;
        int nx = snake.back().first + dx[snakeDir];
        int ny = snake.back().second + dy[snakeDir];
        if(nx < 1 || nx > N || ny < 1 || ny > N) return answerT;
        if(isSnake[nx][ny]) return answerT;
        snake.push({nx,ny});
        isSnake[nx][ny] = true;
        if(apple[nx][ny]){
            apple[nx][ny] = false;
        }else{
            isSnake[snake.front().first][snake.front().second] = false;
            snake.pop();
        }

        //방향
        if(t[answerT] == 1){
            snakeDir = (snakeDir+3)%4;
        }else if(t[answerT] == 2){
            snakeDir = (snakeDir+1) %4;
        }
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        init();
        input();
        int answer = solution();
        cout<<answer<<"\n";
    }
    return 0;
}