#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> dic;
char alpha[5] = {'A', 'E', 'I', 'O', 'U'};

void dfs(int total,int cnt, string s){
    if(cnt == total){
        dic.push_back(s);
        return;
    }
    for(int i = 0; i < 5; i++){
        dfs(total,cnt+1,s+alpha[i]);
    }
}

int solution(string word) {
    int answer = 0;
    for(int i = 1; i <= 5; i++){
        dfs(i,0,"");
    }
    sort(dic.begin(),dic.end());
    answer = find(dic.begin(),dic.end(),word) - dic.begin() +1;
    
    return answer;
}