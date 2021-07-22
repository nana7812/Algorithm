#include <string>
#include <vector>

using namespace std;


string solution(int n) {
    string answer = "";
    char a[3] = {'4','1','2'};
    while(n > 0){
        int res = n%3;
        answer = a[res] + answer;
        n = (n-1)/3;
    }
    
    return answer;
}