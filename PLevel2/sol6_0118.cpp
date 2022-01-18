#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int idx = 0;
    for(int i = k; i < number.size(); i++){
        char temp = '0';
        for(int j = idx; j <= i; j++){
            if(temp < number[j]){
                temp = number[j];
                idx = j;
            }
        }
        idx++;
        answer += temp;
    }
    return answer;
}