#include <string>
#include <queue>
#include <vector>

using namespace std;

int cnt[360000]; //00:00:00 ~ 99:59:59를 초로 변환

string TimeToString(int i){
    string t = "";
    int h = i /3600;
    int m = (i%3600)/60;
    int s = i % 60;
    
    if(h <= 9) t += '0';
    t += to_string(h);
    t += ':';
    if(m <= 9) t += '0';
    t += to_string(m);
    t += ':';
    if(s <= 9) t += '0';
    t += to_string(s);
    return t;
}

int sTimeToInt(string s){
    int h = stoi(s.substr(0,2))*3600;
    int m = stoi(s.substr(3,2))*60;
    int ss = stoi(s.substr(6,2));
    
    return h + m + ss;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int playT = sTimeToInt(play_time);
    int advT = sTimeToInt(adv_time);
    
    for(int i = 0; i < logs.size(); i++){
        int start = sTimeToInt(logs[i].substr(0,8));
        int end = sTimeToInt(logs[i].substr(9));
        for(int j = start; j < end; j++){
            cnt[j]++;
        }
    }
    
    queue<int> q;
    int startPoint = 0;
    long long temp = 0;
    long long result = 0;
    
    for(int i = 0; i < advT; i++){
        temp += cnt[i];
        q.push(cnt[i]);
    }
    result = temp;
    
    for(int i = advT; i < playT; i++){
        temp -= q.front();
        q.pop();
        temp += cnt[i];
        q.push(cnt[i]);
        if(result < temp){
            result = temp;
            startPoint = i - advT +1;
        }
    }
    answer = TimeToString(startPoint);
    
    
    
    return answer;
}