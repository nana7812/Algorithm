#include <string>
#include <vector>

using namespace std;

void sol(int i, int sum, int n, int &ans){
    if(sum >= n){
        if(n == sum) ans++;
        return;
    }
    sol(i+1,sum + i,n,ans);
}

int solution(int n) {
    int answer = 0;
    for(int i = 1; i <= n; i++){
        sol(i,0,n,answer);
    }
    return answer;
}