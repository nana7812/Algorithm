#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;
vector<vector<int>> board;
int ans = 0;

bool inside(int x, int y ){
    return 0 <= x && x < N && 0 <= y && y < N;
}

vector<vector<int>> up(vector<vector<int>> v){
    vector<vector<bool>> ch(N,vector<bool>(N,false));
    for(int k = 0; k < N; k++){
        for(int i = 1; i < N; i++){
            int cur = i;
            int next = i-1;
            if(v[cur][k] == 0) continue;
            while(inside(cur, next)){
                if(v[cur][k] == v[next][k] && !ch[next][k]){
                    v[next][k] *= 2;
                    v[cur][k] = 0;
                    ch[next][k] = true;
                    break;
                }else if(v[next][k] == 0){
                    v[next][k] = v[cur][k];
                    v[cur][k] = 0;
                    cur--;
                    next--;
                }else{
                    break;
                }
            }
        }
    }
    return v;
}

vector<vector<int>> down(vector<vector<int>> v){
    vector<vector<bool>> ch(N,vector<bool>(N,false));
    for(int k = 0; k < N; k++){
        for(int i = N-2; i >= 0; i--){
            int cur = i;
            int next = i+1;
            if(v[cur][k] == 0) continue;
            while(inside(cur,next)){
                if(v[cur][k] == v[next][k] && !ch[next][k]){
                    v[next][k] *= 2;
                    v[cur][k] = 0;
                    ch[next][k] = true;
                    break;
                }else if(v[next][k] == 0){
                    v[next][k] = v[cur][k];
                    v[cur][k] = 0;
                    cur++;
                    next++;
                }else{
                    break;
                }
            }
        }
    }

    return v;
}

vector<vector<int >> right(vector<vector<int>> v){
    vector<vector<bool>> ch(N, vector<bool>(N, false));
    for(int k = 0; k < N; k++){
        for(int i = N-2; i >= 0; i--){
            int cur = i;
            int next = i+1;
            if(v[k][cur] == 0) continue;
            while(inside(cur,next)){
                if(v[k][cur] == v[k][next] && !ch[k][next]){
                    v[k][next] *= 2;
                    v[k][cur] = 0;
                    ch[k][next] = true;
                    break;
                }else if(v[k][next] == 0){
                    v[k][next] = v[k][cur];
                    v[k][cur] = 0;
                    cur++;
                    next++;
                }else{
                    break;
                }
            }
        }
    }
    return v;
}

vector<vector<int>> left(vector<vector<int>> v){
    vector<vector<bool>> ch(N,vector<bool>(N,false));
    for(int k = 0; k < N; k++){
        for(int i = 1; i < N; i++){
            int cur = i;
            int next = i-1;
            if(v[k][cur] == 0) continue;
            while(inside(cur, next)){
                if(v[k][cur] == v[k][next] && !ch[k][next]){
                    v[k][next] *= 2;
                    v[k][cur] = 0;
                    ch[k][next] = true;
                }else if(v[k][next] == 0){
                    v[k][next] = v[k][cur];
                    v[k][cur] = 0;
                    cur--;
                    next--;
                }else{
                    break;
                }
            }
        }
    }

    return v;
}

void dfs(int cnt,vector<vector<int>> v){
    if(cnt >= 5){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                ans = max(ans,v[i][j]);
            }
        }
        return;
    }
    //이동과 변화
    dfs(cnt+1,up(v));
    dfs(cnt+1,down(v));
    dfs(cnt+1,left(v));
    dfs(cnt+1,right(v));

}

int main(){
    cin>> N;
    board = vector<vector<int>>(N,vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>board[i][j];
        }
    }
    dfs(0,board);
    cout<<ans<<"\n";

    return 0;
}