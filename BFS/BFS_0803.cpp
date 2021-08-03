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

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
bool check[1501][1501];

void BFS(int a, int b, int c){
    queue<pair<pair<int,int>,int>> q;
    q.push({{a,b},c});
    check[a][b] = true;
    while(!q.empty()){
        int qa = q.front().first.first;
        int qb = q.front().first.second;
        int qc = q.front().second;
        q.pop();
        if(qa == qb && qb == qc && qa == qc){
            cout<<1<<"\n";
            return;
        }
        check[qa][qb] = true;
        //a >b,c
        if(qa > qb){
            if(check[qa-qb][qb+qb] == false) {
                q.push({{qa - qb, qb + qb}, qc});
            }
        }
        if(qa > qc){
            if(check[qa-qc][qb] == false) {
                q.push({{qa - qc, qb}, qc + qc});
            }
        }
        //b >a,c
        if(qb >qa){
            if(check[qa+qa][qb-qa] == false) {
                q.push({{qa + qa, qb - qa}, qc});
            }
        }
        if(qb >qc){
            if(check[qa][qb-qc] == false) {
                q.push({{qa, qb - qc}, qc + qc});
            }
        }
        //c > a,b
        if(qc > qa){
            if(check[qa+qa][qb] == false) {
                q.push({{qa + qa, qb}, qc - qa});
            }
        }
        if(qc >qb){
            if(check[qa][qb+qb] == false) {
                q.push({{qa, qb + qb}, qc - qb});
            }
        }
    }
    cout<<0<<"\n";
    return;
}


int main() {
    int A,B,C;
    cin>> A>> B>>C;
    BFS(A,B,C);
    return 0;
}