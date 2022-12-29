#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    answer.resize(prices.size(),0);
    
    stack<pair<int,int>> st;
    for(int i = 0; i < prices.size(); i++){
        if(st.empty()|| st.top().second <= prices[i]){
            st.push({i,prices[i]});
        }else{
            while(!st.empty() && st.top().second > prices[i]){
                answer[st.top().first] = i - st.top().first;
                st.pop();
            }
            st.push({i,prices[i]});
        }  
    }
    
    while(!st.empty()){
       answer[st.top().first] = prices.size() -1 - st.top().first;
       st.pop(); 
    }
    return answer;
}
