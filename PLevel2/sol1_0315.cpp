#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

char K[] = {'0','1','2','3','4','5','6','7','8','9'};

string notation(int n, int k){
    string s = "";
    while(n != 0){
        s = K[n%k] + s;
        n /= k;
    }
    return s;
}

bool isPrime(long long n){
    if(n <= 1) return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = -1;
    string ss = notation(n,k);
    //cout<<ss<<"\n";
    string temp = ""; int ans = 0;
    for(long long i = 0; i <ss.length(); i++){
        if(ss[i] == '0' && temp.length() > 0){
          //  cout<<temp<<" ";
            if(isPrime(stoll(temp))){
                ans++;
            }
            temp = "";
        }else{
            temp += ss[i];
        }
    }
    
    if(temp.length() > 0){
     //   cout<<temp<<" ";
        if(isPrime(stoll(temp))){
            ans++;
        }
    }
    
    answer = ans;
    return answer;
}