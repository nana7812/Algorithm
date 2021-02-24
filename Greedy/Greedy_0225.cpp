#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
//#include <set>
using  namespace  std;

//그리디문제_ 경우에 따라 영향을 주는 범위가 달라지는지 확인기 해보기

int n;
string input, output;

char change(char a){
    if(a == '0'){
        return '1';
    }else{
        return '0';
    }
}
int ans = 987654321; bool flag = false;//input이랑 output이랑 같아서 count가 0인지, 불가능해서 0인지 판단하기 위한 변수
void solve(string s,int count){

    for(int i = 1; i < s.size(); i++){
        if(s[i-1] != output[i-1]){
            s[i-1] = change(s[i-1]);
            s[i] = change(s[i]);
            s[i+1] = change(s[i+1]);
            count++;
        }
        if(s == output){
            flag = true;
            ans = min(ans,count);
            break;
        }
    }
    return;
}

int main() {

    cin>> n;
    cin>> input>>output;
    solve(input,0);
    string copy = input;
    copy[0] = change(copy[0]); copy[1] = change(copy[1]);
    solve(copy,1);

    if(flag == true){
        cout<<ans<<"\n";
    }else{
        cout<<"-1""\n";
    }
    return 0;
}