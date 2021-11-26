#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int cnt, int sum, int target){
    if(cnt >= numbers.size()){
        if(sum == target){
            answer++;
        }
        return;
    }
    dfs(numbers,cnt+1,sum + numbers[cnt],target);
    dfs(numbers,cnt+1,sum - numbers[cnt],target);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers,0,0,target);
    return answer;
}