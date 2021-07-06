#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace  std;

vector<int> makeTable(string pattern){
    int patternSize = pattern.size();
    vector<int> table(patternSize, 0);
    int j = 0;
    for(int i = 1; i < patternSize; i++){
        while(j > 0 && pattern[i] != pattern[j]){ //
            j = table[j-1];
        }
        if(pattern[i] == pattern[j]){
            table[i] = ++j;
        }
    }
    return table;
}

void kmp(string parent, string pattern){
    vector<int> table = makeTable(pattern);
    int parentSize = parent.size();
    int patternSize = pattern.size();
    int j = 0;
    for(int i = 0; i < parentSize; i++){
        //일치하지 않는 경우가 발생
        while(j > 0 && parent[i] != pattern[j]){
            j = table[j-1];
        }
        if(parent[i] == pattern[j]){
            if(j == patternSize -1){
                cout<<i-patternSize +2 <<"번째에서 찾았습니다";
                j = table[j];
            }else{
                j++;
            }
        }
    }
}


int main() {

    string s = "abcdef";
    for(int i = 0; i <s.size(); i++) {
        string temp = s.substr(i, s.size());
        cout<<temp<<"\n";
    }
    return 0;
}