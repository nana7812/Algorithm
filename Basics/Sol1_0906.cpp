#include <string>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int result(int n){
    switch(n){
        case 6: return 1;
        case 5: return 2;
        case 4: return 3;
        case 3 : return 4;
        case 2: return 5;
        default : return 6;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zeroCnt = 0; 
    int sameCnt = 0;
    int lottoIdx = 0; int winIdx = 0;
    sort(lottos.begin(),lottos.end());
    sort(win_nums.begin(),win_nums.end());
    while(true){
        if(lottoIdx >=6 || winIdx >= 6){
            break;
        }
        if(lottos[lottoIdx] == 0){
            zeroCnt++;
            lottoIdx++;
        }else{
            if(lottos[lottoIdx] == win_nums[winIdx]){
                sameCnt++;
                lottoIdx++;
                winIdx++;
            }else if(lottos[lottoIdx] > win_nums[winIdx]){
                winIdx++;
            }else if(lottos[lottoIdx] < win_nums[winIdx]){
                lottoIdx++;
            }
        }    
    }
    answer.push_back(result(zeroCnt+sameCnt));
    answer.push_back(result(sameCnt));
    return answer;
}