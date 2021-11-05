#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
map<string,int> m;



void dfs(string order,int total,string s){
    if(s.size() == total){
       m[s]++;
       return;
    }
    for(int i = 0; i < order.size(); i++){
        dfs(order.substr(i+1),total,s + order[i]);
    }

}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int i = 0; i < orders.size(); i++){
        sort(orders[i].begin(),orders[i].end());
    }
    for(int i = 0; i < course.size(); i++){
        for(int j = 0; j < orders.size();j++){
            dfs(orders[j],course[I],"");//!!! 주문한 알파벳 중에서 조합만들기!!!!
        }
        int combi = 2;
        for(auto it = m.begin(); it != m.end(); it++){ //맵 for문!!!
            combi = max(combi,it->second);
        }
        for(auto it = m.begin(); it != m.end(); it++){
            if(it->second == combi){
                answer.push_back(it->first);
            }
        }
       m.clear(); //맵 비우기
        
    }
    sort(answer.begin(),answer.end());
    return answer;
}