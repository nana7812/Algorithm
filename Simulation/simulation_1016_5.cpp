#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;
int homeSize;
int answer;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
vector<pair<int,int>> chicken;

void bfs(vector<vector<int>> v){
    vector<vector<int>> d(N,vector<int>(N,-1));
    queue<pair<int,int>> q;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(v[i][j]==2){
                q.push({i,j});
                d[i][j] = 0;
            }
        }
    }
    int distance = 0;
    int find = 0;
    bool end = false;
    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = qx+dx[i];
            int ny = qy +dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(d[nx][ny] != -1) continue;
            if(v[nx][ny] == 1){
                distance += d[qx][qy] +1;
                find++;
            }
            if(find == homeSize){
                end = true;
                break;
            }
            q.push({nx,ny});
            d[nx][ny] = d[qx][qy] + 1;
        }
        if(end) break;
    }
    if(!end) return;

    if(answer == -1 || answer > distance){
        answer = distance;
    }
}

void open(vector<vector<int>> v, int idx, int cnt){
    if(cnt > M) return;
    if(cnt >= M){ //최대 M개 인데 상식적으로 많을 수록 가깝겠지^^
        bfs(v);
    }
    for(int i = idx; i < chicken.size(); i++){
        v[chicken[i].first][chicken[i].second] = 2;
        open(v,i+1,cnt+1);
        v[chicken[i].first][chicken[i].second] = 0;
    }
}

int main(){
   int T;
   cin>> T;
   while(T--){
       cin>> N>> M;
       chicken.clear();
       vector<vector<int>> city(55,vector<int>(55));
       answer = -1;
       homeSize = 0;
       for(int i = 0; i < N; i++){
           for(int j = 0; j < N; j++){
               cin>>city[i][j];
               if(city[i][j] == 1){
                   homeSize++;
               }else if(city[i][j] == 2){
                   chicken.push_back({i,j});
                   city[i][j] = 0;
               }
           }
       }
       open(city,0,0);
       cout<<answer<<"\n";
   }
    return 0;
}