#include<iostream>
#include<algorithm>
using namespace std;
int N;
int p[16];
int t[16];
int answer = 0;

void sol(int day, int sum){
    if(day == N+1){
        answer = max(sum,answer);
        return;
    }
    if(day > N+1) return;
    sol(day+1,sum);
    sol(day+t[day],sum+p[day]);
}

int main(){
    cin>> N;
    for(int i = 1; i <= N; i++){
        cin>>t[i]>>p[i];
    }
    sol(1,0);
    cout<<answer<<"\n";
    return 0;
}
