#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int N;
int space[21][21];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int fish;
struct shark{
    int x;
    int y;
    int size;
    int total;
};


bool compare(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
    if(a.first == b.first){
       if(a.second.first == b.second.first){
           return a.second.second < b.second.second;
       }
       return a.second.first < b.second.first;
    }
    return a.first < b.first;
}

int main() {
    cin>> N;
    shark baby;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>space[i][j];
            if(space[i][j] == 9) {
                baby.x = i;
                baby.y = j;
                baby.size = 2;
                baby.total = 0;
                space[i][j] = 0;
            }else if(1 <= space[i][j] && space[i][j] <= 6){
                fish++;
            }
        }
    }

    int time = 0;
    vector<pair<int,pair<int,int>>> eat;
    while(fish != 0){
        eat.clear();
        vector<vector<bool>> c(N,vector<bool>(N,false));
        queue<pair<pair<int,int>,int>> q;
        q.push({{baby.x,baby.y},0});
        c[baby.x][baby.y] = true;
        int ans = -1;
        while(!q.empty()){
            int qx = q.front().first.first;
            int qy = q.front().first.second;
            int qc = q.front().second;
            q.pop();
            if(ans != -1 && qc+1 > ans) break;
            for(int i = 0; i < 4; i++){
                int nx = qx + dx[i];
                int ny = qy + dy[i];
                if(nx < 0 || nx >= N || ny < 0 || ny >=N ) continue;
                if(c[nx][ny]) continue;
                if(space[nx][ny] > baby.size) continue;
                q.push({{nx,ny},qc+1});
                c[nx][ny] = true;
                if(1<= space[nx][ny] && space[nx][ny] <= 6 && space[nx][ny] < baby.size){
                    eat.push_back({qc+1,{nx,ny}});
                    if(ans == -1 ) ans = qc+1;
                    //여기서 중단의 기회가 있을수도?? 최소거리보다 넘어가면 안해야
                }
            }
        }

        if(eat.size() == 0) break;

        sort(eat.begin(),eat.end(),compare);
        time += eat[0].first;
        space[eat[0].second.first][eat[0].second.second] = 0;
        fish--;
        baby.x = eat[0].second.first;
        baby.y = eat[0].second.second;
        baby.total++;
        if(baby.total == baby.size){
            baby.size++;
            baby.total = 0;
        }

    }

    cout<<time<<" ";

    return 0;
}