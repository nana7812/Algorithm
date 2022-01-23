#include <string>
#include <vector>
#include <iostream>

using namespace std;

char c[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

string nFunc(int num, int n){
    string s ="";
    if(num == 0){
        return "0";
    }
    while(num != 0){
        s = c[num%n] + s;
        num /= n;
    }
    return s;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string ss = "";
    for(int i = 0; i < t*m; i++){
        ss += nFunc(i,n);
    }
    for(int i = p; i <= m * (t-1) + p; i +=m){
        answer = answer + ss[i-1];
    }
    
    return answer;
}