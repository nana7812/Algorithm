#include <string>
#include <vector>

using namespace std;

int cnt = 0;
void dfs(vector<int> numbers, int target, int sum, int idx){
    if(idx >= numbers.size()){
        if(sum == target) cnt++;
        return;
    }
    dfs(numbers,target,sum+numbers[idx],idx+1);
    dfs(numbers,target,sum-numbers[idx],idx+1);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, target,0,0);
    answer = cnt;
    return answer;
}