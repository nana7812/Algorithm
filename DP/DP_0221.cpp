#include <iostream>
//#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
//#include <set>
using  namespace  std;

const int MAX = 10001;
int n;
int a[MAX];
int d[MAX][3];

void dp(int n){
    d[0][0] = 0; d[0][1] = 0; d[0][2] = 0;
    for(int i = 1; i <=n; i++){
        d[i][0] = max({d[i-1][0],d[i-1][1],d[i-1][2]});
        d[i][1] = d[i-1][0]+a[i];
        d[i][2] = d[i-1][1]+ a[i];
    }
}

int main() {
    cin>> n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    dp(n);

    int ans = max({d[n][0],d[n][1],d[n][2]});
    cout<<ans;

    return 0;
}