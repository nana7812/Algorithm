#include <string>
#include <vector>
#include <queue>

using namespace std;


int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    queue<pair<int,int>> q;
    for(int i = 0; i < priorities.size(); i++){
        pq.push(priorities[i]);
        q.push({priorities[i],i});
    }
    int turn = 0;
    while(!q.empty()){
        int  pr = q.front().first;
        int idx = q.front().second;
        q.pop();
        if(pq.top() == pr){
            turn++;
            if(idx == location){
                answer = turn;
                break;
            }
            pq.pop();
        }else{
            q.push({pr,idx});
        }
        
    }
    return answer;
}