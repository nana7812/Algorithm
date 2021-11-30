#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b){
    return a.size() < b.size();
}

vector<int> solution(string s) {
    bool c[100010] = {false,}; /// 이거 꼭 해줘야함!!!
    vector<int> answer;
    vector<int> v[501];
    int idx = 0;
    for(int i = 1; i < s.size()-1; i++){
        if(s[i] == '{'){
            string temp = "";
            int j = i +1;
            while(true){
                if(s[j] == '}'){
                    break;
                }else if(s[j] == ','){
                    v[idx].push_back(stoi(temp));
                    temp = "";
                }else{
                    temp += s[j];
                }
                j++;
            }
            v[idx].push_back(stoi(temp));
            idx++;
        }
    }
  
    sort(v,v+idx,compare);
    for(int i = 0; i < idx; i++){
        for(int j = 0; j < v[i].size(); j++){
            if(c[v[i][j]] == false){
                answer.push_back(v[i][j]);
                c[v[i][j]] = true;
            }
        }
    }

    return answer;
}