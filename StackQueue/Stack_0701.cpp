#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int size = prices.size();
    vector<int> answer(size);
    stack<int> s;
  
    for(int i = 0; i < size; i++){
        while(!s.empty() && prices[i] < prices[s.top()]){
            answer[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }
    
    while(!s.empty()){
        answer[s.top()] = size - s.top() - 1;
        s.pop();
    }
    return answer;
}
