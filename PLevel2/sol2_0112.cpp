#include <string>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

bool idx[9];
bool check[10000000];

bool isPrime(int n){
    if(n < 2) return false;
    for(int i = 2; i <=sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}

int dfs(string numbers, int total, int cnt, string s){
    int ans = 0;
    
    if(cnt == total){
        if(check[stoi(s)] == false && isPrime(stoi(s))){
            check[stoi(s)] = true;
            return 1;
        }
        return 0;
    }
    
    for(int i = 0; i < numbers.size(); i++){
        if(idx[i] == false){
            idx[i] = true;
            ans += dfs(numbers, total, cnt+1, s + numbers[i]);
            idx[i] = false;
        }
    }
    
    return ans;
}

int solution(string numbers) {
    int answer = 0;
    for(int i = 1; i <= numbers.size(); i++){
        answer += dfs(numbers,i,0,"");
    }
    return answer;
}