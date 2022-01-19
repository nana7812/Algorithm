#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    sort(dungeons.begin(),dungeons.end());
    do{
        int cnt = 0;
        int K = k;
        for(int i = 0; i < dungeons.size(); i++){
            if(K >= dungeons[i][0]){
                K -=dungeons[i][1];
                cnt++;
            }else{
                break;
            }    
        }
        if(cnt > answer) answer = cnt;
        
    }while(next_permutation(dungeons.begin(),dungeons.end()));
    
    return answer;
}