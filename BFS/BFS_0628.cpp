#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace  std;

map<string,int> m;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
string end = "123456780";
string start;


int bfs(){
    queue<string> q;
    q.push(start);
    m[start] = 0;
    while (!q.empty()){
        string qs = q.front();
        q.pop();

        //종료 시점
        if(qs == "123456780"){
            return m[qs];
        }

        int idx = qs.find('0');
        int x = idx / 3;
        int y = idx % 3;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<= nx && nx < 3 && 0 <= ny && ny < 3){
                string change = qs;
                swap(change[x * 3 + y],change[nx * 3 + ny]);
                if(m[change] == 0){
                    m[change] = m[qs] + 1;
                    q.push(change);
                }
            }
        }
    }
    return -1;
}

int main() {

    int a;
    for(int i = 0; i < 9; i++){
        cin>> a;
        char temp = a + '0';
        start += temp;
    }
    int ans = bfs();

    cout<<ans;

    return 0;
}