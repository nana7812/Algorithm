#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> resDay;
    for(int i = 0; i < progresses.size(); i++){
        int r = 100 - progresses[i];
        int day = r/speeds[i];
        if(r % speeds[i] != 0){
            day += 1;
        }
        resDay.push_back(day);
    }
    stack<int> st;
    int value = 0;
    value = resDay[0];
    st.push(resDay[0]);
    for(int i = 1; i < resDay.size(); i++){
        if(value >= resDay[i]){
            st.push(resDay[i]);
        }else{
            int size = st.size();
            answer.push_back(size);
            while(!st.empty()){
                st.pop();
            }
            value = resDay[i];
            st.push(resDay[i]);
        }
    }
    answer.push_back(st.size());
    
    return answer;
}