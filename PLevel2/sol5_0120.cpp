#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(long long idx = left; idx <= right; idx++){
        int i = idx /n;
        int j = idx %n;
        if(i < j){
            answer.push_back(j+1);
        }else{
            answer.push_back(i+1);
        }
    }
    return answer;
}