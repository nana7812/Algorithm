#include <string>
#include <vector>

using namespace std;

vector<vector<vector<int>>> map;

bool check(int x, int y, int a){
    if(a == 0){
        if(!y || (y-1 >= 0 && map[0][x][y-1]) || map[1][x][y] ||(x-1 >= 0 && map[1][x-1][y])) 
            return true;
    }else{
        if((y-1 >= 0 && map[0][x][y-1]) || (y-1 >= 0 && map[0][x+1][y-1]) || (x-1 >= 0 && map[1][x-1][y] && map[1][x+1][y]))
            return true;
    }
    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    map.assign(2,vector<vector<int>>(n+1,vector<int>(n+1)));
    for(int i = 0; i < build_frame.size(); i++){
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];
        if(b == 0){ //삭제
            map[a][x][y] = 0;
            for(int i = 0; i<= n; i++){
                for(int j = 0; j <= n; j++){
                    for(int k = 0; k < 2; k++){
                        if(map[k][i][j] == 1 && !check(i,j,k)){
                            map[a][x][y] = 1;
                            break;
                        }
                            
                    }
                }
            }
        }else{
            if(check(x,y,a)) map[a][x][y] = 1;
        }
    }
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; k < 2; k++){
                if(map[k][i][j] == 1){
                    answer.push_back({i,j,k});
                }
            }
        }
    }
    return answer;
}