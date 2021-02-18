#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using  namespace  std;

const int MAX = 32001;
int n, m;
vector<int> v[MAX];
int inDegree[MAX];

void topologySort(){
    int result[MAX];
    queue<int> q;
    //집입차수가 0인 노드를 큐에 삽
    for(int i = 1; i <=n; i++){
        if(inDegree[i] == 0) q.push(i);
    }
    //정렬이 완전히 수행되려면 정확하게 n개의 노드를 방문
    for(int i = 1; i <=n; i++){
        if(q.empty()){
            return;
        }
        int x = q.front();
        q.pop();
        result[i] = x;
        for(int i = 0; i < v[x].size(); i++){
            int y = v[x][i];
            if(--inDegree[y] == 0){
                q.push(y);
            }
        }
    }

    for(int i = 1; i <=n; i++){
        cout<<result[i]<<" ";
    }
    return;

}

int main() {
   cin>> n>> m;
   int a,b;
   for(int i = 0; i < m; i++){
       cin>> a>> b;
       v[a].push_back(b);
       inDegree[b]++;
   }
   topologySort();

   return 0;
}