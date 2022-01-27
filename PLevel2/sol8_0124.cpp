#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
    int res = 0;
    while(b != 0){
        res = a % b;
        a = b;
        b = res;
    }
    return a;
}

int lcm (int a, int b){
    return a *b /gcd(a,b);
}

int solution(vector<int> arr) {
    int answer = 1;
    for(int i = 0; i < arr.size(); i++){
        answer = lcm(answer,arr[i]);
    }
    
    return answer;
}ㅗ고