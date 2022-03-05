#include <iostream>
using namespace std;

int N;
int t[16];
int p[16];

void dfs(int day, int sum, int &ans){
    if(day > N){
        if(ans < sum) ans = sum;
        return;
    }
    if(day + t[day] <= N+1){
        dfs(day + t[day],sum + p[day],ans);
    }
    dfs(day+1,sum,ans);
}

int main(){
    cin>> N;
    for(int i = 1; i <= N; i++){
        cin>>t[i]>>p[i];
    }
    int answer = 0;
    dfs(1,0,answer);
    cout<<answer<<"\n";\
    return 0;
}