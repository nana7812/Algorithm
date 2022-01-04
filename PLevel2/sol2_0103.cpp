#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <queue>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string,string> m;
    queue<pair<string, string>> q;
    stringstream ss;
    string cmd, uid, nick;
    for(int i = 0; i < record.size(); i++){
        ss.str(record[i]);
        ss>>cmd; ss>>uid; ss>>nick;
        if(cmd == "Enter"){
            m[uid] = nick;
            q.push({cmd,uid});
        }else if(cmd == "Change"){
            m[uid] = nick;
        }else{
            q.push({cmd,uid});
        }
        ss.clear();
    }
    while(!q.empty()){
        string ans = "";
        string qCmd = q.front().first;
        string qId = q.front().second;
        q.pop();
        ans += m[qId];
        if(qCmd == "Enter"){
            ans +="님이 들어왔습니다.";
        }else{
            ans += "님이 나갔습니다.";
        }
        answer.push_back(ans);
    }
    return answer;
}