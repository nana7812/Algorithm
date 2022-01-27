#include <string>
#include <vector>

using namespace std;

int F[100001];

int solution(int n) {
    F[0] = 0, F[1] = 1;
    for(int i = 2; i <= n; i++){
        F[i] = (F[i-1] + F[i-2]) % 1234567;
    }
    return F[n];
}