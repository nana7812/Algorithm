#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace  std;

int A,B,C;
vector<int> ans;
bool ch[201][201];

void bfs(){
    queue<pair<pair<int,int>,int>> q;
    q.push({{0,0},C});

    while(!q.empty()){
        int a = q.front().first.first;
        int b = q.front().first.second;
        int c = q.front().second;
        q.pop();
        
        if(ch[a][b] == true) continue;
        ch[a][b] = true;

        if(a == 0){
            ans.push_back(c);
        }

        //a->b
        if(a+b > B)
            q.push({{(a+b)-B,B},c});
        else
            q.push({{0,(a+b)},c});
        //a->c
        if(a+c > C)
            q.push({{(a+c)-C,b},C});
        else
            q.push({{0,b},(a+c)});
        //b->a
        if(b+a > A)
            q.push({{A,(b+a)-A},c});
        else
            q.push({{(a+b),0},c});
        //b->c
        if(b+c > C)
            q.push({{a,(b+c)-C},C});
        else
            q.push({{a,0},(b+c)});
        //c->a
        if(a+c > A)
            q.push({{A,b},(a+c)-A});
        else
            q.push({{(a+c),b},0});
        //c->b
        if(c+b > B)
            q.push({{a,B},(b+c)-B});
        else
            q.push({{a,(b+c)},0});
    }

}


int main() {

    cin>>A>>B>>C;
    bfs();
    sort(ans.begin(),ans.end());

    for(int i = 0; i <ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    
    return 0;
}