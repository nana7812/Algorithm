#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    queue<int> turn;
    for(int i = 0; i <priorities.size(); i++){
        pq.push(priorities[i]);
        turn.push(i);
    }
    
    while(true){
        int out = pq.top();
        int idx = turn.front();
        turn.pop();
        if(priorities[idx] == out){
            pq.pop();
            answer++;
            if(idx == location){
                return answer;
            }
        }else{
            turn.push(idx);
        }
         
    }
    
    return answer;
}