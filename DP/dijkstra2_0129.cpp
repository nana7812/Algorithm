#include <iostream>
#include <vector>
#include <queue>
using  namespace  std;

const int MAX = 10001;
const int INF = 100000000;
int N;
int m;
vector<pair<int,int>> v[MAX];
int d[MAX];

void dijkstra(int start){
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(start,0));
    d[start] = 0;
    while(!pq.empty()){
        int current = pq.top().first;
        int distance = -pq.top().second;
        pq.pop();
        if(d[current] < distance) continue;
        for(int i = 0; i < v[current].size(); i++){
            int next = v[current][i].first;
            int next_distance = v[current][i].second + distance;
            if(next_distance < d[next]){
                d[next] = next_distance;
                pq.push(make_pair(next,-next_distance));
            }
        }
    }

}

int main(){
    cin>> N;
    cin>> m;
    int s,e,c;
    for(int i = 0; i < m; i++){
        cin>>s>>e>>c;
        v[s].push_back(make_pair(e,c));
    }
    for(int i = 1; i <= N; i++){
        d[i] = INF;
    }
    int c1,c2;
    cin>> c1>> c2;

    dijkstra(c1);

    cout<<d[c2];
}