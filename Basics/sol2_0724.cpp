#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int v[101][101];


int sol(int x1,int y1,int x2,int y2){
    int minV = 10001;
    int temp = v[x1][y1];
    
    for(int i = x1; i < x2; i++){
        v[i][y1] = v[i+1][y1];
        minV = min(minV,v[i][y1]);
    }
    for(int i = y1; i < y2; i++){
        v[x2][i] = v[x2][i+1];
        minV = min(minV,v[x2][i]);
    }
    for(int i = x2; i >x1; i--){
        v[i][y2] = v[i-1][y2];
        minV = min(minV,v[i][y2]);
    }
    for(int i = y2; i >y1+1; i--){
        v[x1][i] = v[x1][i-1];
        minV = min(minV,v[x1][i]);
    }
    
    v[x1][y1+1] = temp;
    minV = min(minV,v[x1][y1+1]);
    return minV;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
   
    vector<int> answer;

    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){
            v[i][j] = (i-1)*columns+j;
        }
    }
    for(int i = 0; i < queries.size(); i++){
       
       int ans = sol(queries[i][0],queries[i][1],queries[i][2],queries[i][3]);
        answer.push_back(ans);
    }
    

    return answer;
}