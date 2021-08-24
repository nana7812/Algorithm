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

int r,c,k;
int a[100][100];

int main(){

    cin>>r>>c>>k;
    r -= 1, c -=1;
    int time = 0;
    bool flag = false;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin>> a[i][j];
            if(i == r && j ==c && a[i][j] == k)
                flag = true;
        }
    }
    int row = 3, col = 3;
    while(!flag){
        time++;
        if(time >100){
            cout<<"-1" <<"\n";
            return 0;
        }
        vector<pair<int,int>> v[100];
        if(row >= col){
            for(int i = 0; i < row; i++){
                map<int,int> m;
                for(int j = 0; j < col; j++) {
                    m[a[i][j]]++;
                }
                for(int j = 1; j <= 100; j++){
                    if(m[j]){
                        v[i].push_back({m[j],j});
                    }
                }
            }

            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    a[i][j] = 0;
                }
            }
            for(int i = 0; i < row; i++){
                sort(v[i].begin(),v[i].end());
            }

            for(int i = 0; i < row; i++){
                int temp = 0;
                for(int j = 0; j < v[i].size(); j++){
                    a[i][temp++] = v[i][j].second;
                    if(temp == 100) break;
                    a[i][temp++] = v[i][j].first;
                    if(temp == 100) break;
                }
                col = max(col,temp);
            }
        }else{
            for(int i = 0; i < col; i++) {
                map<int, int> m;
                for (int j = 0; j < row; j++) {
                    m[a[j][i]]++;
                }
                for (int j = 1; j <= 100; j++) {
                    if (m[j]) {
                        v[i].push_back({m[j], j});
                    }
                }
            }
            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    a[i][j] = 0;
                }
            }
            for(int i = 0; i < col; i++){
                sort(v[i].begin(),v[i].end());
            }
            for(int i = 0; i < col; i++){
                int temp = 0;
                for(int j = 0; j < v[i].size(); j++){
                    a[temp++][i] = v[i][j].second;
                    if(temp== 100) break;
                    a[temp++][i] = v[i][j].first;
                    if(temp == 100) break;
                }
                row = max(row,temp);
            }
        }
        if(a[r][c] == k){
            flag = true;
            break;
        }
    }
    cout<<time<<"\n";
    return 0;
}