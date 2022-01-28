#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int row, col;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

bool inside(int x, int y){
    return 0 <= x && x < row  && 0 <= y && y < col;
}

bool solve(int x, int y, vector<string> & board){
    char find = board[x][y];
    
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        while(inside(nx,ny) && (board[nx][ny] == '.' ||board[nx][ny] == find)){
            if(board[nx][ny] == find){
                board[nx][ny] = '.';
                board[x][y] = '.';
                return true;
            }
            for(int j = 0; j < 4; j++){
                if(i == j || (i == 0 && j == 1) || (i== 1 &&j == 0) ||(i== 2 && j == 3) ||(i==3 && j ==2)) continue;
                
                int nnx = nx + dx[j];
                int nny = ny + dy[j];
                
                while(inside(nnx,nny) && (board[nnx][nny] == '.' || board[nnx][nny] == find)){
                    if(board[nnx][nny] == find){
                       board[nnx][nny] = '.';
                       board[x][y] = '.';
                       return true; 
                    }
                    nnx += dx[j];
                    nny += dy[j];
                }
            }
            nx += dx[i];
            ny += dy[i];
        }
    }
    return false;
}

string solution(int m, int n, vector<string> board) {
   string answer = "";
    row = m; col = n;
    vector<pair<char,pair<int,int>>> reserve;
    map<char,int> check;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if('A'<= board[i][j] && board[i][j] <= 'Z' && check[board[i][j]] == 0){
                check[board[i][j]] = 1;
                reserve.push_back({board[i][j],{i,j}});
            }
        }
    }
    sort(reserve.begin(),reserve.end());
    
    bool flag = true;
    while(flag){
        flag = false;
        for(int i = 0; i < reserve.size(); i++){
            flag = solve(reserve[i].second.first,reserve[i].second.second,board);
            if(flag){
                cout<<reserve[i].first<<" ";
                answer += reserve[i].first;
                reserve.erase(reserve.begin()+i);
                break;
            }
        }
    }
    
    if(reserve.size() != 0){ // 다 제거 되지 않는다면
        answer = "IMPOSSIBLE";
    }
    
  
    return answer;
}