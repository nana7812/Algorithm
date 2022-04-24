#include <iostream>
#include <vector>

using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int N,answer;

bool inside(int x, int y){
    return 0 <= x && x < N && 0 <=y && y < N;
}

vector<vector<int>> up(vector<vector<int>> v){
    vector<vector<bool>> check(N,vector<bool>(N,false));
    for(int i = 0; i < N; i++){
        for(int j = 1; j < N; j++){
            if(v[j][i] == 0) continue; //?
            int cur = j; int next = j-1;
            while(inside(cur,next) && v[cur][i] != 0){
                if(v[next][i] == 0){
                    v[next][i] = v[cur][i];
                    v[cur][i] = 0;
                }else if(v[next][i] == v[cur][i] && !check[next][i]){
                    v[next][i] += v[cur][i];
                    v[cur][i] = 0;
                    check[next][i] = true;
                    break;
                }else{
                    break;
                }
                cur--; next--;
            }
        }
    }

    return v;
}
vector<vector<int>> down(vector<vector<int>> v){
    vector<vector<bool>> check(N,vector<bool>(N,false));
    for(int i = 0; i < N; i++){
        for(int j = N-2; j >= 0; j--){
            if(v[j][i] == 0) continue; //?
            int cur = j; int next = j+1;
            while(inside(cur,next) && v[cur][i] != 0){
                if(v[next][i] == 0){
                    v[next][i] = v[cur][i];
                    v[cur][i] = 0;
                }else if(v[next][i] == v[cur][i] && !check[next][i]){
                    v[next][i] += v[cur][i];
                    v[cur][i] = 0;
                    check[next][i] = true;
                    break;
                }else{
                    break;
                }
                cur++; next++;
            }

        }
    }

    return v;
}
vector<vector<int>> left(vector<vector<int>> v){
    vector<vector<bool>> check(N,vector<bool>(N,false));
    for(int i = 0; i < N; i++){
        for(int j = 1; j < N; j++){
            if(v[i][j] == 0) continue;
            int cur = j; int next = j-1;
            while(inside(cur,next) && v[i][cur] != 0){
                if(v[i][next] == 0){
                    v[i][next] = v[i][cur];
                    v[i][cur] = 0;
                }else if(v[i][next] == v[i][cur] && !check[i][next]){
                    v[i][next] += v[i][cur];
                    v[i][cur] = 0;
                    check[i][next] = true;
                    break;
                }else{
                    break;
                }
                cur--; next--;
            }

        }
    }

    return v;
}
vector<vector<int>> right(vector<vector<int>> v){
    vector<vector<bool>> check(N,vector<bool>(N,false));
    for(int i = 0; i < N; i++){
        for(int j = N-2; j >= 0; j--){
            if(v[i][j] == 0) continue;
            int cur = j; int next = j+1;
            while(inside(cur,next) && v[i][cur] != 0){
                if(v[i][next] == 0){
                    v[i][next] = v[i][cur];
                    v[i][cur] = 0;
                }else if(v[i][next] == v[i][cur] && !check[i][next]){
                    v[i][next] += v[i][cur];
                    v[i][cur] = 0;
                    check[i][next] = true;
                    break;
                }else{
                    break;
                }
                cur++; next++;
            }

        }
    }

    return v;
}


void dfs(vector<vector<int>> v, int cnt){
    if(cnt >= 5){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(answer < v[i][j]){
                    answer = v[i][j];
                }
            }
        }
        return;
    }
    dfs(up(v),cnt+1);
    dfs(down(v),cnt+1);
    dfs(left(v),cnt+1);
    dfs(right(v),cnt+1);
}


int main() {

    cin>> N; //
    vector<vector<int>> map(N,vector<int>(N,0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>map[i][j];
        }
    }

    answer = 0;
    dfs(map,0);

    cout<<answer<<"\n";

    return 0;
    
}