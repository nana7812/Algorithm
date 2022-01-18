#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    return a > b;
}

int solution(vector<int> citations) {
    sort(citations.begin(),citations.end(),compare);
    for(int i = 0; i < citations.size(); i++){
        if(citations[i] <= i){
            return i;
        }
    }
}