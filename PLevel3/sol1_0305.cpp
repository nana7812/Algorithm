#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 987654321;
    int size = weak.size();
    for(int i = 0; i <size; i++){
        weak.push_back(weak[i]+n);
    }
    
    sort(dist.begin(),dist.end());
    do{
        for(int i = 0; i <size; i++){ //시작점 부분만
            int start = weak[i];
            int end = weak[i+size-1];
            
            for(int j = 0; j < dist.size(); j++){
                start += dist[j];
                if(start >= end){
                    answer = min(answer,j+1);
                    break;
                }
                for(int k = i+1; k < i+size; k++){ //시작에 따른 원형부분까지
                    if(start < weak[k]){
                        start = weak[k];
                        break;
                    }
                }   
            }       
        }  
    }while(next_permutation(dist.begin(),dist.end()));
    
    if(answer == 987654321) return -1;
    return answer;
}