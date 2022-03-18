#include <string>
#include <vector>

using namespace std;

int maxDiff;
vector<int> answer(1,-1);


bool isBetter(vector<int> & ryan){
    for(int i = 10; i >= 0; i--){
        if(ryan[i] > answer[i]) return true;
        else if(ryan[i] < answer[i]) return false;
    }
}

void solve(int idx, int arrows, vector<int> & ryan, vector<int> & apeach){
    
    if(idx == 11 || arrows == 0){
        ryan[10] += arrows; // 어피치 이기고 왔는데 화살 남으면 아래 쪽에 많이 있을 수록 좋으니까
        
        //이제 점수 계산
        int ryanScore = 0, apeachScore = 0;
        for(int i = 0; i < 11; i++){
            if(ryan[i] > apeach[i]) ryanScore += (10-i);
            else if(apeach[i] > 0) apeachScore += (10-i);
        }
        
        int diff = ryanScore - apeachScore;
        if(diff > 0 && diff >= maxDiff){
            if(maxDiff == diff && !isBetter(ryan)) return;
            
            maxDiff = diff;
            answer = ryan;
        }
        ryan[10] -= arrows;
        return;
    }
    
    
    //어피치보다 하나 더 많아야 이길 수 있음
    if(apeach[idx] < arrows){
        ryan[idx] += apeach[idx] + 1;
        solve(idx+1,arrows - apeach[idx]-1,ryan,apeach);
        ryan[idx] -= apeach[idx] +1;
    }
    

    solve(idx+1,arrows,ryan,apeach);
}

vector<int> solution(int n, vector<int> info) {
    vector<int> ryan(11,0);
    solve(0,n,ryan,info);
    return answer;
}