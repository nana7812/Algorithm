#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> q; int idx = 0;int sum =0; int time = 0;
    while(true){
        if(idx == truck_weights.size()){
         time += bridge_length;
            break;
        }
        time++;
        if(q.size() == bridge_length){
            sum -= q.front();
            q.pop();
        }
        if(q.size() < bridge_length && sum+ truck_weights[idx] <= weight){
            q.push(truck_weights[idx]);
            sum += truck_weights[idx];
            idx++;
        }else if(sum+ truck_weights[idx] > weight){
            q.push(0);
        }
    }
    return time;
}