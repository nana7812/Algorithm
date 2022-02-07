#include <string>
#include <vector>
#include <iostream>

using namespace std;

int num[9] = {0,0,1,7,4,2,0,8,10};
long long dp[101];

void minCal(){
    for(int i = 1; i < 9; i++){
        dp[i] = num[i];
    }
    dp[6] = 6;
    for(int i = 9; i < 101; i++){
        dp[i] = dp[i-2]*10 + num[2]; //일단 2부터 만들어 놓
        for(int j = 3; j < 8; j++){
            dp[i] = min(dp[i],dp[i-j]*10+num[j]);
        }
    }
}

int main(){
    int T;
    cin>> T;
    minCal();
    int n;
    while(T--){
        cin>> n;
        cout<<dp[n]<<" ";
        string Max = "";
        while(n){
            if(n%2 != 0){
                cout<<7;
                n -=3;
            }else {
                cout << 1;
                n -= 2;
            }
        }
       cout<<"\n";
    }

}