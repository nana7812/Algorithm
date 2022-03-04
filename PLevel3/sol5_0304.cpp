#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
vector<vector<int>> b;
int x, y;

int bfs(int v){
    vector<vector<bool>> c(4,vector<bool>(4,false));
    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y},0});
    c[x][y] = true;
    while(!q.empty()){
        int qx = q.front().first.first;
        int qy = q.front().first.second;
        int qc = q.front().second;
        q.pop();
        if(b[qx][qy] == v){
            b[qx][qy] = 0;
            x = qx; y = qy;
            return qc+1;
        }
        for(int i = 0; i < 4; i++){
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            if(0 > nx || nx >= 4 || 0 > ny || ny >= 4) continue;
            if(c[nx][ny]) continue;
            q.push({{nx,ny},qc+1});
            c[nx][ny] = true;
        }
        for(int i = 0; i < 4; i++){
            int nx = qx; int ny = qy;
            while(0<= nx+dx[i] && nx +dx[i] < 4 && 0 <= ny+dy[i] && ny + dy[i] < 4){
                nx += dx[i];
                ny += dy[i];
                if(b[nx][ny] > 0) break;
            }
            if(!c[nx][ny]){
                q.push({{nx,ny},qc+1});
                c[nx][ny] = true;
            }
        }
    }
    
}

int solution(vector<vector<int>> board, int r, int c){
    int answer = 987654321;
    bool check[9];
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            if(board[i][j] > 0 && !check[board[i][j]]){
                check[board[i][j]] = true;
            }
        }
    }
    
    vector<int> card;
    for(int i = 0; i < 9; i++){
        if(check[i]) card.push_back(i);
    }
    do{
        int ans = 0;
        b = board;
        x= r; y = c;
        for(int i = 0; i < card.size(); i++){
            //카드 두개니까 둘다 찾아야징
            ans += bfs(card[i]); 
            ans += bfs(card[i]);
        }
        
        if(answer > ans) answer = ans;
    }while(next_permutation(card.begin(),card.end()));
    
    return answer;
}