#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    vector<int> startT, endT;
    for(int i = 0; i < lines.size(); i++){
        lines[i].erase(lines[i].length()-1); //lines[i].pop_back();
        int h = stoi(lines[i].substr(11,2)) * 60 * 60 * 1000;
        int m = stoi(lines[i].substr(14,2)) * 60 * 1000;
        int s = stoi(lines[i].substr(17,2)) * 1000;
        int ms = stoi(lines[i].substr(20,3));
        int tS = stof(lines[i].substr(24,5)) * 1000;
        startT.push_back(h+m+s+ms - tS + 1); //시작시간
        endT.push_back(h+m+s+ms);    
    }
    
    for(int i = 0; i < lines.size(); i++){
        int end = endT[i] + 1000;
        int cnt = 0;
        for(int j = i; j < lines.size(); j++){
            if(startT[j] < end){
                cnt++;
            }
        }
        answer = max(answer, cnt);
    }
    return answer;
}