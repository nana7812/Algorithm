#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
//#include <set>
using  namespace  std;

string s;
int check(int i,char m){
    if((s[i*3]==m&&s[i*3+1]==m&&s[i*3+2]==m)
    ||(s[i]==m&&s[i+3]==m&&s[i+6]==m)
    ||(s[0]==m&&s[4]==m&&s[8]==m)
    ||(s[2]==m&&s[4]==m&&s[6]==m))return 1;
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
            if(check(i,'X')){
                XWin =  1;
            }
            if(check(i,'O')){
                OWin = 1;
            }
            for(int j = 0; j <3; j++){
                if(s[i*3+j] == 'O') O++;
                if(s[i*3+j] == 'X') X++;
            }
        }
        
        //if문 순서주의!
        if(XWin && OWin) flag = false;
        else if(X-O==1 && XWin)  flag = true;
        else if(X == O && OWin ) flag = true;
        else if(X == 5 && O == 4 && !XWin && !OWin) flag = true;
       
        //cout<<X <<" "<<O<<" "<<XWin<<" "<<OWin<<"\n";
        if(flag == true){
            cout<<"valid"<<"\n";
        }else{
            cout<<"invalid"<<"\n";
        }
    }
    return 0;
}