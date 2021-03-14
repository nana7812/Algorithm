#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace  std;
int n, m;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int a[501][501];
bool check[501][501];

int ans = 0;

void dfs(int x, int y){
    if(x == n-1 && y == m-1){
        ans++;
        return;
    }
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0<= nx && nx < n && 0 <= ny && ny <m ) {
            if (a[nx][ny] < a[x][y]) {
                dfs(nx, ny);
            }
        }
    }
    return;
}

int main() {
    cin>> n>> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>a[i][j];
        }
    }

    dfs(0,0);

    cout<<ans;
    return 0;
}