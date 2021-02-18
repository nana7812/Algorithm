#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using  namespace  std;

const int MAX = 501;
int n;
vector<int> v[MAX];
int inDegree[MAX],t[MAX],result[MAX];

void topologySort(){
    queue<int> q;
    //집입차수가 0인 노드를 큐에 삽
    for(int i = 1; i <=n; i++){
        if(inDegree[i] == 0) {
            result[i] = t[i];
            q.push(i);
        }
    }
    //정렬이 완전히 수행되려면 정확하게 n개의 노드를 방문
    for(int i = 1; i <=n; i++){
        int x = q.front();
        q.pop();
        for(int i = 0; i < v[x].size(); i++){
            int y = v[x][i];
            //선행조건 2개 이상일 때 주의!
            result[y] = max(result[y],result[x]+ t[y]);
            if(--inDegree[y] == 0){
                q.push(y);
            }
        }
    }

    for(int i = 1; i <=n; i++){
        cout<<result[i]<<"\n";
    }
 
}

int main() {
   cin>> n;

   for(int i = 1; i <=n; i++){
       cin>> t[i];
       while(true){
           int pre;
           cin>> pre;
           if(pre == -1) break;
           inDegree[i]++;
           v[pre].push_back(i);
       }
   }

   topologySort();
   return 0;
}