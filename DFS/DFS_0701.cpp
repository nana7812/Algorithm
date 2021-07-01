#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool c[51];
int answer = 51;

void dfs(string word,string target, vector<string> words, int cnt){
    if(word == target){
        answer = min(answer,cnt);
        return;
    }
    
    for(int i = 0; i < words.size(); i++){
        int equal = 0;
        for(int j = 0; j < words[i].size(); j++){
            if(word[j] != words[i][j]) equal++;
            if(equal == 2) break;
        }
        
        if(equal == 1 && c[i] == false){
            c[i] = true;
            dfs(words[i],target,words,cnt+1);
            c[i] = false;
        } 
        
    }
}


int solution(string begin, string target, vector<string> words) {
    dfs(begin,target,words,0);
    if(answer == 51) answer = 0;
    return answer;
}