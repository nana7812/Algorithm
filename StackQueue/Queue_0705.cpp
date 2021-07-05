#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace  std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
    int idx = 0, time = 0;
    while (idx < jobs.size() || !pq.empty()) {
        if(idx < jobs.size() && time >= jobs[idx][0]) {
            cout<<"idx: "<<idx<<" ";
            cout<<jobs[idx][1]<<" "<<jobs[idx][0]<<"\n";
            pq.push(make_pair(-jobs[idx][1], jobs[idx][0]));
            idx++;
            continue;
        }
        if(!pq.empty()) {
            time += -pq.top().first;
            answer += time - pq.top().second;
            cout<<"time:"<<time<<"answer:"<<answer<<"\n";
            // 기다린 시간 더해줌
            pq.pop();
        } else {
            time = jobs[idx][0];
        }

    }

    return answer / jobs.size();
}

