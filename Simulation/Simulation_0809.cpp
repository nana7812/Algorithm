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

int dx[] ={0,-1,0,1};
int dy[] = {1,0,-1,0};
bool a[101][101];
int N;
int y,x,d,g;
vector<int> Dir;


int main() {
    cin >> N;
    for(int i = 0; i < N; i++){
        cin>>y>>x>>d>>g;
        Dir.clear();

        a[x][y] = true;
        x = x + dx[d];
        y = y + dy[d];
        a[x][y] = true;
        Dir.push_back(d);

        for(int j = 0; j < g; j++){
            for(int k = Dir.size()-1; k>=0; k--){
                int dd = (Dir[k]+1)%4;
                x = x+ dx[dd];
                y = y + dy[dd];
                a[x][y] = true;
                Dir.push_back(dd);
            }
        }

    }

    int ans = 0;
    for(int i = 0; i <=99; i++){
        for(int j = 0; j <= 99; j++){
            if(a[i][j] && a[i][j+1]&&a[i+1][j] && a[i+1][j+1]){
                ans += 1;
            }
        }
    }
    cout<<ans<<"\n";

    return 0;
}
