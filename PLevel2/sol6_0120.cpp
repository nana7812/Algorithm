#include <string>
#include <vector>
#include <iostream>
using namespace std;

int o = 0; int l = 0;

void sol(vector<vector<int>> &arr, int x, int y, int n){
    
    int temp = arr[x][y];
    bool flag = true;
    for(int i = x; i < x+n; i++){
        for(int j = y; j < y+n; j++){
            if(temp != arr[i][j]){
                flag = false;
                break;
            }
        }
        if(!flag) break;
    }
    
    if(flag){
        if(temp == 0) o++;
        else l++;
        return;
    }else{
        int size = n/2;
        if(size > 0){
            sol(arr,x,y,size);
            sol(arr,x+size,y,size);
            sol(arr,x,y+size,size);
            sol(arr,x+size,y+size,size); 
        }
      
    }

}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    sol(arr,0,0,arr.size());
    answer.push_back(o);
    answer.push_back(l);
    return answer;
}