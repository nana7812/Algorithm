#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {

    int answer = 0;
    string s = "ACFJMNRT";
    do{
        bool ok = true;
        for(int i = 0; i <n; i++){
            int a = s.find(data[i][0]);
            int b = s.find(data[i][2]);
            if(data[i][3] == '='){
                if(abs(a-b)-1 != data[i][4]-'0' ) ok = false; 
            }
            else if(data[i][3] == '>'){
                if(abs(a-b) <= data[i][4]-'0' + 1) ok = false; 
            }else if(data[i][3] == '<'){
                if(abs(a-b) >= data[i][4]-'0' + 1) ok = false; 
            }
            if(ok == false) break;
        }
        if(ok == true) answer++;

    }while(next_permutation(s.begin(),s.end()));
    return answer;
}"