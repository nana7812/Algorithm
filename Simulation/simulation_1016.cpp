#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int t[4][8];
bool check(int num1,int num2){
    return t[num1][2] != t[num2][6];
}

void circle(int num, int dir){
    if(dir == 1){
        int temp = t[num][0];
        t[num][0] = t[num][7];
        for(int i = 7; i >=2; i--){
            t[num][i] = t[num][i-1];
        }
        t[num][1] = temp;
    }else{
        int temp = t[num][0];
        for(int i = 0; i <= 6; i++){
            t[num][i] = t[num][i+1];
        }
        t[num][7] = temp;
    }
}


int main(){
    int T;
    cin>>T;
    while(T--){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 8; j++){
                char input;
                cin>> input;
                t[i][j] = input - '0';
            }
        }
        int K;
        cin>> K;
        while(K--){
            vector<bool> turn(4,false);
            vector<int> d(4);
            int num, dir;
            cin>>num>>dir;
            num--;
            bool even = false;
            if(num%2 == 0){
                even = true;
            }
            for(int i = 0; i < 4; i++){
                if(even){
                    if(i%2 == 0){
                        d[i] = dir;
                    }else{
                        d[i] = (-1*dir);
                    }
                }else{
                    if(i%2 != 0){
                        d[i] = dir;
                    }else{
                        d[i] = (-1*dir);
                    }
                }
            }
            turn[num] = true;
            if(num == 0){
                if(check(0,1)){
                    turn[1] = true;
                    if(check(1,2)){
                        turn[2] = true;
                        if(check(2,3)){
                            turn[3] = true;
                        }
                    }
                }
            }else if(num == 1){
                if(check(0,1)){
                    turn[0] = true;
                }
                if(check(1,2)){
                    turn[2] = true;
                    if(check(2,3)){
                        turn[3] = true;
                    }
                }
            }else if(num == 2){
                if(check(1,2)){
                    turn[1] = true;
                    if(check(0,1)){
                        turn[0] = true;
                    }
                }
                if(check(2,3)){
                    turn[3] = true;
                }
            }else{
                if(check(2,3)){
                    turn[2] = true;
                    if(check(1,2)){
                        turn[1] = true;
                        if(check(0,1)){
                            turn[0] = true;
                        }
                    }
                }
            }

            //회전
            for(int i = 0; i < 4; i++){
                if(turn[i] == true){
                    circle(i,d[i]);
                }
            }
        }
        int answer = 0;
        if(t[0][0] == 1) answer += 1;
        if(t[1][0] == 1) answer += 2;
        if(t[2][0] == 1) answer += 4;
        if(t[3][0] == 1) answer += 8;
        cout<<answer<<"\n";
    }
    return 0;
}