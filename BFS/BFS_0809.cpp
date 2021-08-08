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

using namespace std;

int main() {

    int T;
    cin>>T;
    while(T--){
        int n;
        cin>> n;
        map<int, bool> m;
        queue<pair<int,string>> q;
        q.push({1%n,"1"});
        m[1%n] = true;
        bool check = false;
        while(!q.empty()){
            int num = q.front().first;
            string path = q.front().second;
            q.pop();
            if(num == 0){
                cout<<path<<"\n";
                check = true;
                break;
            }
            for(int i = 0; i <=1; i++){
                int nextNum = (num*10 + i)%n;
                if(m[nextNum] == false){
                    q.push({nextNum,path+to_string(i)});
                    m[nextNum] = true;
                }

            }
        }
        if(!check){
            cout<<"BARK"<<"\n";
        }
    }
    return 0;
}