#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;


int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int N, M;


bool sol(vector<string> &board,int x, int y, int what){
    bool v[N][M][4]; 
    memset(v,false,sizeof(v));
    v[x][y][0] = v[x][y][1] = v[x][y][2] = v[x][y][3] = true;
    queue<pair<pair<int,int>,pair<int,bool>>> q;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0 > nx || nx >= N || 0 > ny || ny >= M) continue;
        if(board[nx][ny] == '.' || board[nx][ny] == what){
            q.push({{nx,ny},{i,false}});
            v[nx][ny][i] = true;
        }  
    }
                        
    while(!q.empty()){
        int qx = q.front().first.first;
        int qy = q.front().first.second;
        int qd = q.front().second.first;
        bool qb = q.front().second.second;
        q.pop();
        if(board[qx][qy] == what){
            board[qx][qy] = '.';
            board[x][y] = '.';
            return true;
        }
        for(int i = 0; i < 4; i++){
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            if(0 > nx || nx >= N || 0 > ny || ny >= M) continue;
            if(v[nx][ny][i]) continue;
            if(board[nx][ny] == '.' || board[nx][ny] == what){
                if(i == qd){
                    q.push({{nx,ny},{i,qb}});
                    v[nx][ny][i] = true;
                }else{
                    if(qb == false){
                        if((qd == 0 && i == 1) || (qd == 1 && i == 0) || (qd == 2 && i == 3) || (qd == 3 && i == 2)) continue;
                        q.push({{nx,ny},{i,true}});
                        v[nx][ny][i] = true;
                    }
                }
            }
        }
        
    }
    return false;
}




string solution(int m, int n, vector<string> board) {
    string answer = "";
    N = m; M = n;
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
            int what = board[reserve[i].second.first][reserve[i].second.second];
            flag = sol(board,reserve[i].second.first,reserve[i].second.second,what);
            if(flag){
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