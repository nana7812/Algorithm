#include <string>
#include <vector>
#include <iostream>
using namespace std;

int N,M,NM;

void rotate(vector<vector<int>> &key){
    vector<vector<int>> temp = key;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            key[i][j] = temp[M-1-j][i];
        }
    }
}

bool check(int x, int y,vector<vector<int>> &key,vector<vector<int>> board){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            board[x+i][y+j] += key[i][j];
        }
    }

    
    for(int i = M-1; i <= NM-M; i++){
        for(int j = M-1; j <= NM-M; j++){
            if(board[i][j] == 1) continue;
            return false;
        }
    }
    
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    N = lock.size(), M = key.size();
    NM = M*2 + N-2;
   vector<vector<int>> map(NM,vector<int>(NM,0));
    
    //map에 자물쇠 넣깅
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            map[M-1 +i][M-1 +j] = lock[i][j];
        }
    }
    
    
    for(int k = 0; k < 4; k++){
         for(int i = 0; i <= NM-M; i++){
            for(int j = 0; j <= NM -M; j++){
                if(check(i,j,key,map)){
                    answer = true;
                    return answer;
                }
            }
         }
         rotate(key);
    }
    
    return answer;
}