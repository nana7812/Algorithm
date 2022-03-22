#include <string>
#include <vector>

using namespace std;

vector<vector<vector<bool>>> v(105,vector<vector<bool>>(105,vector<bool>(2,false)));
int N;

bool check(int x, int y, int a){
    if(a == 0){
        if(y == N || v[x][y+1][0] || v[x][y][1] || (x-1 >= 0 && v[x-1][y][1])) 
           return true;
    }else if(a == 1){
        if(v[x][y+1][0] ||v[x+1][y+1][0]|| (x-1 >= 0 && v[x-1][y][1] && v[x+1][y][1]))
            return true;
    }
    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    N= n;
    for(int i = 0; i < build_frame.size(); i++){
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];
        y = N-y;

        if(b == 0){
            v[x][y][a] = false;
            for(int r = 0 ; r <= N; r++){
                for(int c = 0; c <= N; c++){
                    for(int k = 0; k < 2; k++){
                        if(v[r][c][k] && !check(r,c,k)){
                            v[x][y][a] = true;
                            break;
                        }
                    }
                }
            }
        }else{
           if(check(x,y,a)){
               v[x][y][a] = true;
           }
        }
    }
    
   
    for(int i = 0; i <= N; i++){
        for(int j = N; j >= 0; j--){
            for(int k = 0; k < 2; k++){
                if(v[i][j][k] == 1){
                    answer.push_back({i,N-j,k});
                }
            }
        }
    }
    return answer;
}