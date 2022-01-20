#include <string>
#include <vector>
#include <map>
#include <deque>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    for(int i = 0; i < cities.size(); i++){
         transform(cities[i].begin(),cities[i].end(),cities[i].begin(),::tolower);
    }
    if(cacheSize == 0){
        return cities.size() * 5;
    }
    
    map<string, bool> m;
    deque<string> q;
    int time = 5;
    m[cities[0]] = true;
    q.push_back(cities[0]);
    for(int i = 1; i < cities.size(); i++){
        if(m[cities[i]]){
            vector<string> temp; 
            while(q.front() != cities[i]){
                temp.push_back(q.front());
                q.pop_front();
            }
            q.pop_front();
            q.push_back(cities[i]);
            for(int j = temp.size()-1; j >=0; j—){
                q.push_front(temp[j]);
            }
            time += 1;
        }else{
            if(q.size() >= cacheSize){
                m[q.front()] = false;
                q.pop_front();
            }
            q.push_back(cities[i]);
            m[cities[i]] = true;
            time += 5;
        }
    }
    answer = time;
    return answer;
}