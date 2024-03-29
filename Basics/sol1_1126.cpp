#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i = 0; i < commands.size(); i++){
        vector<int> temp;
        for(int j = commands[i][0]-1; j < commands[i][1]; j++){
            temp.push_back(array[j]);
        }
        sort(temp.begin(),temp.end());
        int k = commands[i][2] -1;
        answer.push_back(temp[k]);
    }
    return answer;
}