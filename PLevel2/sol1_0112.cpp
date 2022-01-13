#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> num;
    for(int i = 0; i < numbers.size(); i++){
        num.push_back(to_string(numbers[i]));
    }
    
    sort(num.begin(),num.end(),compare);
    for(int i = 0; i < num.size(); i++){
        answer += num[i];
    }
    
    if(answer[0] == '0'){
        answer = "0";
    } 
    
    return answer;
}