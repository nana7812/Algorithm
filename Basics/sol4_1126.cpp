#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int rotate(vector<vector<int>> &v,int x1, int y1, int x2, int y2){
    int ans = 987654321; 
    int temp1 = v[x1][y2];
    ans = min(ans, temp1);
    for(int i = y2; i > y1; i--){
        v[x1][i] = v[x1][i-1];
        ans = min(ans, v[x1][i]);
    }
    int temp2 = v[x2][y2];
    ans = min(ans, temp2);
    for(int i = x2; i > x1+1; i--){
        v[i][y2] = v[i-1][y2];
        ans = min(ans, v[i][y2]);
    }
    v[x1+1][y2] = temp1;
    int temp3 = v[x2][y1];
    ans = min(ans, temp3);
    for(int i = y1; i < y2 -1; i++){
        v[x2][i] = v[x2][i+1];
        ans = min(ans, v[x2][i]);
    }
    v[x2][y2-1] = temp2;
    for(int i = x1; i < x2-1; i++){
        v[i][y1] = v[i+1][y1];
         ans = min(ans, v[i][y1]);
    }
    v[x2-1][y1] = temp3;
    
    return ans;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> m(rows+1,vector<int>(columns+1));
    int num = 1;
    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){
            m[i][j] = num;
            num++;
        }
    }
    for(int i = 0; i < queries.size(); i++){
        answer.push_back(rotate(m,queries[i][0],queries[i][1],queries[i][2],queries[i][3]));
    }
    
    return answer;
}