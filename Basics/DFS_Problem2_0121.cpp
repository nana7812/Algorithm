//
// Created by 김정음 on 2021/01/21.
//
#include <string>
#include <vector>

using namespace std;

int total = 0;
int dfs(int x, int sum, vector<int> numbers,int target){
    int total = 0;
    if(x == numbers.size()){
        if(sum == target)
            return 1;
        return 0;
    }

    total += dfs(x+1,sum+(-1*numbers[x]),numbers,target);
    total += dfs(x+1,sum+numbers[x],numbers,target);

    return total;
}


int solution(vector<int> numbers, int target) {

    int answer = dfs(0,0,numbers,target);
    return answer;
}

