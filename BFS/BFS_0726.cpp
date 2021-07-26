#include <iostream>
#include <stdlib.h>
//#include <map>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <cstring>
#include <stack>
#include <sstream>


using namespace std;

int F,S,G,U,D;
bool check[1000001];

void BFS(){
    queue<pair<int,int>> q;
    q.push({S,0});
    check[S] = true;
    while(!q.empty()){
        int floor = q.front().first;
        int button = q.front().second;
        q.pop();
        if(floor == G){
            cout<<button<<"\n";
            return;
        }
        if(floor + U <= F && check[floor+U] == false){
            q.push({floor+U,button+1});
            check[floor+U] = true;
        }
        if(floor - D >=1 && check[floor - D] == false){
            q.push({floor-D,button+1});
            check[floor-D] = true;
        }
    }
    cout<<"use the stairs"<<"\n";
    return;
}


int main() {
    cin>>F>>S>>G>>U>>D;
    BFS();
    return 0;
}