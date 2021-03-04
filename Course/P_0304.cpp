#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;
    for(int i = cookie.size()-1; i >=1; i--){
        int leftSum = cookie[i-1]; int rightSum = cookie[i];
        int left = i-1; int right = i;
        while(left >= 0 && right < cookie.size()){
            if(leftSum == rightSum){
                answer = max(leftSum,answer);
            }
            if(leftSum < rightSum){
                left--;
                leftSum += cookie[left];
            }else{
                right++;
                rightSum += cookie[right];
            }
        }

    }

    return answer;
}