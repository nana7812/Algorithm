#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace  std;

int N, K;
bool ch[100001];
int parent[100001];
vector<int> path;

int bfs(){
    queue<pair<int,int>> q;
    q.push({N,0});
    ch[N] = true;
    while(!q.empty()){
        int loc = q.front().first;
        int sec = q.front().second;
        q.pop();

        //중단지점
        if(loc == K){
            int idx = loc;
            while(idx != N){
            path.push_back(idx);
            idx = parent[idx];
            }
            path.push_back(N);

            return sec;
        }


        if(loc+1 < 100001 && ch[loc + 1] == false){
            q.push({loc + 1,sec + 1});
            ch[loc+1] = true;
            parent[loc+1] = loc;
        }
        if(loc - 1 >= 0 && ch[loc - 1] == false){
            q.push({loc-1,sec+1});
            ch[loc - 1] = true;
            parent[loc - 1] = loc;
        }
        if(2 * loc < 100001 &&ch[2 * loc] == false){
            q.push({2*loc,sec+1});
            ch[2*loc] = true;
            parent[2*loc] = loc;
        }

    }
}

int main() {

    cin>> N>> K;
    int cnt = bfs();
    cout<<cnt<<"\n";
    for(int i = path.size()-1; i >= 0; i--){
        cout<<path[i]<<" ";
    }

    return 0;
}
