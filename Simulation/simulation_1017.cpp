#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

vector<pair<int,pair<int,int>>> fish;
int N;
int map[21][21];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
struct shark{
    int x;
    int y;
    int size;
    int eatCnt;
};
shark s;

void bfs(int x, int y){
    int take = -1;
    fish.clear();
    vector<vector<bool>> c(N,vector<bool>(N,false));
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{x,y}});
    c[x][y] = true;
    while(!q.empty()){
        int cnt = q.front().first;
        int qx = q.front().second.first;
        int qy = q.front().second.second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = qx+ dx[i];
            int ny = qy + dy[i];
            if(0>nx || nx >= N || 0 > ny || ny >= N ) continue;
            if(c[nx][ny]) continue;
            if(map[nx][ny] <= s.size){
                if(map[nx][ny] > 0 && map[nx][ny] < s.size){
                    if(take == -1 || take >= cnt+1){
                        fish.push_back({cnt+1,{nx,ny}});
                        take = cnt+1;
                    }
                }
                q.push({cnt+1,{nx,ny}});
                c[nx][ny] = true;
            }
        }
    }
}

int main(){
    int T;
    cin>> T;
    while(T--){
        cin>> N;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin>> map[i][j];
                if(map[i][j] == 9){
                    s.x = i;
                    s.y = j;
                    s.size = 2;
                    s.eatCnt = 0;
                    map[i][j] = 0; //잊지말자 이동하는건 비워주기
                }
            }
        }
        int answer = 0;
        while(true){
            bfs(s.x,s.y);
            if(fish.empty()){
                break;
            }else{
                sort(fish.begin(),fish.end());
                int fishCnt = fish[0].first;
                int fishX = fish[0].second.first;
                int fishY = fish[0].second.second;
                map[fishX][fishY] = 0;
                s.eatCnt++;
                if(s.eatCnt == s.size){
                    s.size++;
                    s.eatCnt = 0;
                }
                answer += fishCnt;
                s.x = fishX;
                s.y = fishY;
            }
        }
        cout<<answer<<"\n";
    }

    return 0;
}