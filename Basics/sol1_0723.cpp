#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

map<string,string> m;
vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> inOut;
    stringstream ss;
    string action; string id; string nickname;
    for(int i = 0; i < record.size(); i++){
        ss.str(record[i]);
        ss >> action;
        if(action == "Enter"){
            ss >> id;
            ss >> nickname;
            inOut.push_back(id);
            m[id] = nickname;
            answer.push_back("님이 들어왔습니다.");
        }else if(action == "Leave"){
            ss >> id;
            inOut.push_back(id);
            answer.push_back("님이 나갔습니다.");
        }else{
            ss >> id;
            ss >> nickname;
            m[id] = nickname;
        }
        ss.clear();
    }
    for(int i = 0; i < inOut.size(); i++){
        answer[i] = m[inOut[i]] + answer[i];
    }

    return answer;
}