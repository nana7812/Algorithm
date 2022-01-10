#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

bool check(string s){ //올바른 문자열
    stack<char> st;
    for(int i = 0; i < s.size(); i++){
        if(st.empty()){
            st.push(s[i]);
            continue;
        }
        if(st.top() == '(' && s[i] == ')'){
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

string change(string s){
    if(s.length() == 0) return "";
    
    string u,v;
    int right = 0; int left = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '('){
            left++;
        }else{
            right++;
        }
        
        if(left == right){
            u = s.substr(0,i+1);
            v = s.substr(i+1);
            break;
        }
    }
    
    if(check(u)){
        return u + change(v);
    }else{
        string temp = "";
        temp += '(';
        temp += change(v);
        temp += ')';
        for(int i = 1; i < u.length()-1; i++){
            if(u[i] == '('){
                temp += ')';
            }else{
                temp += '(';
            }
        }
       return temp;   
    }
}

string solution(string p) {
    string answer = "";
    if(check(p)){
        answer = p;
    }else{
        answer = change(p);
    }
    
    return answer;
}