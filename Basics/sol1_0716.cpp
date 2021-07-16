#include <string>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.size();
    for(int i = 1; i <= s.size()/2; i++){
        string ss = "";
        string prev = s.substr(0,i);
        int cnt = 1;
        for(int j = i; j <s.size(); j+=i){
            if(prev != s.substr(j,i)){
                if(cnt > 1) ss += to_string(cnt);
                ss += prev;
                prev = s.substr(j,i);
                cnt = 1;
            }else{
                cnt++;
            }
        }
        if(cnt > 1) ss += to_string(cnt);
        ss += prev;
        
        if(answer > ss.size()){
            answer = ss.size();
        }
    }
    
    return answer;
}