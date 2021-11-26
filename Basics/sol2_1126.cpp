#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(string s1, string s2){ // 문자열 더하기 !!! 3 30 34 !! 
    return s1 + s2 > s2+ s1;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for(int i = 0; i < numbers.size(); i++){
        v.push_back(to_string(numbers[i]));
    }
    sort(v.begin(),v.end(),compare);
    for(int i = 0; i < v.size(); i++){
        if(v[0] == "0"){ // !!!0으로만 이루어진 경우!!!!
            answer = "0";
            break;
        }
        answer += v[i];
    }
    
    return answer;
}