#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int h = 1; h <= yellow; h++){
        if(yellow % h == 0){
            int w = yellow / h;
            if((h+2) *(w+2) == yellow + brown){
                    answer.push_back(w+2);
                    answer.push_back(h+2);
                    break;
            }
        }
    }
    sort(answer.rbegin(),answer.rend());
    return answer;
}