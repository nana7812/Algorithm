#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    transform(s.begin(),s.end(),s.begin(),::tolower);
    s[0] = toupper(s[0]);
    for(int i = 1; i < s.length(); i++){
        if(s[i-1] == ' ' && ('a' <= s[i] && s[i] <= 'z'))
            s[i] = toupper(s[i]);
    }
    
    answer = s;
    return answer;
}c