#include <iostream>
#include <queue>
using  namespace  std;

const int MAX = 100000 + 1;
bool check[MAX];


int bfs(int N, int K ){
    queue<pair<int,int>> q;
    
    q.push(make_pair(N,0));
    check[N] = true;
    
    while(!q.empty()){
        int qp= q.front().first;
        int qt = q.front().second;
        q.pop();

        if(qp == K) return qt;

        if(qp + 1 < MAX && !check[qp + 1]){
            q.push(make_pair(qp+1,qt+1));
            check[qp+1] = true;
        }
        if(qp - 1 >= 0 &&!check[qp-1] ){
            q.push(make_pair(qp-1,qt+1));
            check[qp-1] = true;
        }
        if(qp*2 < MAX && !check[qp*2]){
            q.push(make_pair(qp*2,qt+1));
            check[qp*2] = true;
        }
    }
}

int main(){
    int N, K;

    cin>> N>> K;
    cout<<bfs(N,K)<<"\n";
    return 0;
}