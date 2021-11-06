#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = -1;
    priority_queue<int> pq;
    for(int i = 0; i < scoville.size(); i++){
        pq.push(-scoville[i]);
    }
    int turn = 0;
    while(!pq.empty() && pq.size() > 1){
        turn++;
        int firstV = -pq.top();
        pq.pop();
        int secondV = -pq.top();
        pq.pop();
        int newV = firstV + secondV*2;
        pq.push(-newV);
        if(-pq.top() >= K){
            answer = turn;
            break;
        }
    }
    //**마지막 한개 남은경우 체크**
    if(-pq.top() >= K){
        answer = turn;
    }
        
    return answer;
}