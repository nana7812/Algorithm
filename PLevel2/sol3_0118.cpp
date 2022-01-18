#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    int sum = 0;
    int i = 0;
    while(true){
        if(i == truck_weights.size()){
            answer += bridge_length;
            break;
        } 
        answer++;
        if(weight >= sum + truck_weights[i]){
            sum += truck_weights[i];
            q.push(truck_weights[i]);
            i++;
        }else{
            q.push(0);
        }
        
        if(q.size() == bridge_length){
            sum -= q.front();
            q.pop();
        }
    }
    return answer;
}