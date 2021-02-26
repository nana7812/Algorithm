#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
//#include <set>
using  namespace  std;

string s;
int check(int i,char c){
    if((s[i*3] == c && s[i*3+1] == c && s[i*3+2] == c)
    || (s[i] == c && s[i+3] == c && s[i+6] == c)
    || (s[0] == c && s[4] == c && s[8] == c)
    || (s[2] == c && s[4] == c && s[6] == c))
        return 1;
        return 0;
}

int main() {

    while(true){
        cin>>s;
        int X = 0,O = 0,XWin = 0,OWin =0;
        bool flag = false;
        if(s == "end"){
            break;
        }
        for(int i = 0; i <3; i++){
            for(int j = 0; j <3; j++){
                if(s[i*3+j] == 'O') O++;
                if(s[i*3+j] == 'X') X++;
            }
        }
        if(X-O==1)  flag = true;
        else if(X == O) flag = true;
        else if()
    }
    return 0;
}