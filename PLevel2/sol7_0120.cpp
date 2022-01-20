#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i= 0; i < skill_trees.size(); i++){
        vector<int> idx;
        for(int j = 0; j < skill.size(); j++){
            int it = skill_trees[i].find(skill[j]);
            idx.push_back(it);
        }
        
      
        bool check = false, flag = true;
        int id = 0;
        for(int i = 0; i < idx.size(); i++){
            if(idx[i] == -1){
                check = true;
                continue;
            }
            if((check && idx[i] >= 0) || (!check && id > idx[i])){
                flag = false;
            }
            id = idx[i];
        }
        if(flag){
            answer++;
        }  
    }
    return answer;
}