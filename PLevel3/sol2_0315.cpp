#include <string>
#include <vector>
#include <set>

using namespace std;

int num(int N, int idx){
    //idx == 1 NN /idx == 2 NNN //idx == 3 NNNN
    int result = N;
    for(int i = 1; i <=idx; i++){
        result = result * 10 + N;
    }
    return result;
}

int solution(int N, int number) {
    if(N == number) return 1;
    
    vector<set<int>> dp(8);
    dp[0].insert(N);
    
    for(int k = 1; k < 8; k++){
        
        //숫자 늘리기
        dp[k].insert(num(N,k));
        
        //사칙연산
        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++){
                if(i+j +1 != k) continue;
                for(int a: dp[i]){
                    for(int b : dp[j]){
                    dp[k].insert(a +b);
                    if(a-b > 0) dp[k].insert(a-b);
                    dp[k].insert(a *b);
                    if(a/b > 0) dp[k].insert(a/b);
                    }
                }
            }
        }
         if(dp[k].find(number) != dp[k].end()) return k +1;
    }

    return -1;
}