#include <string>
#include <vector>
#include <set>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer(n,'X');
    
    set<int> table;
    stack<int> hist;
    for(int i = 0; i < n; i++) table.insert(i);
    
    auto itr = table.find(k); // 선택된 행의 위치를 나타내는 정수 K itr 찾기 
    
    for(string s :cmd){
        if(s[0] == 'U' || s[0] == 'D'){
            int x = stoi(s.substr(2));
            if(s[0] == 'U') while(x--) itr = prev(itr);
            else while(x--) itr = next(itr);
        }else if(s[0] == 'C'){
            hist.push(*itr);
            itr = table.erase(itr);
            if(itr == table.end()) itr = prev(itr);
        }else if(s[0] == 'Z'){
            table.insert(hist.top());
            hist.pop();
        }else return "";
    }
    
    for(int i : table) answer[i] = 'O'; 
    
    return answer;
}