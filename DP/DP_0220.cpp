#include <iostream>
//#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
//#include <set>
using  namespace  std;

const int MAX = 100001;
int s[2][MAX];
int d[MAX][3];

void dp(int n){
    d[0][0] = 0; d[0][1] = 0; d[0][2] = 0;
    for(int i = 1; i <= n; i++){
        d[i][0] = max({d[i-1][0],d[i-1][1],d[i-1][2]});
        d[i][1] = max(d[i-1][0],d[i-1][2]) + s[0][i];
        d[i][2] = max(d[i-1][0],d[i-1][1]) +s[1][i];
    }

}

int main() {
    int t;
    cin>> t;
    while(t--){
        int n;
        cin>> n;
       for(int i = 0; i <2; i++){
           for(int j = 1; j <=n; j++){
               cin>>s[i][j];
           }
       }
        dp(n);
        int ans = max({d[n][0],d[n][1],d[n][2]});
        cout<< ans<<"\n";
    }
    return 0;
}
