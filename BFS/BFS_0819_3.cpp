#include <iostream>
#include <stdlib.h>
#include <map>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <cstring>
#include <stack>
#include <sstream>
#include <array>
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
map<long long,bool> m;
long long s,t;
string answer; bool ok = false;

void BFS(){
    queue<pair<long long,string>> q;
    q.push({s,""});
    m[s] = true; //생각 좀
    while (!q.empty()){
        long long num = q.front().first;
        string qString = q.front().second;
        q.pop();
        if(num == t){
            answer = qString;
            ok = true;
            return;
        }
        if(m[num*num] == false){
            q.push({num*num,qString+'*'});
            m[num*num] = true;
        }
        if(m[num+num] == false){
            q.push({num+num,qString+'+'});
            m[num+num] = true;
        }
        if(m[num-num] == false){
            q.push({num-num,qString+'-'});
            m[num-num] = true;
        }
        if(num != 0){
            if(m[num/num] == false){
                q.push({num/num,qString+'/'});
                m[num/num] = true;
            }
        }
    }

}


int main(){
    cin>> s>> t;
    if(s == t){
        cout<<0<<"\n";
        return 0;
    }
    BFS();
    if(ok){
        cout<<answer<<"\n";
    }else{
        cout<<-1<<"\n";
    }
    return 0;
}