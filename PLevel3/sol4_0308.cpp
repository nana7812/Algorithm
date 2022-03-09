#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool inside(int y, int x){
    return 0 <= y && y < N && 0 <= x && x < M;
}

bool go(vector<vector<int>> &board,int y, int x){
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(inside(ny,nx) && board[ny][nx] == 1 ) return true;
    }
    return false;
}

pair<bool,int> sol(vector<vector<int>> &board,int y1, int x1, int y2, int x2){
    if(!go(board,y1,x1)) return {false,0}; //패배
    
    pair<bool,int> ret = {false,0};
    if(board[y1][x1] == 1){ //자신의 발판이 있는경우
        int minV = 987654321; int maxV = 0;
        for(int i = 0; i < 4; i++){
            int nx = x1 + dx[i];
            int ny = y1 + dy[i];
            
            if(!inside(ny,nx) || board[ny][nx] == 0) continue;
            
            board[y1][x1] = 0;
            auto [win,move] = sol(board, y2,x2,ny,nx);
            board[y1][x1] = 1;
            
            if(!win){// 내가 이길 경우 _최소한의 움직임으로
                ret.first = true;
                minV = min(minV,move);
            }else if(!ret.first){ //내가 질 경우_최대 움직임으로 플레이
                maxV = max(maxV,move);    
            }  
        }
        ret.second = ret.first ? minV+1 : maxV+1;
    }
    return ret;
}



int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    N = board.size();
    M = board[0].size();
    
    return sol(board,aloc[0],aloc[1],bloc[0],bloc[1]).second;
}