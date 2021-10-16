#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int N,L,R;
int a[55][55];
bool c[55][55];


int BFS(int x, int y){
    vector<pair<int,int>> g;
    queue<pair<int,int>> q;
    g.push_back({x,y});
    q.push({x,y});
    c[x][y] = true;
    int total = a[x][y];
    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(c[nx][ny]) continue;
            int diff = abs(a[qx][qy] - a[nx][ny]);
            if(L <= diff && diff <= R){
                q.push({nx,ny});
                g.push_back({nx,ny});
                c[nx][ny] = true;
                total += a[nx][ny];
            }
        }
    }
    int groupSize = g.size();
    if(groupSize >= 2){
        int people = total/groupSize;
        for(int i = 0; i < groupSize; i++){
            a[g[i].first][g[i].second] = people;
        }
    }
    return groupSize;
}
int main(){
    int T;
    cin>> T;
    while(T--){
        cin>>N>>L>>R;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin>>a[i][j];
            }
        }
        int day = -1;
        bool makeGroup;
        while(true){
            memset(c,false,sizeof(c));
            makeGroup = false;
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    if(!c[i][j]){
                       int size = BFS(i,j);
                       if(size >= 2) makeGroup = true;
                    }
                }
            }
            day++;
            if(!makeGroup) break;
        }
        cout<<day<<"\n";
    }
    return 0;
}