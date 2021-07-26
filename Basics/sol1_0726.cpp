
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<long long> num;
    vector<char> exp;
    vector<char> loc;
    string n = "";
    for(int i = 0; i < expression.size(); i++){
        if(expression[i] == '+'|| expression[i] == '-'|| expression[i] == '*'){
            num.push_back(stoi(n));
            n = "";
            if(find(exp.begin(),exp.end(),expression[i]) == exp.end())
                exp.push_back(expression[i]);
            loc.push_back(expression[i]);
        }else{
            n += expression[i];
        }
    } 
    num.push_back(stoi(n));
    sort(exp.begin(),exp.end());

    do{
        vector<long long> temp_num = num;
        vector<char> temp_loc = loc;

        for(int i = 0; i < exp.size(); i++){
            for(int j = 0; j <temp_loc.size(); j++){
                if(exp[i] == temp_loc[j]){
                    if(temp_loc[j] == '+'){
                        temp_num[j] = temp_num[j] + temp_num[j+1];
                    }else if(temp_loc[j] == '-'){
                        temp_num[j] = temp_num[j] - temp_num[j+1];
                    }else if(temp_loc[j] =='*'){
                        temp_num[j] = temp_num[j] * temp_num[j+1];
                    }
                    temp_loc.erase(temp_loc.begin()+j);
                temp_num.erase(temp_num.begin()+j+1);
                j--;
                }
            }
        }
        if(answer < abs(temp_num[0]))
            answer = abs(temp_num[0]);
    }while(next_permutation(exp.begin(),exp.end()));

    return answer;
}