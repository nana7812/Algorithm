#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    stack<int> st;
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