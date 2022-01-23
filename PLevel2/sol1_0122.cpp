#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


bool compare(pair<pair<string,string>,int> A,pair<pair<string,string>,int> B){
   if(A.first.first == B.first.first){
       if(stoi(A.first.second) == stoi(B.first.second)){
           return A.second < B.second;
       }else{
           return stoi(A.first.second) < stoi(B.first.second);
       }
       
   }else{
       return A.first.first < B.first.first;
   }
    
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<pair<pair<string,string>,int>> v;
    for(int i = 0; i < files.size(); i++){
        string HEAD = "",NUMBER = "";
        bool flag = false;
        for(int j = 0; j < files[i].size(); j++){
            if('0' <= files[i][j] && files[i][j] <= '9'){
                NUMBER += files[i][j];
                flag = true;
            }else{
                if(!flag){
                    HEAD += files[i][j];
                }
                if(flag) break;
            }
        }
        transform(HEAD.begin(),HEAD.end(),HEAD.begin(),::tolower);
       
        v.push_back({{HEAD,NUMBER},i});
    }
    sort(v.begin(),v.end(),compare);
    for(int i = 0; i < v.size(); i++){
        answer.push_back(files[v[i].second]);
    }
    
    return answer;
}