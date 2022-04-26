#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int N;
int map[25][25];
int answer;


struct Shark{
    int x;
    int y;
    int cnt;
    int size;
};
Shark s;


bool compare(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

bool find(int x, int y){
    bool c[N][N];
    memset(c,false,sizeof(c));
    vector<pair<int,int>> fish;
    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y},0});
    c[x][y] = true;
    int diff = -1;
    while(!q.empty()){
        int qx = q.front().first.first;
        int qy = q.front().first.second;
        int qc = q.front().second;
        q.pop();
        if(diff != -1 && qc == diff) break; //?
        for(int i = 0; i < 4; i++){
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(c[nx][ny]) continue;
            if(map[nx][ny] > s.size) continue;
            if(map[nx][ny] > 0 && map[nx][ny] < s.size){
                if(diff == -1) diff = qc+1;
                fish.push_back({nx,ny});

            }
            q.push({{nx,ny},qc+1});
            c[nx][ny] = true;
        }
    }


    if(fish.size() == 0) return false;
    sort(fish.begin(),fish.end(),compare);
    answer += diff;
    s.x = fish[0].first; s.y = fish[0].second;
    s.cnt += 1;
    if(s.cnt == s.size){
        s.size += 1;
        s.cnt = 0;
    }
    map[fish[0].first][fish[0].second] = 0;
    return true;
}

int main() {

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            if(map[i][j] == 9){
                s.x = i;
                s.y = j;
                s.size = 2;
                s.cnt = 0;
                map[i][j] = 0;
            }
        }
    }

    while(true){
        if(!find(s.x,s.y)) break;
    }

    cout<<answer<<"\n";
    return 0;
}
