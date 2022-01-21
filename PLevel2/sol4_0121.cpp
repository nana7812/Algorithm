#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string msg) {
    vector<string> dic = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    vector<int> answer;
    for(int i = 0; i < msg.size(); ){
        string temp = ""; int idx = 0;
        int j;
        for(j = 1; j <= msg.size() - i; j++){
            temp = msg.substr(i,j);
            if(find(dic.begin(),dic.end(),temp) != dic.end()){
                idx = find(dic.begin(),dic.end(),temp) - dic.begin() +1;
                if(i + j == msg.size()){
                    dic.push_back(temp);
                    answer.push_back(idx);
                }
            }else{
                dic.push_back(temp);
                answer.push_back(idx);
                break;
            }
        }
       i += j-1;  
    }
    return answer;
}