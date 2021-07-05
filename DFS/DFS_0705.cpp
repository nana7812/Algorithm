#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(vector<bool>& visit,vector<vector<string>>& tickets,vector<string>& answer, vector<string>& temp,string from,int cnt){
    temp.push_back(from);
    
    if(cnt == tickets.size()){
        answer = temp;
        return true;g
    }
    
    for(int i = 0; i <tickets.size(); i++){
        if(tickets[i][0] == from && visit[i] == false){
            visit[i] = true;
            bool check = dfs(visit,tickets,answer, temp,tickets[i][1],cnt+1);
            if(check == true) return true;
            visit[i] = false;
        }
    }
    temp.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer,temp;
    vector<bool> visit(tickets.size(),false);
    sort(tickets.begin(),tickets.end());
    dfs(visit,tickets,answer, temp,"ICN",0);
    
    return answer;
}