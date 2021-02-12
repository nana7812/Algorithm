#include <iostream>
using  namespace  std;


const long long mod = 10007;
long long d[10001][10];

void dp(int x){
    for(int i =0; i <=9; i++){
        d[1][i] = 1;
    }
    for(int i = 2; i <=x; i++){
        for(int j = 0; j <=9; j++){
            for(int k = 0; k <=j; k++){
                d[i][j] += d[i-1][k];
                d[i][j] %=mod;
            }
        }
    }

}

int main()
{
   int n;
   cin>> n;
   dp(n);

   long long ans = 0;
   for(int i = 0; i <=9; i++){
       ans += d[n][i];
   }
   cout<<ans%mod;
    return 0;
}