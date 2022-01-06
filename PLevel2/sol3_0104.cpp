#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    char val[3] = {'1','2','4'};
    string answer = "";
    while(n != 0){
        n--;
        answer = val[n%3] + answer;
        n = n/3;
    }
    return answer;
}