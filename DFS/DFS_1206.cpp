#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool visit[10001] = {false,};
vector<string> answer;
bool dfs(vector<vector<string>> tickets,string start,int cnt){
    answer.push_back(start);
    if(cnt == tickets.size()){
        return true;
    }
    for(int i = 0; i < tickets.size(); i++){
        if(visit[i] == false  && tickets[i][0] == start){
            visit[i] = true;
            bool T = dfs(tickets,tickets[i][1], cnt+1);
            if(T == true) return true;
            visit[i] = false;
        }
    }
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    //vector<string> answer;
    sort(tickets.begin(),tickets.end());
    dfs(tickets,"ICN",0);
    return answer;
}