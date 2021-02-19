#include <iostream>
//#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
//#include <set>
using  namespace  std;

const int MAX = 100001;
int N,K;
bool check[MAX];


//**BFS가중치가 다르면 우선순위 큐를 사용!
int BFS(int x,int y){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push(make_pair(x,y)); check[y] = true;
    while(!q.empty()){
        int qx= q.top().first;
        int qy = q.top().second;
        q.pop();
        if(qy == K){
            return qx;
        }
        if(qy*2< MAX && check[qy*2] ==false){
            q.push(make_pair(qx,qy*2));
            check[qy*2] = true;
        }
        if(0<= qy-1 && check[qy-1] == false){
            q.push(make_pair(qx+1,qy-1));
            check[qy-1] = true;
        }
        if(qy+1 <MAX &&check[qy+1] == false){
            q.push(make_pair(qx+1,qy+1));
            check[qy+1] = true;
        }

    }

}

int main() {
    cin>> N>>K;
    cout<< BFS(0,N);

    return 0;
}