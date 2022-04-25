#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int N, M,answer;
vector<vector<int>> map;
vector<pair<int,int>> w;


int safe(vector<vector<int>> &v){

    queue<pair<int,int>> q;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(v[i][j] == 2){
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M ) continue;
            if(v[nx][ny] == 0){
                q.push({nx,ny});
                v[nx][ny] = 2;
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(v[i][j] == 0) cnt++;
        }
    }

    return cnt;
}


void dfs(int cnt, int idx, vector<pair<int,int>> make){
    if(cnt >= 3){
        vector<vector<int>> temp;
        temp = map;
        for(int i = 0; i < 3; i++){
            temp[make[i].first][make[i].second] = 1;
        }

        int cnt = safe(temp);
        if(cnt > answer) answer = cnt;
        return;
    }

    for(int i = idx; i < w.size(); i++){
        make.push_back(w[i]);
        dfs(cnt+1,i+1,make);
        make.pop_back();
    }
}


int main() {

   cin >> N>> M;
   map = vector<vector<int>>(N,vector<int>(M,0));
   for(int i = 0; i < N; i++){
       for(int j = 0; j < M; j++){
           cin>>map[i][j];
           if(map[i][j] == 0){
               w.push_back({i,j});
           }
       }
   }

   answer = 0;
   vector<pair<int,int>> wall;
   dfs(0,0,wall);

   cout<<answer<<"\n";

    return 0;
}