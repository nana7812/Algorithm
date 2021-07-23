#include <string>
#include <vector>

using namespace std;

bool check(string s){
    int cnt = 0;
    for(char c :s){
        if(c == '(') cnt++;
        else cnt--;
        if(cnt < 0) return false;
    }
    return true;
}

string func(string s){
    if(s == "") return s;
    //2단계
    string u = ""; string v = "";
    int left = 0; int right = 0;
    for(int i = 0; s.size(); i++){
        if(s[i] == '('){
            left++;
        }else{
            right++;
        }
        if(left == right){
            u = s.substr(0,i+1);
            v = s.substr(i+1);
            break;
        }
    }
    if(check(u) == true) return u + func(v);
    else{
        string temp = "(";
        temp += func(v) + ")";
        u = u.substr(1,u.size()-2);
        for(int i = 0; i < u.size(); i++){
            if(u[i] == '(') temp += ')';
            else temp += '(';
        }
        return temp;
    }

}

string solution(string p) {

   if(check(p)) return p;

    return func(p);
}