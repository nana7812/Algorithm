#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

string cal(string a, string b, string what){
    long long na = stoll(a); long long nb = stoll(b);
    if(what == "*"){
        return to_string(na * nb);
    }else if(what == "-"){
        return to_string(na - nb);
    }else{
        return to_string(na + nb);
    }
 
}

long long solution(string expression) {
    long long answer = 0;
    
    map<string,bool> m;
    vector<string> exp;
    vector<string> priority;
    string temp = "";
    for(int i = 0; i <expression.size(); i++){
        if(expression[i] == '*' || expression[i] == '+' || expression[i] == '-'){
            exp.push_back(temp);
            temp = "";
            temp += expression[i];
            exp.push_back(temp);
            if(!m[temp]){
                m[temp] = true;
                priority.push_back(temp);
            }
            temp = "";
        }else{
            temp += expression[i];
        }
    }
    exp.push_back(temp);
    
    
    sort(priority.begin(),priority.end());
    do{
        vector<string> temp;
        for(int i = 0; i <exp.size(); i++){
            temp.push_back(exp[i]);
        }
        
        for(int i = 0; i < priority.size(); i++){
           // cout<<priority[i]<<" ";
            for(int j = 0; j < temp.size(); j++){
                if(temp[j] == priority[i]){
                    temp[j-1] = cal(temp[j-1],temp[j+1],temp[j]);
                    temp.erase(temp.begin() + j+1);
                    temp.erase(temp.begin() + j);
                    j--;
                }
            }
        }
        if(answer < abs(stoll(temp[0]))){
            answer = abs(stoll(temp[0]));
        }
    }while(next_permutation(priority.begin(),priority.end()));
    return answer;
}