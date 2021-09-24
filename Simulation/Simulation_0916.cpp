#include <iostream>
#include <stdlib.h>
#include <map>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <cstring>
#include <stack>
#include <sstream>
#include <array>
using namespace std;

int N,K;
int start,End,cnt,answer;
int belt[220];
bool visit[220];
queue<int> robot;


int main(){
    cin>> N>> K;
    for(int i = 1; i <= 2* N; i++){
        cin>>belt[i];
    }
    start = 1;
    End = N;
    while(cnt < K){
        answer++;
        //(1)
        start--;
        End--;
        if(start < 1) start = 2*N;
        if(End < 1) End = 2*N;
        //(2)
         int size = robot.size();
        for(int i = 0; i < size; i++){
        int cur = robot.front();
        visit[cur] = false;
        robot.pop();

        if(cur == End) continue;

        int next = cur+1;
        if(next > 2* N) next = 1;
        if(belt[next] >= 1 && visit[next] == false){
            belt[next]--;
            if(belt[next] == 0) cnt++;
            if(next == End) continue;
            visit[next] = true;
            robot.push(next);
        }else{
            visit[cur] = true;
            robot.push(cur);
        }
        }
        //(3)
        if(visit[start] == false && belt[start] >= 1){
        visit[start] = true;
        belt[start]--;
        robot.push(start);

        if(belt[start] == 0) cnt++;
        }
    }
    cout<<answer<<"\n";

    return 0;
}