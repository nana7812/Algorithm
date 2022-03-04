#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<int> &stones, int mid , int k){
    int cnt = 0;
    for(int i = 0; i < stones.size(); i++){
        if(stones[i] - mid <= 0) cnt++;
        else cnt = 0; //연달아 나오지 않는다면 다시 0
        if(cnt >= k) return true; //여기다 넣어햐겠지.. 연달아 나오는게 k이상이면 중단
    }
    
    return false;
}

int solution(vector<int> stones, int k) {
    int start = 1; int end = *max_element(stones.begin(),stones.end());
    while(start <= end){
        int mid = (start + end) / 2;
        if(check(stones,mid, k)) end = mid-1;
        else start = mid + 1;
    }
    return start;
}
