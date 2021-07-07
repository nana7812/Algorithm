#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace  std;
const int MAX = 100000 + 1;
int N, K;
int minSec = 0;
int cnt = 0;
bool check[MAX];
void bfs(){
    queue<pair<int,int>> q;
    q.push({N,0});
    check[N] = true;
    while(!q.empty()){
        int loc = q.front().first;
        int sec = q.front().second;
        q.pop();

        check[loc] = true;

        if(loc == K && cnt == 0){
            minSec = sec;
            cnt++;
            continue;
        }
        if(loc == K && cnt != 0 && minSec == sec){
            cnt++;
            continue;
        }


        if(0 <= loc -1 && !check[loc - 1]){
            q.push({loc-1,sec+1});
        }
        if(loc +1 < MAX && !check[loc + 1]){
            q.push({loc+1,sec+1});
        }
        if(loc * 2 < MAX && !check[loc * 2]){
            q.push({loc*2 ,sec+1});
        }
    }

}


int main() {

    cin>>N>>K;
    bfs();
    cout<<minSec<<" "<<cnt<<"\n";
    return 0;
}