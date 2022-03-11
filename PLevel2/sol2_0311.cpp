#include <string>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    if(cacheSize == 0) return cities.size() * 5;
    
    for(int i = 0; i < cities.size(); i++){
        transform(cities[i].begin(),cities[i].end(),cities[i].begin(),::tolower);
    }
        
    list<string> cache;
    for(int i = 0; i < cities.size(); i++){
        auto itr = find(cache.begin(),cache.end(),cities[i]);
        if(itr == cache.end()){
            answer += 5;
            if(cache.size() == cacheSize){
                cache.pop_front();
            }
            cache.push_back(cities[i]);
        }else{
            answer += 1;
            cache.erase(itr);
            cache.push_back(cities[i]);
        }
    }
   
    return answer;
}