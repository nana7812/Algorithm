#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string,pair<pair<int,int>,bool>> car; 
    vector<string> numOfCars;
    map<string,int> fee;
    //차량번호, 들어온시간, 총시간, 들어오면 true
    for(int i = 0; i < records.size(); i++){
        int H = stoi(records[i].substr(0,2))*60;
        int M = stoi(records[i].substr(3,2));
        string carNum = records[i].substr(6,4);
        string state = records[i].substr(11);
        if(state == "IN"){
            if(car[carNum].first.second == 0){ //주차장에 처음들어옴
                numOfCars.push_back(carNum);
            }
            car[carNum].first.first = H +M;
            car[carNum].second = true;
        }else{
            car[carNum].first.second += (H+M) - car[carNum].first.first;
            car[carNum].second = false;
        }  
    }
    
    //요금계산
    int end = 23*60 + 59;
    for(auto itr = car.begin(); itr != car.end(); itr++){
        if(car[itr->first].second){ //안 나갔으면 시간계산
            car[itr->first].first.second += end - car[itr->first].first.first;
        }
        int total = car[itr->first].first.second;
        
        
        fee[itr->first] = fees[1];
        total -= fees[0];
        if(total > 0){
            if(total % fees[2] == 0){
                fee[itr->first] += (total/fees[2]) * fees[3];
            }else{
                fee[itr->first] += (total/fees[2]) * fees[3] + fees[3];
            }
        }
    }
    //사전순
    sort(numOfCars.begin(),numOfCars.end());
    for(int i = 0; i <numOfCars.size(); i++){
        answer.push_back(fee[numOfCars[i]]);
    }
    return answer;
}