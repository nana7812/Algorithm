#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    long long sum = 0;
    priority_queue<int> pq;
    for(int i = 0; i <works.size(); i++){
        pq.push(works[i]);
    }
    while(n--){
        int v = pq.top() -1;
        pq.pop();
        if(v > 0){
            pq.push(v);
        }
        if(pq.size() == 0) return 0;   
    }
    while(!pq.empty()){
        int t = pq.top();
        answer += t*t;
        pq.pop();
    }   
    return answer;
}