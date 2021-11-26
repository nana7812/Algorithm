#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
// 정답이 인용횟수가 아닌 0~ 총 편수 사이에서 움직임
int solution(vector<int> citations) {
    int answer = 0;
    int total = citations.size();
    sort(citations.begin(),citations.end());
    for(int k = total; k >= 0; k--){
        for(int i = 0; i < citations.size(); i++){
            if(citations[i] >= k && i + k <= total){
                answer = k;
                return answer;
            }
        }
    }
   
    return answer;
}