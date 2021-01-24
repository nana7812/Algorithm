#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using  namespace  std;


string solution(string number, int k) {
    string answer = "";

    int index = 0;
    for(int i = k; i <number.size(); i++){
        char max ='0';
        for(int j = index; j <= i; j++){
           if(max < number[j]){
               max = number[j];
               index = j;
           }
        }
       // cout<<max<<"\n";
        answer += max;
        index++;
    }

    return answer;
}