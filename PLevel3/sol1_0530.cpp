#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    answer.resize(2,0);
    int total = 0;
    map<string,bool> m;
    for(int i = 0; i < gems.size(); i++){
        if(!m[gems[i]]){
            m[gems[i]] = true;
            total++;
        }
    }
    
    int s = 0; int t = 0; int len = gems.size();
    map<string,int> cnt;
    for(int i = 0; i < gems.size(); i++){
        if(cnt[gems[i]] == 0){
            t++;
        }
        
        cnt[gems[i]]++;
        
        while(cnt[gems[s]] > 1){
            cnt[gems[s]]--;
            s++;
        }
        
        if(t == total){
            if(len > i-s){
                answer[0] = s+1;
                answer[1] = i+1;
                len = i -s;
            }
            
        }
        
    }
    
    return answer;
}