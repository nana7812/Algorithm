#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool compare(vector<string> a, vector<string> b){
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    map<string, bool> m; 
    vector<vector<string>> v;
    string temp;
    int idx = 0;
    bool flag = false;
    vector<string> tempV;
    for(int i = 0; i < s.size()-1; i++){
        if(s[i] == '{'){
            tempV.clear();
            flag = true;
            temp = "";
        }else if('0' <= s[i] && s[i] <= '9'){
            temp += s[i];
        }else if(s[i] == ','){
            if(flag){
                tempV.push_back(temp);
                temp = "";
            }
        }else if(s[i] == '}'){
            tempV.push_back(temp);
            v.push_back(tempV);
            flag = false;
            idx++;
        }
    }
    sort(v.begin(),v.end(),compare);
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            if(!m[v[i][j]]){
                m[v[i][j]] = true;
                answer.push_back(stoi(v[i][j]));
            }
        }
        cout<<"\n";
    }
    
    return answer;
}