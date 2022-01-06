#include <iostream>
using namespace std;

long long gcd(long long a, long long b){
    long long res = 0;
    while(b != 0){
        res = a%b;
        a = b;
        b = res;
    }
    return a;
}

long long solution(int w,int h) {
    long long W = w;
    long long H = h;
    long long out = w+h - gcd(w,h);
    
    return W*H - out;
}s