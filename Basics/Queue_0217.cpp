#include <string>
#include <vector>
#include<queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    int sum = 0;
    int new_t = 0;
    queue<int> q;
    while(true){
        if(new_t == truck_weights.size()){
            time += bridge_length;
            break;
        }
        time++;

         if(q.size() == bridge_length){
            sum -= q.front();
            q.pop();
        }
        if(sum+truck_weights[new_t] <= weight){
            q.push(truck_weights[new_t]);
            sum += truck_weights[new_t];
            new_t++;
        }else{
            q.push(0);
        }


    }
    return time;
}