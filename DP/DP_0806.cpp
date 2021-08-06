#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    long long d[20001];
    d[1] = 1; d[2] = 2;
    for(int i = 3; i <=n; i++){
        d[i] = d[i-1] + d[i-2];
        d[i]= d[i]%1234567;
    }
    return d[n]%1234567;
}