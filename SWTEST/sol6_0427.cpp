#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int N, M;
int map[25][25];

int s[25][25];
pair<int,int> e[410];
struct Taxi{
    int x;
    int y;
    int fuel;
    int total;
};
Taxi taxi;

bool compare(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    if(a.first.first == b.first.first){
        return a.first.second < b.first.second;
    }
    return a.first.first < b.first.first;
}

pair<int,int> select(){
    if(s[taxi.x][taxi.y] > 0){
        int n = s[taxi.x][taxi.y];
        s[taxi.x][taxi.y] = 0;
        return make_pair(n,0);
    }
    int d[N][N];
    memset(d,-1,sizeof(d));
    queue<pair<int,int>> q;
    q.push({taxi.x,taxi.y});
    d[taxi.x][taxi.y] = 0;
    vector<pair<pair<int,int>,int>> p; //위치, 승객번호
    int cnt = -1;
    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        if(cnt != -1 && d[qx][qy] == cnt) break;
        for(int i = 0; i < 4; i++){
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(map[nx][ny] == 1 || d[nx][ny] != -1) continue;
            if(s[nx][ny] > 0){
                p.push_back({{nx,ny},s[nx][ny]});
                if(cnt == -1){//
                    cnt = d[qx][qy] + 1;
                }
            }
            q.push({nx,ny});
            d[nx][ny] = d[qx][qy] + 1;
        }
    }

    if(p.size() == 0) return make_pair(-1,-1);

    sort(p.begin(),p.end(),compare);
    s[p[0].first.first][p[0].first.second] = 0;
    taxi.x = p[0].first.first; taxi.y = p[0].first.second;
    return make_pair(p[0].second,cnt);
}

int getOff(int num){
    if(e[num].first == taxi.x && e[num].second == taxi.y){
        return 0;
    }

    int d[N][N];
    memset(d,-1,sizeof(d));
    queue<pair<int,int>> q;
    q.push({taxi.x,taxi.y});
    d[taxi.x][taxi.y] = 0;
    int cnt = -1;
    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(map[nx][ny] == 1 || d[nx][ny] != -1) continue;
            if(nx == e[num].first && ny == e[num].second){
                taxi.x = nx; taxi.y = ny;
                cnt = d[qx][qy] + 1;
                return cnt;
            }
            q.push({nx,ny});
            d[nx][ny] = d[qx][qy] + 1;
        }
    }
    return cnt;
}

int main() {
    cin >> N >> M >>taxi.fuel;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>> map[i][j];
        }
    }

    cin>>taxi.x>> taxi.y;
    taxi.x--; taxi.y--;
    for(int i = 0; i < M; i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        s[a-1][b-1] = i+1;
        e[i+1] = {c-1,d-1};
    }

    bool done = false;
    while(true){
        //출발지
        auto p = select();
        if(p.first == -1 || taxi.fuel - p.second < 0) break;
        taxi.fuel -= p.second;
        //cout<<taxi.x<<" "<<taxi.y<<"( "<<p.second<<")"<<" "<<taxi.fuel<<"->";
        //목적지
        int cnt = getOff(p.first);
        if(cnt == -1 || taxi.fuel - cnt < 0) break;
        taxi.fuel -= cnt;
        taxi.fuel += (cnt*2);
        taxi.total++;
        //cout<<taxi.x<<" "<<taxi.y<<" "<<taxi.fuel<<"\n";
        if(taxi.total == M){
            done = true;
            break;
        }
    }

    if(done){
        cout<<taxi.fuel<<"\n";
    }else{
        cout<<-1<<"\n";
    }

    return 0;
}