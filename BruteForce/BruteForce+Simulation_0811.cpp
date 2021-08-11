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

int N,M,H;
int ladder[40][40];

int start(int c){
    int r = 1;
    while(r<= H){
        if(ladder[r][c] == 1){
            c +=1;
        }else if(ladder[r][c] == 2){
            c -= 1;
        }
        r+=1;
    }
    return c;
}

bool go(){
    for(int i = 1; i <= N; i++){
        int res = start(i);
        if(res != i) return false;
    }
    return true;
}

int main() {
    cin>>N>>M>>H;
    for(int i = 0; i < M; i++){
        int a,b;
        cin>>a>>b;
        ladder[a][b] = 1;
        ladder[a][b+1] = 2;
    }
    vector<pair<int,int>> temp;
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= N-1; j++){
            if(ladder[i][j] != 0)  continue;
            if(ladder[i][j+1] != 0) continue;
            temp.push_back({i,j});
        }
    }
    int ans = -1;
    if(go()){
        cout<<0<<"\n";
        return 0;
    }
    int tempSize = temp.size();
    for(int i = 0; i <tempSize; i++){
        int x1 = temp[i].first;
        int y1 = temp[i].second;
        if(ladder[x1][y1] != 0 || ladder[x1][y1+1] != 0) continue;
        ladder[x1][y1] = 1;
        ladder[x1][y1+1] = 2;
        if(go()){
            if(ans == -1 || ans > 1){
                ans = 1;
            }
        }
        for(int j = i+1; j < tempSize; j++){
            int x2 = temp[j].first;
            int y2 = temp[j].second;
            if(ladder[x2][y2] != 0 || ladder[x2][y2+1] != 0) continue;
            ladder[x2][y2] = 1;
            ladder[x2][y2+1] = 2;
            if(go()){
                if(ans == -1 || ans > 2){
                    ans = 2;
                }
            }
            for(int k = j+1; k <tempSize; k++){
                int x3 = temp[k].first;
                int y3 = temp[k].second;
                if(ladder[x3][y3] != 0 || ladder[x3][y3+1] != 0) continue;
                ladder[x3][y3] = 1;
                ladder[x3][y3+1] = 2;
                if(go()){
                    if(ans == -1 || ans > 3){
                        ans = 3;
                    }
                }
                ladder[x3][y3] = 0;
                ladder[x3][y3+1] = 0;
            }
            ladder[x2][y2] = 0;
            ladder[x2][y2+1] = 0;
        }
        ladder[x1][y1] = 0;
        ladder[x1][y1+1] = 0;
    }
    cout<<ans<<"\n";
    return 0;
}