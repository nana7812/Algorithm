#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace  std;

int A,B;
bool ch[10000];
void bfs(){
    queue<pair<int,string>> q;
    q.push({A,""});
    ch[A] = true;
    while(!q.empty()){
        int qA = q.front().first;
        string qCommand = q.front().second;
        q.pop();

        //중단지점
        if(qA == B){
            cout<<qCommand<<"\n";
            return;
        }
        int D,S,L,R;
        //D
        D = (qA * 2) % 10000;
        if(ch[D] == false){
            q.push({D,qCommand + "D"});
            ch[D] = true;
        }
        //S
        S = qA - 1 < 0 ? 9999 : qA-1;
        if(ch[S] == false){
            q.push({S,qCommand+"S"});
            ch[S] = true;
        }
        //L
        L = (qA % 1000) * 10 + (qA / 1000);
        if(ch[L] == false){
            q.push({L,qCommand+"L"});
            ch[L] = true;
        }
        //R
        R = (qA / 10) + (qA % 10) * 1000;
        if(ch[R] == false){
            q.push({R,qCommand+"R"});
            ch[R] = true;
        }
    }

}

int main() {

    int T;
    cin>>T;
    while(T--){
        cin>>A>>B;
        memset(ch,false,sizeof(ch));
        bfs();
    }

    return 0;
}