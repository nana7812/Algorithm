#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    set<string> s(gems.begin(),gems.end());
   
    int ss = 0; int len = gems.size();
    map<string,int> m;
    for(int i = 0; i < gems.size(); i++){
        m[gems[i]]++;
        
        if(m.size() == s.size()){
            while(m[gems[ss]] > 1){
                m[gems[ss]]--;
                ss++;
            }
        
        
        if(len > (i-ss)){
            len = i -ss;
            answer = {ss+1, i+1};
        }
    } 
    }
    
    return answer;
}