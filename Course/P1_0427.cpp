#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    
    for(int i = 0; i < moves.size(); i++){
        int p = moves[i]-1;
        for(int j = 0; j < board.size(); j++){
            if(board[j][p] !=0){
                if(!s.empty() && s.top() == board[j][p])
                {
                    answer+=2;
                    s.pop();
                }else{
                    s.push(board[j][p]);
                }
                board[j][p] = 0;
                break;
            }
        }
    }
    
    
    return answer;
}