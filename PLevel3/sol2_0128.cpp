#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "00:00"; int ans = 0;
    vector<int> line; vector<int> shuttle;
    for(int i = 0; i < timetable.size(); i++){
        int h = stoi(timetable[i].substr(0,2))*60;
        int m = stoi(timetable[i].substr(3,2));
        line.push_back(h+m);
    }
    sort(line.begin(),line.end());
    
    int shuttleT = 540, idx = 0;
    for(int i = 1; i <= n; i++, shuttleT = shuttleT + t){
        int cnt = 0;
        for(int j = idx; j < line.size(); j++){
            if(line[j] <= shuttleT){
                idx++;
                cnt++;
                if(cnt == m) break;
            }
        }
        if(i == n){
            if(cnt == m) ans = line[idx -1]-1;
            else ans = shuttleT;
        }
    }
    int h = ans / 60; int mm = ans % 60;
    answer[0] = h/10 + '0'; 
    answer[1] = h%10 + '0';
    answer[3] = mm/10 + '0';
    answer[4] = mm%10 + '0';

    return answer;
}