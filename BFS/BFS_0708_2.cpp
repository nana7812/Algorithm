#include <iostream>
#include <stdlib.h>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <cstring>
#include <stack>

using namespace  std;

int dx[] = {-1,1,0,0};
int dy[] ={0,0,-1,1};

vector<vector<int>> bfs(vector<string> &a, int sx, int sy){
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> dist(n,vector<int>(m,-1));
    queue<pair<int,int>> q;
    q.push({sx,sy});
    dist[sx][sy] = 0;
    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        for(int k = 0; k <4; k++){
            int nx = qx + dx[k];
            int ny = qy + dy[k];
            if(0 <= nx && nx < n && 0 <= ny && ny < m){
                if(dist[nx][ny] == -1 && a[nx][ny] != 'x'){
                    dist[nx][ny] = dist[qx][qy] + 1;
                    q.push({nx,ny});
                }
            }
        }
    }
    return dist;
}

int main() {
    while(true){
        int n, m;
        cin>> m >> n;
        if(n == 0 && m== 0) break;
        vector<string> a(n);
        for(int i = 0; i <n; i++){
            cin>>a[i];
        }
        vector<pair<int,int>> b(1);
        for(int i = 0; i< n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == 'o'){
                    b[0] = {i,j};
                }else if(a[i][j] == '*'){
                    b.push_back({i,j});
                }
            }
        }

        int size = b.size();
        vector<vector<int>> d(size,vector<int>(size));
        bool ok = true;
        for(int i = 0; i <size; i++){
            auto dist = bfs(a,b[i].first,b[i].second);
            for(int j = 0; j < size; j++){
                d[i][j] = dist[b[j].first][b[j].second];
                if(d[i][j] == -1){
                    ok = false;
                }
            }
        }
        if(ok == false){
            cout<<-1<<"\n";
            continue;
        }
        vector<int> p(size-1);
        for(int i = 0; i < size -1; i++){
            p[i] = i+1;
        }
        int ans = -1;
        do{
            int now = d[0][p[0]];
            for(int i = 0; i < size -2; i++){
                now += d[p[i]][p[i+1]];
            }
            if(ans == -1 || ans > now){
                ans = now;
            }
        }while(next_permutation(p.begin(),p.end()));
        cout<<ans<<"\n";

    }
    return 0;
}
