#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

bool check(string s){
    stack<char> st;
    for(int i = 0; i < s.size(); i++){
        if(st.empty()){
            st.push(s[i]);
            continue;
        }
        if(st.top() == '{' && s[i] == '}'||
           st.top() == '(' && s[i] == ')' || 
           st.top() == '[' && s[i] == ']'){
            st.pop();
        }else{
            st.push(s[i]);
        }
    }
    if(st.empty()){
        return true;
    }else{
        return false;
    }
}

int solution(string s) {
    int answer = 0;
    string ss = s;
    bool flag = false;
    for(int i = 0; i < s.size(); i++){
        string ss = s;
        reverse(ss.begin(),ss.begin()+i);
        reverse(ss.begin()+i,ss.end());
        reverse(ss.begin(),ss.end());
        if(check(ss)){
            answer++;
        }
    }
    return answer;
}