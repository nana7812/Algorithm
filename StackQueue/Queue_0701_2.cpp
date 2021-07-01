#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int>> q;
    priority_queue<int> pq;
    for(int i = 0; i < priorities.size(); i++){
        q.push({i,priorities[i]});
        pq.push(priorities[i]);
    }
    while(!q.empty()){
        int idx = q.front().first;
        int pr = q.front().second;
        q.pop();
        if(pr == pq.top()){
            pq.pop();
            answer++;
            if(idx == location){
                break;
            }
        }else{
            q.push({idx,pr});
        }
    }
    
    return answer;
}