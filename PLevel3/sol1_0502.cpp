#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> startT;
vector<int> endT;

int solution(vector<string> lines) {
    int answer = 0;
    for(int i = 0; i < lines.size(); i++){
        lines[i].erase(lines[i].length()-1);
        int h = stoi(lines[i].substr(11,2)) * 60 * 60 * 1000;
        int m = stoi(lines[i].substr(14,2)) * 60 * 1000;
        int s = stoi(lines[i].substr(17,2)) * 1000; //1초 = 1000;
        int ms = stoi(lines[i].substr(20,3));
        int ts = stof(lines[i].substr(24,5)) * 1000;  //string s = "2.5" stof(s) : 2.5
        
        startT.push_back(h+m+s+ms+1 - ts);
        endT.push_back(h+m+s+ms);
    }
    
    for(int i = 0; i < lines.size(); i++){
        int end = endT[i] + 1000; //1초 경과
        int cnt = 0;
        for(int j = i; j < lines.size(); j++){ //i 기준으로 1초 동안 
            if(startT[j] < end){ //1초구간내 _ j는 i보다 종료시간이 늦기때문에 j 시작시작만 신경씀
                cnt++;
            }
        }
        answer = max(answer,cnt);
    }
        
    return answer;
}