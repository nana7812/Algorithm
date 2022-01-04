#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.length();
    for(int i = 1; i <= s.length()/2; i++){
        string ans = "";
        int cnt = 1;
        string prev = s.substr(0,i);
        for(int j = i; j < s.length(); j+=i){
            string temp = s.substr(j,i);
            if(temp == prev){
                cnt++;
            }else{
                if(cnt > 1){
                     ans += to_string(cnt);
                }
                ans += prev;
                prev = temp;
                cnt = 1;
            }
        }
        if(cnt > 1){
            ans += to_string(cnt);
        }
        ans += prev;
       // cout<<i<<" "<<ans<<" ";
        
        if(answer > ans.length()){
            answer = ans.length();
        }
    }
    return answer;
}