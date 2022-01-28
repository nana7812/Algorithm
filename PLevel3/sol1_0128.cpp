#include <string>
#include <vector>

using namespace std;
int keySize, lockSize,boardSize;

bool check(vector<vector<int>> & key,int x,int y, vector<vector<int>> board){
    for(int i = x; i < x + keySize; i++){
        for(int j = y; j < y + keySize; j++){
            board[i][j] += key[i-x][j-y];
        }
    }
    
    for(int i = keySize -1; i <= boardSize-keySize; i++){
        for(int j = keySize-1; j <= boardSize-keySize; j++){
            if(board[i][j] == 1)continue; //돌기만 있는 1, 홈 + 돌기  = 1 통과
            //1이 아니면 바로 false 돌기 + 돌기 또는 홈이 존재하는 경우(0)
            return false;
        }
    }
    return true;
}

//열쇠 시계방향 회전
void rotate(vector<vector<int>> &key){
    vector<vector<int>> temp = key;
    for(int i = 0; i < keySize; i++){
        for(int j = 0; j < keySize; j++){
            key[i][j] = temp[keySize-1-j][i];
        }
    }
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    keySize = key.size();
    lockSize = lock.size();
    boardSize = lockSize + (keySize-1)*2;
    vector<vector<int>> board(boardSize,vector<int>(boardSize,0));
    
    //보드판에 자물쇠 이볅
    for(int i = keySize-1; i <= boardSize - keySize; i++){
        for(int j = keySize-1; j <= boardSize - keySize; j++){
            board[i][j] = lock[i - keySize + 1][j-keySize+1];
        }
    }
    //보드판 모든 좌표에서 4방향에 대한 완적 탐색
    for(int k = 0; k < 4; k++){
        for(int i = 0; i <= boardSize-keySize; i++){
            for(int j = 0; j <= boardSize - keySize; j++){
                if(check(key,i,j,board)){
                    answer = true;
                    return answer;
                }
            }
        }
        rotate(key);
    }

    return answer;
}