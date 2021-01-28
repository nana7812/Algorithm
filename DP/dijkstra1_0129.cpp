#include <iostream>
#include <vector>
#include <queue>
using  namespace  std;
const int INF = 1000000000;
const int MAX = 20001;
int V,E;
int d[MAX];
vector<pair<int,int>> v[MAX];

void dijkstra(int start){
    priority_queue<pair<int,int>> pq;
    d[start] = 0;
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        int distance = -pq.top().first;
        int current = pq.top().second;
        pq.pop();
        if(d[current] < distance) continue;
        for(int i = 0; i <v[current].size(); i++){
            int next = v[current][i].first;
            int next_distance = v[current][i].second + distance;
            if(next_distance < d[next]){
                d[next] = next_distance;
                pq.push(make_pair(-next_distance,next));
            }
        }
    }

}

int main(){
    cin >> V>>E;
    int s;
    cin>>s;
    int v1,v2,c;
    for(int i = 0; i <E; i++){
        cin>>v1>>v2>>c;
        v[v1].push_back(make_pair(v2,c));
    }
    for(int i = 1; i <= V; i++){
        d[i] = INF;
    }
    dijkstra(s);
    for(int i = 1; i <=V; i++){
        if(d[i] != INF){
            cout<<d[i]<<"\n";
        }else{
            cout<<"INF"<<"\n";
        }
    }
}