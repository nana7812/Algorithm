#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss;
    int minV = 987654321, maxV = -987654321;
    ss.str(s);
    string temp;
    while(ss>>temp){
        minV = min(minV,stoi(temp));
        maxV = max(maxV,stoi(temp));
    }
    answer = to_string(minV) + ' ' + to_string(maxV);
    return answer;
}