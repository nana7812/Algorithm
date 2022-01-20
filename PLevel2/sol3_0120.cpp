#include <string>
#include <vector>

using namespace std;

string bin(int num){
    string s = "";
    while(num != 0){
        if(num %2 == 0){
            s = '0' + s;
        }else{
            s = '1' + s;
        }
        num /= 2;
    }
    return s;
}

vector<int> solution(string s) {
    vector<int> answer;
    int turn = 0, erase = 0;
    while(s != "1"){
        turn++;
        int temp = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0'){
                erase++;
            }else{
                temp++;
            }
        }
        
        s = bin(temp);
    }
    answer.push_back(turn);
    answer.push_back(erase);
    return answer;
}