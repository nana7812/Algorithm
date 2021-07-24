#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    //주어진 문자열이 1개인 경우, 무조건 true
    if(phone_book.size() <= 1) return true;

    sort(phone_book.begin(), phone_book.end()); //사전순으로 정렬

    for(int i = 1; i < phone_book.size(); i++){
        if(phone_book[i].find(phone_book[i-1]) == 0) //이전 값과 비교
            return false;
    }
    return true;
}