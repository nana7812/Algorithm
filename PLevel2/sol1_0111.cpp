#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//문자열 다듬기
string trim(string s){
    string ss = "";
    for(int i = 0; i < s.length(); i++){
        if('A'<= s[i] && s[i] <= 'Z'){
            ss += s[i] - 'A' + 'a';
            continue;
        }
        ss +=s[i];
    }
    return ss;
}

vector<string> makeCom(string s){
    vector<string> v;
    for(int i = 0; i < s.length()-1; i++){
        if('a'<= s[i] && s[i]<='z' && 'a' <= s[i+1] && s[i+1] <= 'z')
        v.push_back(s.substr(i,2));
    }
    return v;
}


int solution(string str1, string str2) {
    int answer = 0;
    str1 = trim(str1); str2 = trim(str2);
    vector<string> com1 = makeCom(str1); 
    vector<string> com2 = makeCom(str2);
    int u = com1.size() + com2.size();
    int n = 0;
    if(com1.size() > com2.size()){
        for(int i = 0; i < com2.size(); i++){
            auto itr = find(com1.begin(),com1.end(),com2[i]);
            if(itr != com1.end()){
                n++;
                com1.erase(itr);
            }
        }
    }else{
       for(int i = 0; i < com1.size(); i++){
            auto itr = find(com2.begin(),com2.end(),com1[i]);
            if(itr != com2.end()){
                n++;
                com2.erase(itr);
            }
        } 
    }
    
    u-=n;
    
    if(u == 0){
        return 65536;
    }else{
        answer = n*65536/u;
    }
    

    return answer;
}