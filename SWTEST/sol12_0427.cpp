#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int N,M;
int map[25][25];
bool check[25][25];

struct Info{
    vector<pair<int,int>> block;
    int rainbow = 0;
    int x;
    int y;
};

bool compare(Info a, Info b){
    if(a.block.size() == b.block.size()){
        if(a.rainbow == b.rainbow){
            if(a.x == b.x){
                return a.y > b.y;
            }
            return a.x > b.x;
        }
        return a.rainbow > b.rainbow;
    }
    return a.block.size() > b.block.size();
}

bool inside(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < N;
}

void drop(){
    for(int i = 0; i < N; i++){
        for(int j = N-2; j >= 0; j--){
            int cur = j, next = j+1;
            while(inside(cur,next) && map[cur][i] >= 0 && map[next][i] == -2){
                map[next][i] = map[cur][i];
                map[cur][i] = -2;
                cur++; next++;
            }
        }
    }
}

void rotate(){
    int temp[25][25];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            temp[i][j] = map[j][N-1-i];
        }
    }

    memcpy(map,temp,sizeof(temp));
}

int main() {

    cin >> N >>M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>> map[i][j];
        }
    }

    int answer =0;
    while(true){
        memset(check, false,sizeof(check));
        vector<Info> groups;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                int color = map[i][j];
                if(color > 0 && !check[i][j]){
                    check[i][j] = true;
                    Info group;
                    group.x = i; group.y = j; group.block.push_back({i,j});
                    queue<pair<int,int>> q;
                    vector<vector<bool>> c(N,vector<bool>(N,false));
                    q.push({i,j});
                    c[i][j] = true;
                    while(!q.empty()){
                        int qx = q.front().first;
                        int qy = q.front().second;
                        q.pop();
                        for(int d = 0; d < 4; d++){
                            int nx = qx + dx[d];
                            int ny = qy + dy[d];
                            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                            if(check[nx][ny]) continue;
                            if(c[nx][ny]) continue;
                            if(map[nx][ny] == 0){
                                group.rainbow++;
                                c[nx][ny] = true;
                                q.push({nx,ny});
                                group.block.push_back({nx,ny});
                            }else if(color == map[nx][ny]){
                                c[nx][ny] = true;
                                check[nx][ny] = true;
                                q.push({nx,ny});
                                group.block.push_back({nx,ny});
                            }
                        }
                    }
                    if(group.block.size() >= 2){
                        groups.push_back(group);
                    }
                }
            }
        }

        if(groups.size() == 0) break;

        sort(groups.begin(),groups.end(),compare);
        for(int i = 0; i < groups[0].block.size(); i++){
            map[groups[0].block[i].first][groups[0].block[i].second] = -2;
        }

        answer += (groups[0].block.size() * groups[0].block.size());

        drop();

        rotate();

        drop();

    }

    cout<<answer<<"\n";

    return 0;
}
