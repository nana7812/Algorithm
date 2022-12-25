#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {    
    queue<int> q;
    int sum = 0,idx = 0, time = 0; 
    while(true){
        time++;
        
        if(q.size() == bridge_length){ //!!!!!
            sum -= q.front();
            q.pop();
        }
        
        if(sum + truck_weights[idx] <= weight){
            sum += truck_weights[idx];
            q.push(truck_weights[idx]);
            idx++;
            if(idx == truck_weights.size()){ //!!!!!!!!!!!!!!!
                time += bridge_length;
                break;
            }
        }else{
            q.push(0);
        }
    }
    return time;
}
