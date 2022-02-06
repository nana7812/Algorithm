#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string name) {
    int answer = 0;
    int move = name.length();
    for(int i = 0; i < name.length(); i++){
        answer += min(name[i]-'A','Z'-name[i]+1);
        
        int idx = i+1;
        while(idx < name.length() && name[idx] == 'A'){
            idx++;
        }
        int a = i;
        int b = name.length() - idx;
        move = min(move,min(2*a+b,a+2*b));
    }
    answer += move;
    return answer;
}