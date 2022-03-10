#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer(n,'O');
    stack<int> st; // 삭제된 행
    vector<int> prev;
    vector<int> next;

    for (int i = 0; i < n+2; i++) {
        prev.push_back(i - 1);
        next.push_back(i + 1);
    }
    k++;
    for (int i = 0; i < cmd.size(); i++) {
        if (cmd[i][0] == 'U') {
            for (int j = 0; j < stoi(cmd[i].substr(2)); j++) {
                k = prev[k];
            }
        }
        else if (cmd[i][0] == 'D') {
            for (int j = 0; j < stoi(cmd[i].substr(2)); j++) {
                k = next[k];
            }
        }
        else if (cmd[i][0] == 'C') {
            st.push(k); 
            next[prev[k]] = next[k];
            prev[next[k]] = prev[k];

            if (next[k] == n+1) k = prev[k];
            else k = next[k];
        }
        else if (cmd[i][0] == 'Z') {
            int v = st.top();
            next[prev[v]] = v;
            prev[next[v]] = v;
            st.pop();
        }
    }

    while(!st.empty()){
        answer[st.top()-1] = 'X';
        st.pop();
    }

    return answer;
}