#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    if(phone_book.size() == 1){
        return true;
    }
    sort(phone_book.begin(),phone_book.end());
    for(int i = 1; i < phone_book.size(); i++){
        if(phone_book[i].find(phone_book[i-1]) == 0){ // 문자열 찾은 위치가 0이면 접두사
            return false;
        }
    }
    return answer;
}