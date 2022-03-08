#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;

    int M = board[0].size();
    vector<vector<int>> sol(N+1,vector<int>(M+1,0));
    for(int i = 0; i < skill.size(); i++){
        int type = skill[i][0];
        int r1 = skill[i][1];
        int c1 = skill[i][2];
        int r2 = skill[i][3];
        int c2 = skill[i][4];
        int degree = skill[i][5];
        
        if(type == 1) degree *= -1;
        sol[r1][c1] += degree;
        sol[r1][c2+1] += -degree;
        sol[r2+1][c1] += -degree;
        sol[r2+1][c2+1] += degree;
    }
    //위 아래 누적합
    for(int i = 0; i < M; i++){
        for(int j = 1; j < N; j++){
            sol[j][i] += sol[j-1][i];
        }
    }
    //왼쪽 오른쪽 누적합
    for(int i = 0; i < N; i++){
        for(int j = 1; j < M; j++){
            sol[i][j] += sol[i][j-1];
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            board[i][j] += sol[i][j];
            if(board[i][j] >= 1) answer++;
        }
    }
    
    return answer;
}