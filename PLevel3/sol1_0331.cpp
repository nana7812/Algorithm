#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int solution(vector<vector<int>> jobs) {
    int total = 0;
    int done = 0;
    int time = 0;
    int idx = 0; 
    sort(jobs.begin(),jobs.end()); //이거 중요중요
    priority_queue<pair<int,int>> pq; //소요시간, 요청
    while(true){
        if(pq.empty()){
            pq.push({-jobs[idx][1],jobs[idx][0]});
            time = jobs[idx][0];
            idx++;
            continue;
        }
        
        time += -pq.top().first;
        total += (time - pq.top().second);
        pq.pop();
        done++;
        if(done >= jobs.size()) break;
        
        while(idx < jobs.size() && jobs[idx][0] <= time){
            pq.push({-jobs[idx][1],jobs[idx][0]});
            idx++;
        }
    }
    
    return total/jobs.size();
}