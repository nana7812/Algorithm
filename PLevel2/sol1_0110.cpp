#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<char,int> menu;
vector<char> tempM;

void dfs(vector<string> orders,int total,int idx,int cnt,string s,vector<string> & ans,int &maxV){
    if(cnt == total){
        int check = 0;
        for(int i = 0; i < orders.size(); i++){
            bool flag = true;
            for(int j = 0; j < s.size(); j++){
                if(orders[i].find(s[j]) == -1){
                    flag = false;
                }
                if(!flag) break;
            }
            if(flag) check++;
        }
        if(check >= maxV){
            if(check > maxV){
            ans.clear();
            maxV = check;
            }
            ans.push_back(s);
        }

        return;
    }
    
    for(int i = idx; i <tempM.size(); i++){
        dfs(orders,total, i+1, cnt+1, s+tempM[i],ans,maxV);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int i = 0; i < orders.size(); i++){
        for(int j = 0; j < orders[i].size(); j++){
              menu[orders[i][j]]++;
        }
    }
    for(auto it = menu.begin(); it != menu.end(); it++){
        if(it->second >= 2){
            tempM.push_back(it->first);
        }
    }
    
    for(int i = 0; i < course.size(); i++){
        vector<string> ans;
        int maxV = 2;
        dfs(orders,course[i],0,0,"",ans,maxV);
        for(int j = 0; j < ans.size(); j++){
            answer.push_back(ans[j]);
        }
    }
    
    sort(answer.begin(),answer.end());
    return answer;
}