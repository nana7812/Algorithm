#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> d;
vector<pair<int,int>> v[55];

void dijkstra(){
    priority_queue<pair<int,int>> pq;
    pq.push({0,1});
    d[1] = 0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for(int i = 0; i < v[cur].size(); i++){
            int next = v[cur][i].first;
            int cost2 = v[cur][i].second;
            if(d[next] > cost + cost2){
                d[next] = cost + cost2;
                pq.push({-d[next],next});
            }
        }
    }
    
}

int solution(int N, vector<vector<int> > road, int K) {
    d.resize(N+1,987654321);
    for(int i = 0; i < road.size(); i++){
        int n1 = road[i][0];
        int n2 = road[i][1];
        int c = road[i][2];
        v[n1].push_back({n2,c});
        v[n2].push_back({n1,c});
    }
 
    dijkstra();
    
    int answer = 0;
    for(int i = 1; i <= N; i++){
        if(d[i] <= K){
            answer++;
        }
    }

    return answer;
}