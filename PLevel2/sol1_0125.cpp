#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> win;

void shot(vector<int> &info,vector<int> & temp,int n, int idx, int cnt,int &diff){
    if(idx == info.size()){
        if(cnt != n) return;
        int apeach = 0; int lion = 0;
        for(int i = 0; i < info.size();i++){
            if(info[i] == 0 && temp[i] == 0) continue;
            if(info[i] >= temp[i]){
                apeach += (10-i);
            }else{
                lion += (10-i);
            }
        }
        if(lion > apeach && diff <= lion-apeach){
            if(diff < lion - apeach){
               win.clear(); 
               diff = lion - apeach;
            }
            vector<int> r = temp;
            reverse(r.begin(),r.end());
            win.push_back(r);
        }
        return;    
    }
    for(int i = 0; i + cnt <= n; i++){
        temp[idx] = i;
        shot(info,temp,n,idx+1,cnt+i,diff);
        temp[idx] = 0;
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    vector<int> temp = {0,0,0,0,0,0,0,0,0,0,0};
    int d = 0;
   shot(info, temp,n,0,0,d);
    if(win.size() == 0){
        return {-1};
    }
    sort(win.rbegin(),win.rend());
    for(int i = win[0].size()-1; i >= 0; i--){
        answer.push_back(win[0][i]);
    }
    return answer;
}