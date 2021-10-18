#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
struct horse{
    int x;
    int y;
    int dir;
};
int N,K;
int color[13][13];
vector<int> map[13][13];
vector<horse> chess;

int changeDir(int n){
    if(n == 0) return 1;
    if(n == 1) return 0;
    if(n == 2) return 3;
    if(n == 3) return 2;
}

int findIdx(int num,int x, int y){
    for(int i = 0; i < map[x][y].size(); i++){
        if(map[x][y][i] == num){
            return i;
        }
    }
}
bool check(){
    for(int j = 0; j < K; j++){
        int x = chess[j].x;
        int y = chess[j].y;
        if(map[x][y].size()>= 4){
            return true;
        }
    }
    return false;
}
void move(int num, int x, int y, int nx, int ny,int c){
    if(c == 0){
        int idx = findIdx(num,x,y);
        int cnt = 0;
        for(int j = idx; j < map[x][y].size(); j++){
            map[nx][ny].push_back(map[x][y][j]);
            chess[map[x][y][j]].x = nx;
            chess[map[x][y][j]].y = ny;
            cnt++;
        }
        while(cnt--){
            map[x][y].pop_back();
        }
    }else if(c == 1){
        int idx = findIdx(num,x,y);
        int cnt = 0;
        for(int j = map[x][y].size()-1 ; j >= idx; j--){
            map[nx][ny].push_back(map[x][y][j]);
            chess[map[x][y][j]].x = nx;
            chess[map[x][y][j]].y = ny;
            cnt++;
        }
        while(cnt--){
            map[x][y].pop_back();
        }
    }else if(c == 2){
        chess[num].dir = changeDir(chess[num].dir);
        int nnx = x + dx[chess[num].dir];
        int nny = y + dy[chess[num].dir];
        if(0 <= nnx && nnx < N && 0 <= nny && nny < N) {
            if(color[nnx][nny] != 2) {
                move(num, x, y, nnx, nny, color[nnx][nny]);
            }
        }
    }

}



int main(){
    // int T;
    // while(T--){
    cin>> N>> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>color[i][j];
        }
    }
    for(int i = 0; i < K; i++){
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;c--;
        chess.push_back({a,b,c}); ////
        map[a][b].push_back(i); //
    }
    int turn = 0;
    while(true){
        turn++;
        if(turn > 1000){
            turn = -1;
            break;
        }
        bool endPoint = false;
        //말 이동
        for(int i = 0; i < K; i++){
            int x = chess[i].x;
            int y = chess[i].y;
            int nx = x + dx[chess[i].dir];
            int ny = y + dy[chess[i].dir];
            if(0 <= nx && nx < N && 0 <= ny && ny < N) { //범위
                move(i,x,y,nx,ny,color[nx][ny]);
            }else{
                move(i,x,y,nx,ny,2);
            }
            if(check()){
                endPoint = true;
                break;
            }

        }
        if(endPoint) break;
    }
    cout<<turn<<"\n";
    //}
    return 0;
}