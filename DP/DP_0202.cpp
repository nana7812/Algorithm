#include <iostream>
#include <algorithm>
using  namespace  std;

int p[10001];
int d[10001];

int  dp(int n){

    d[0] = 0; p[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=i; j++){
            d[i] = max(d[i],d[i-j]+p[j]);
        }
    }

    return d[n];
}


int main(){
   int n;
   cin>> n;
   for(int i = 1; i <= n; i++){
      cin>>p[i];
   }
   int ans = dp(n);
   cout<<ans;
}