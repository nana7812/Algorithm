#include<vector>
#include<queue>
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int d[101][101];

void move(vector<vector<int> > maps){
    int n = maps.size();
    int m = maps[0].size();
    d[0][0] = 1;
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();  
        for(int i = 0; i < 4; i++){
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            if(0 > nx || nx >= n || 0 > ny || ny >= m) continue;
            if(maps[nx][ny] == 0) continue;
            if(d[nx][ny] > 0) continue;
            q.push({nx,ny});
            d[nx][ny] = d[qx][qy] +1;
            if(nx == n-1 && ny == m-1){
                return;
            }
        }
    }

}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            d[i][j] = -1;
        }
    }
    
    move(maps);
    
    if(d[n-1][m-1] == -1){
       answer = -1;
    }else{
       answer = d[n-1][m-1]; 
    }
    
    return answer;
}