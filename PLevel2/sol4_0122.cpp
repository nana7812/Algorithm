#include <string>
#include <vector>
#include <iostream>
using namespace std;

int cnt(int n){
    int c = 0;
    while(n != 0){
        if(n % 2 == 1) c++;
        n /= 2;
    }
    return c;
}

int solution(int n) {
    int answer = 0;
    int oneCnt = cnt(n);
    for(int i = n+1;;i++){
        int c = cnt(i);
        if(oneCnt == c){
            answer = i;
            break;
        }
    }
    return answer;
}