#include <queue>
using namespace std;


int solution(int n)
{
    int answer = 0;
    while(n != 0){
        if(n %2 !=0){
            n--;
            answer++;
        }else{
            n /=2;
        }
    }

    return answer;
}