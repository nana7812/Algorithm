#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

map<string,string> m; //id,nick

vector<string> solution(vector<string> record) {
    vector<pair<string,string>> list; //action, id
    vector<string> answer;
    stringstream ss;
    string action; string id; string nick;
    for(int i = 0; i < record.size(); i++){
        ss.str(record[i]);
        ss>>action;
        if(action == "Enter"){
            ss>>id;
            ss>>nick;
            m[id] = nick;
            list.push_back({"IN",id});   
        }else if(action == "Leave"){
            ss>>id;
            list.push_back({"OUT",id});
        }else if(action == "Change"){
            ss>>id;
            ss>>nick;
            m[id] = nick;
        }
        ss.clear();
    }
    for(int i = 0; i < list.size(); i++){
        string ans = "";
        ans += m[list[i].second];
        if(list[i].first == "IN"){
            ans += "님이 들어왔습니다.";
        }else{
            ans += "님이 나갔습니다.";
        }
        answer.push_back(ans);
    }
    return answer;
}