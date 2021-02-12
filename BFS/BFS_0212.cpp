#include <iostream>
#include <algorithm>
#include <queue>
using  namespace  std;

bool check[1001][1001];
int emo[1001][1001];
int n;

void bfs(int s,int c){
    queue<pair<int,int>> q;
    q.push(make_pair(s,c));
    emo[s][c] = 0;
    check[s][c] = true;
    while(!q.empty()){
        int qs = q.front().first;
        int qc = q.front().second;
        q.pop();
        if(check[qs][qs] == false){
            emo[qs][qs] = emo[qs][qc] + 1;
            q.push(make_pair(qs,qs));
            check[qs][qs] = true;
        }
        if(qs+qc <= n &&check[qs+qc][qc] == false){
            emo[qs+qc][qc] = emo[qs][qc] + 1;
            q.push(make_pair(qs+qc,qc));
            check[qs+qc][qc] = true;
        }
        if(qs-1 >=0 && check[qs-1][qc]== false){
            emo[qs-1][qc] = emo[qs][qc] + 1;
            q.push(make_pair(qs-1,qc));
            check[qs-1][qc] = true;
        }
    }

}

int main()
{
    cin>> n;
    bfs(1,0);


    int ans = 987654321;
    for(int i = 0; i<=n; i++){
        if(check[n][i] == true && ans > emo[n][i]){
            ans = emo[n][i];
        }
    }

    cout<<ans;

    return 0;
}