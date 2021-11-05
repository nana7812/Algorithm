#include <string>
#include <vector>
//#include <stack>

using namespace std;

//stack말고 이걸로 하자 stack으로 하면 코드 더 복잡해짐 ex_ ')'인데 st 비워져있는 경우 까지 생각해야함
bool check(string s){
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(') cnt++;
        else cnt--;
        if(cnt < 0 ) return false;
    }
    return true;
}

// bool check(string s){
//     stack<char> st;
//     for(int i = 0; i <s.size(); i++){
//         if(s[i] == '('){
//             st.push(s[i]);
//         }else if(s[i] == ')'){
//             if(st.empty()) return false;
//             st.pop();
//         }
//     }
//     if(st.empty()){
//         return true;
//     }
//     return false;
// }
string func(string s){
    //1단계
    if(s == "") return s;
    //2단계
    int left = 0; int right = 0;
    string u = ""; string v = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            left++;
        }else{
            right++;
        }
        if(1 <= left && 1 <= right && left == right){
            u = s.substr(0,i+1);
            v = s.substr(i+1);
            break;
        }
    }
    //3단계
    if(check(u)){
        return u + func(v);
    }else{
        string temp = "(";
        temp += func(v) +")";
        for(int i = 1; i < u.size()-1; i++){
            if(u[i] == '('){
                temp += ')';
            }else{
                temp += '(';
            } 
        }
        return temp; 
    }
}

string solution(string p) {
    string answer = "";
    //일단 올바른 문자열인지 확인하기
    if(check(p)) answer = p;
    else{
        answer = func(p);
    }
    return answer;
}