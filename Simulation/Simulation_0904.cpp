#include <iostream>
#include <stdlib.h>
#include <map>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <cstring>
#include <stack>
#include <sstream>
#include <array>
using namespace std;

int a[10][10];
int temp[10][10];

void remove(int s, int e, char c){
    if(c == 'g'){
        for(int i = e; i >= s; i--){
            for(int j = 0; j < 4; j++){
                if(i == s){
                    a[i][j] = 0;
                }else{
                    a[i][j] = a[i-1][j];
                }
            }
        }

    }else if(c == 'b'){
        for(int i = e; i >= s; i--){
            for(int j = 0; j < 4; j++){
                if(i == s){
                    a[j][i] = 0;
                }else {
                    a[j][i] = a[j][i - 1];
                }
            }
        }
    }
}


int main(){
    int N;
    cin>> N;
    int score = 0;
    while(N--){
        int t,x,y;
        cin>> t>> x>> y;
        int gSpecial = -1; int bSpecial = -1;
        //도미노
        bool ginstall; bool binstall;
        if(t == 1){
            //green
            ginstall = false;
            for(int i = 5; i <10; i++){
                if(a[i][y] == 0){
                    continue;
                }else{
                    ginstall = true;
                    a[i-1][y] = t;
                    if(i-1 <= 5){
                        gSpecial = i-1;
                    }
                    break;
                }
            }
            if(!ginstall){
                a[9][y] = t;
            }
            //blue
            binstall = false;
            for(int i = 5; i < 10; i++){
                if(a[x][i] == 0){
                    continue;
                }else{
                    binstall = true;
                    a[x][i-1] = t;
                    if(i-1 <= 5){
                        bSpecial = i-1;
                    }
                    break;
                }
            }
            if(!binstall){
                a[x][9] = t;
            }
        }else if(t == 2){
            //green
            ginstall = false;
            for(int i = 4; i <10; i++){
                if(a[i][y] == 0 && a[i][y+1] == 0){
                    continue;
                }else{
                    ginstall = true;
                    a[i-1][y] = t;
                    a[i-1][y+1] = t;
                    if(i-1 <= 5){
                        gSpecial = i-1;
                    }
                    break;
                }
            }
            if(!ginstall){
                a[9][y] = t;
                a[9][y+1] = t;
            }
            //blue
            binstall = false;
            for(int i = 6; i < 10; i++){
                if(a[x][i] == 0 && a[x][i-1] == 0){
                    continue;
                }else{
                    binstall = true;
                    a[x][i-1] = t;
                    a[x][i-2] = t;
                    if(i-2 <= 5){
                        bSpecial = i-2;
                    }
                    break;
                }
            }
            if(!binstall){
                a[x][9] = t;
                a[x][8] = t;
            }
        }else if(t == 3){
            //green
            ginstall = false;
            for(int i = 6; i < 10; i++){
                if(a[i][y] == 0 && a[i-1][y] == 0){
                    continue;
                }else{
                    ginstall = true;
                    a[i-1][y] = t;
                    a[i-2][y] = t;
                    if(i -2 <= 5){
                        gSpecial = i-2;
                    }
                    break;
                }
            }
            if(!ginstall){
                a[9][y] = t;
                a[8][y] = t;
            }
            //blue
            binstall = false;
            for(int i = 5; i <10; i++){
                if(a[x][i] == 0 && a[x+1][i] == 0){
                    continue;
                }else{
                    binstall = true;
                    a[x][i-1] = t;
                    a[x+1][i-1] = t;
                    if(i-1 <= 5){
                        bSpecial = i-1;
                    }
                    break;
                }
            }
            if(!binstall){
                a[x][9] = t;
                a[x+1][9] = t;
            }
        }
        //점수 확인
        //green
        bool nog;
        for(int i = 9; i >= 6; i--){
            nog = false;
            for(int j = 0; j < 4; j++){
                if(a[i][j] == 0){
                    nog = true;
                    break;
                }
            }
            if(!nog){
               // cout<<i <<"그린 점수"<<"\n";
                score++;
                //여기 끝부분 시작부뿐 확인하기
                remove(4,i,'g');
                if(gSpecial  != -1){
                    gSpecial++;
                }
                i++;
            }
        }
        //blue
        bool nob;
        for(int i = 9; i >= 6; i--){
            nob = false;
            for(int j = 0; j < 4; j++){
                if(a[j][i] == 0){
                    nob = true;
                    break;
                }
            }
            if(!nob){
                //cout<<i <<"블루 점수"<<"\n";
                score++;
                //여기 끝부분 시작부뿐 확인하기
                remove(4,i,'b');
                if(bSpecial  != -1){
                    bSpecial++;
                }
                i++;
            }
        }
        
        //특수존
        while(4 <= gSpecial && gSpecial <= 5){
            //cout<<"그린특수존 발생"<<"\n";
            remove(gSpecial,9,'g');
            gSpecial++;
        }
        while(4 <= bSpecial && bSpecial <= 5){
            //cout<<"블루특수존 발생"<<"\n";
            remove(bSpecial,9,'b');
            bSpecial++;
        }


        //상태확인해보자
        //for(int i = 0; i < 10; i++){
        //    for(int j = 0; j < 10; j++){
        //        cout<<a[i][j]<<" ";
        //    }
        //    cout<<"\n";
        // }
    }

    //점수출력
    cout<<score<<"\n";
    //블록 개수
    int cnt = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 6; j < 10; j++){
            if(a[i][j] > 0) cnt++;
        }
    }

    for(int i = 6; i < 10; i++){
        for(int j = 0; j < 4; j++){
            if(a[i][j] > 0) cnt++;
        }
    }
    cout<<cnt<<"\n";
    return 0;
}