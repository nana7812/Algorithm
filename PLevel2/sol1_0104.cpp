#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    vector<char> member = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    sort(member.begin(),member.end());
    do{
        string line = "";
        for(int i = 0; i < member.size(); i++){
            line += member[i];
        }
        bool flag;
        for(int i = 0; i < data.size(); i++){
            flag = false;
            int idxA = line.find(data[i][0]);
            int idxB = line.find(data[i][2]);
            int val = data[i][4] - '0';
            int diff = abs(idxA-idxB);
            if(data[i][3] == '='){
                if(diff == val+1) flag = true;
            }else if(data[i][3] == '>'){
                if(diff > val+1) flag = true;
            }else{
                if(diff < val+1) flag = true;
            }
            if(!flag) break;
        }
        if(flag) {
           answer++; 
        }
  
    }while(next_permutation(member.begin(),member.end()));
    return answer;
}s