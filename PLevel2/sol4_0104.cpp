#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    for(int i = 0; i < progresses.size(); i++){
        int res = 100 - progresses[i];
        int d = 0;
        if(res%speeds[i] == 0){
            d = res/speeds[i];
        }else{
            d= res/speeds[i] + 1;
        }
        q.push(d);
    }
    int pivot = q.front();
    int cnt = 0;
    while(!q.empty()){
        int v = q.front();
        if(pivot >= v){
            q.pop();
            cnt++;
        }else{
            answer.push_back(cnt);
            pivot = v;
            cnt = 0;
        }
    }
    if(cnt > 0){
        answer.push_back(cnt);
    }
    
    
    return answer;
}