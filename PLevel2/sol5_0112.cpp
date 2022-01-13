#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    a--;b--;

    while(true){
        answer++;
        if(a/2 == b/2) break;
        a = a/2; b = b/2;
    }

    return answer;
}