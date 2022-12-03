#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int move = name.length();
    for(int i = 0; i < name.length(); i++){
        answer += min(name[i]-'A','Z'-name[i]+1);
        int j = i+1;
        while(j < name.length() && name[j] == 'A') j++;
        
        int l = i;
        int r = name.length() - j;
        
        //다시 풀어도 모르는...
        move = min({move,2*l+r,l + 2*r});
    }
    answer += move;
    return answer;
}