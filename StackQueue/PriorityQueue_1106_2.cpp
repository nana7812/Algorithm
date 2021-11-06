#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(),jobs.end());
    priority_queue<pair<int,int>> pq;// 소요, 도착
    int idx = 0; int time = 0; int cur = 0;
    while(idx < jobs.size() || !pq.empty()){ // 모든 잡은 확인했고 pq를 계산해야하는 경우
        if(idx < jobs.size() &&cur >= jobs[idx][0]){ // idx 조건 필수 왜냐면 위에 //인경우는 아래 코드를 실행하면 안됨
            pq.push({-jobs[idx][1],jobs[idx][0]});
            idx++;
            continue;
        }
        if(!pq.empty()){
            cur += -pq.top().first;
            time += cur - pq.top().second; // 현재시간에서 도착한 시간 빼면 = 걸린시간
            pq.pop();
        }else{
            //현재시각보다 대기열에 있는 시간이 더 크면 그 대기열 시간 가져오기  
            cur = jobs[idx][0];
        }
    }
    answer = time/jobs.size();
    return answer;
}