#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while(true){
        //4블록 확인
        vector<vector<bool>> c(m,vector<bool>(n,false));
        bool flag = false;
        for(int i = 0; i < m-1; i++){
            for(int j = 0; j < n-1; j++){
                if(board[i][j] == 'b') continue;
                if(board[i][j]== board[i+1][j] && board[i][j] == board[i][j+1] && board[i+1][j] == board[i+1][j+1] ){
                    flag = true;
                    c[i][j] = true;
                    c[i][j+1] = true;
                    c[i+1][j] = true;
                    c[i+1][j+1] = true;
                }
            }
        }
        
        //4블록 없음
        if(!flag) break;

        //빈칸 만들기
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(c[i][j]){
                    answer++;
                    board[i][j] = 'b';
                }
            }
        }
   
        //중력_cur control
        for(int i = 0; i < n; i++){
            for(int j = m-2; j >= 0; j--){
                int cur = j;
                int next = j+1;
              if(board[cur][i] =='b') continue;
                while(0 <= cur && cur < m && 0<= next && next < m && board[next][i] == 'b'){
                        board[next][i] = board[cur][i];
                        board[cur][i] = 'b';
                        next++;
                        cur++;
                }
            }
        }
         
        
    }
    return answer;
}