#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    string temp = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' '){
            if(temp != ""){
                 transform(temp.begin()+1,temp.end(),temp.begin()+1, ::tolower);
                 if('a'<=temp[0] && temp[0] <= 'z') temp[0] = toupper(temp[0]);
                 answer += temp;
            }
            answer += ' ';
            temp = "";
        }else{
            temp += s[i];
        }
    }
        
    if(temp != ""){
        transform(temp.begin()+1,temp.end(),temp.begin()+1, ::tolower);
        if('a'<=temp[0] && temp[0] <= 'z') temp[0] = toupper(temp[0]);
        answer += temp;
    }
    return answer;
}