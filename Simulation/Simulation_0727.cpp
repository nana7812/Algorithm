#include <iostream>
#include <stdlib.h>
//#include <map>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <cstring>
#include <stack>
#include <sstream>

using namespace std;



int main() {
    int n = 4;
    vector<string> a(n);
    for(int i = 0; i <n; i++){
        cin>>a[i];
    }
    int K;
    cin>> K;
    while(K--){
        int no,dir;
        cin>> no>> dir;
        vector<int> d(n);
        no = no-1;
        d[no] = dir;
        for(int i = no-1; i>=0; i--){
            if(a[i][2] != a[i+1][6]){
                d[i] = -d[i+1];
            }else{
                break;
            }
        }
        for(int i = no +1; i <n; i++){
            if(a[i][6] != a[i-1][2]){
                d[i] = -d[i-1];
            }else{
                break;
            }
        }
        for(int i = 0; i < n; i++){
            if(d[i] == 0) continue;
            if(d[i] == 1){
                char temp = a[i][7];
                for(int j = 7; j >=1; j--){
                    a[i][j] = a[i][j-1];
                }
                a[i][0] = temp;
            }else if(d[i] == -1){
                char temp = a[i][0];
                for(int j = 0; j < 7; j++){
                    a[i][j] = a[i][j+1];
                }
                a[i][7] = temp;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i][0] == '1'){
            if(i == 0){
                ans += 1;
            }else if(i == 1){
                ans += 2;
            }else if(i == 2){
                ans += 4;
            }else if(i == 3){
                ans += 8;
            }
        }
    }

    cout<<ans;
    return 0;
}