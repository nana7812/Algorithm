#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <cstring>
using  namespace  std;

int dx[]= {-1,1,0,0};
int dy[] ={0,0,-1,1};

vector<pair<int,int>> room[101][101];
bool check[101][101];
bool turnOn[101][101];
int n,m;
int ans = 0;

void bfs(int x, int y){
    memset(check,false,sizeof (check));
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    check[x][y] = true;
    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        for(int i =0; i <room[qx][qy].size(); i++) {
            int tx = room[qx][qy][i].first;
            int ty = room[qx][qy][i].second;
            if (!turnOn[tx][ty]) {
            turnOn[tx][ty] = true;
            ans++;
            }
        }
        for(int i=0; i<4; i++){
            int nx = qx+dx[i];
            int ny = qy+dy[i];
            if(1<=nx && nx <=n  && 1<=ny && ny <=n){
                if(turnOn[nx][ny] == true && check[nx][ny] == false){
                    q.push(make_pair(nx,ny));
                    check[nx][ny] = true;
                }
            }
        }
    }

}

int main() {
    cin >> n >> m;
    int a, b, c, d;
    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        room[a][b].push_back(make_pair(c, d));
    }

    ans = 1;
    turnOn[1][1] = true;
    int b_ans = 0;
    do{
        b_ans = ans;
        bfs(1,1);
    }while(ans != b_ans);

    cout<<ans;
    return 0;
}