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

using namespace std;

int a[101][101];
int N, L;

bool sol(vector<int> &a){
    vector<bool> c(N,false);
    bool pass = true;
    for (int j = 0; j < N - 1; j++) {
        if (a[j] == a[j + 1]) {
            continue;
        } else {
            if (a[j] + 1 == a[j + 1]) {
                for (int k = 0; k < L; k++) {
                    if (a[j] != a[j - k]) {
                        pass = false;
                        break;
                    }
                    if(c[j-k] == true){
                        pass = false;
                        break;
                    }
                    c[j-k] = true;
                }
            } else if (a[j] - 1 == a[j + 1]) {
                for (int k = 0; k < L; k++) {
                    if (a[j + 1] != a[j + 1 + k]) {
                        pass = false;
                        break;
                    }
                    if(c[j+1+k] == true){
                        pass = false;
                        break;
                    }
                    c[j+1+k] = true;
                }
            } else {
                pass = false;
                break;
            }
        }
    }
    return pass;
}

int main() {
    cin>> N>> L;
    for(int i = 0; i <N; i++){
        for(int j = 0; j < N; j++){
            cin>>a[i][j];
        }
    }
    int answer = 0;
    for(int i = 0; i < N; i++){
        vector<int> v;
        for(int j = 0; j < N; j++){
            v.push_back(a[i][j]);
        }
        if(sol(v)== true)
            answer += 1;
    }
    for(int i = 0; i < N; i++){
        vector<int> v;
        for(int j = 0; j < N; j++){
            v.push_back(a[j][i]);
        }
        if(sol(v)== true)
            answer += 1;
    }
    cout<<answer;

}