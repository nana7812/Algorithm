#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = -1;
    priority_queue<int> pq;
    for(int i = 0; i < scoville.size(); i++){
        pq.push(-scoville[i]);
    }
    int turn = 0;
    while(pq.size() >= 2){
        int s1 = -pq.top();
        pq.pop();
        int s2 = -pq.top();
        pq.pop();
        int nS = s1 + s2*2;
        pq.push(-nS);
        turn++;
        if(-pq.top() >= K){
            answer = turn;
            break;
        }
    }
    return answer;
}