#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while(true){
        vector<vector<bool>> c(m, vector<bool>(n,false));
        bool flag = false;
        for(int i = 0; i < m-1; i++){
            for(int j = 0; j < n-1; j++){
                if(board[i][j] == 'X') continue;
                if(board[i][j] == board[i+1][j] && 
                   board[i][j] == board[i][j+1] && 
                   board[i+1][j] == board[i+1][j+1]){
                    c[i][j] = true;
                    c[i+1][j] =true;
                    c[i][j+1] = true;
                    c[i+1][j+1] = true;
                    flag = true;
                }
            }
        }
          
        if(!flag) break;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(c[i][j]){
                    board[i][j] = 'X';
                    answer++;
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = m-1; j > 0; j—){
                int cur = j-1;
                int next = j;
                while(0<= cur && cur < m && 0 <= next && next < m && board[next][i] == 'X'){
                    board[next][i] = board[cur][i];
                    board[cur][i] = 'X';
                    next++;
                    cur++;
                }
            }
        }
        
    }
   ㄱ